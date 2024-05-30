#include "Brush.h"
#include "Debug.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stbi_write.h"

Brush::Brush(glm::mat4 *model)  : PlaneModel(model)
{
    if(!program.GetInitState()){
        program.Init("paint.comp");
    }
}
static void saveTextureToPNG(const char* filename,int texture,int width, int height) {
    // Allocate memory for the texture data
    unsigned char* data = new unsigned char[width * height * 4]; // Assuming RGBA format

    // Read texture data from GPU into CPU memory
    glBindTexture(GL_TEXTURE_2D, texture);
    glGetTexImage(GL_TEXTURE_2D, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

    // Write data to PNG file
    if (!stbi_write_png(filename, width, height, 3, data, width * 3)) {
        std::cerr << "Error: Failed to write PNG file!" << std::endl;
    }

    // Free memory
    delete[] data;
}
void Brush::Draw(const Camera &cam, GLuint texture, int width, int height)
{
    Ray ray;
    double x, y;
    glfwGetCursorPos(glfwGetCurrentContext(), &x, &y);
    glm::vec3 Mouse3D = cam.ScreenPointToWorld(glm::vec2(float(x), float(y)));
    ray.Origin = cam.GetPos();
    ray.Direction = glm::normalize(Mouse3D);
    glm::vec3 Point = CalcPlaneRayInt(ray, cam);
    glm::vec2 TexCoords = PlaneTexCoordsInt(Point);
    //Using the texture coordinates determent whether the point is inside the plane.
    if(TexCoords.x > 0.0f && TexCoords.x < 1.0f && TexCoords.y > 0.0f && TexCoords.y < 1.0f)
        DRAW_POINT(Point, cam);

    if(glfwGetMouseButton(glfwGetCurrentContext(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
        glm::vec3 scale = ExtractScale(*PlaneModel);
        program.Bind();
        glBindImageTexture(0, texture, 0, GL_FALSE, 0, GL_READ_ONLY, GL_RGBA32F);
        program.SetUniform("TexCoords", TexCoords);
        program.SetUniform("radius", BrushSize / scale.x);
        float weight = BrushWeight;
        if(glfwGetKey(glfwGetCurrentContext(),GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
            weight = -BrushWeight;

        program.SetUniform("weight", weight);
        program.Dispatch(glm::vec3((unsigned int)ceil(width / 32.0f), (unsigned int)ceil(height / 32.0f), 1.0f),GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);
        program.Unbind();
    }
    if(glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_SPACE)){
        glBindTexture(GL_TEXTURE_2D, texture);
        glBindImageTexture(0, texture, 0, GL_FALSE, 0, GL_READ_ONLY, GL_RGBA32F);
        saveTextureToPNG("hi.png", texture, width, height);
    }
}

glm::vec3 Brush::CalcPlaneRayInt(const Ray &ray, const Camera& cam)
{
    //Keeping track so it doesn't update the vertices every frame.
    if(*PlaneModel != LastModel)
    {
        for (size_t i = 0; i < 4; i++)
        {
            PlaneVertices[i] = glm::vec3((*PlaneModel) * glm::vec4(NormPlaneVert[i], 1.0));
            LOG_VEC(PlaneVertices[i]);
        }
        LastModel = *PlaneModel;
    }
    const glm::vec3 A = PlaneVertices[0];
    const glm::vec3 B = PlaneVertices[1];
    const glm::vec3 C = PlaneVertices[2];

    //Calculating plane equation.
    float a = (B.y - A.y) * (C.z - A.z) - (B.z - A.z) * (C.y - A.y);
    float b = (B.z - A.z) * (C.x - A.x) - (B.x - A.x) * (C.z - A.z);
    float c = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
    float d = -a * A.x - b * A.y - c * A.z;

    glm::vec3 Normal(a,b,c);
    float dst = -(glm::dot(ray.Origin, Normal) + d) / glm::dot(ray.Direction, Normal);

    return ray.Origin + dst * ray.Direction;
}

glm::vec2 Brush::PlaneTexCoordsInt(const glm::vec3 &Point)
{
    //1 *look at the bottom of the file for explanation*
    glm::vec3 PlaneSize = ExtractScale(*PlaneModel);
    const glm::vec3& BL = PlaneVertices[3]; //Bottom Left corner ((0,0) for OpenGL texture coordinates).
    const glm::vec3& BR = PlaneVertices[2]; // Bottom Right corner of the plane.
    const glm::vec3& TL = PlaneVertices[0]; // Top left corner of the plane.
    float a = glm::length2(BR - Point); //We only need the squared values so no need to perform the square root.
    float b = glm::length2(BL - Point);
    float c = glm::length2(TL - Point);
    float x = -(a - b - PlaneSize.x * PlaneSize.x) / (2.0f * PlaneSize.x);
    float y = -(c - b - PlaneSize.y * PlaneSize.y) / (2.0f * PlaneSize.y);
    x /= PlaneSize.x;
    y /= PlaneSize.y;
    return glm::vec2(x, y); 
}
//https://math.stackexchange.com/questions/237369/given-this-transformation-matrix-how-do-i-decompose-it-into-translation-rotati
glm::vec3 Brush::ExtractScale(const glm::mat4& matrix)
{
    // Extract the column vectors
    glm::vec3 xAxis = glm::vec3(matrix[0][0], matrix[0][1], matrix[0][2]);
    glm::vec3 yAxis = glm::vec3(matrix[1][0], matrix[1][1], matrix[1][2]);
    glm::vec3 zAxis = glm::vec3(matrix[2][0], matrix[2][1], matrix[2][2]);

    // Calculate the length of each column vector (scaling factor along each axis)
    float scaleX = glm::length(xAxis);
    float scaleY = glm::length(yAxis);
    float scaleZ = glm::length(zAxis);

    return glm::vec3(scaleX, scaleY, scaleZ);
}



//1*
/*
    Our goal here is to project the possibly transformed plane and project it 
    into our normalized coordinates from 0 to 1 and get the texture coordinates.
    We know that the distance between a corner of the plane A will be the same distance 
    from the point on the plane, transformated or not so we can form the equation

    Let P(x,y) be the point in the normalized plane.
    Lets take the two bottom corners so we can form a system of equations (as used in the implementation)
    A(0, 0), B(1, 0)

    a² = (1 - x)² + y²
    b² = x² + y²
    
    where a, b the distance from the corners A, B from the point respectively.
    And now we have a system that we can solve, you can solve it yourself but the solutions are:

         a² - b² - 1
    x = ------------- , y = ±sqrt(b² - x²)
            -2

    There is a problem with the y axis. The x axis can stay as is but we get 2 possible values for y.
    Now this is a problem because we can't know whether y is positive or negative (technically y is always positive, 0 < y < 1,
    if its inside the plane but I want to use this function as a way to test whether the
    point in the argument is inside the plane or not, so that means that the y value can be negative).
    So similary with x we will do the same. 
    Now we'll get the distance from the top left and bottom left.

    c² = x² + (1 - y)²
    b² = x² + y²

    where c is the distance from the top left corner C(0, 1)

    so we get
         c² - b² - 1
    y = -------------
            -2

    and now we will know whether y is negative or positive.
*/