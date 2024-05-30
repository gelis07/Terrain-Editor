#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Camera.h"
#include <GLFW/glfw3.h>
#include "Shader.h"

struct Ray{
    glm::vec3 Origin;
    glm::vec3 Direction;
};
constexpr glm::vec3 NormPlaneVert[4] = {
    glm::vec3(-0.5f,  0.5f, 0.0f),  // Top left
    glm::vec3( 0.5f,  0.5f, 0.0f),  // Top right
    glm::vec3( 0.5f, -0.5f, 0.0f),  // Bottom right
    glm::vec3(-0.5f, -0.5f, 0.0f)   // Bottom left
};
class Brush
{
    public:
        Brush(glm::mat4* model);
        void Draw(const Camera& cam, GLuint texture, int width, int height);
        float BrushSize = 0.05f;
        float BrushWeight = 1.0f;
    private:
        glm::vec3 CalcPlaneRayInt(const Ray& ray,const Camera& cam); //Returns the ray intersection with a plane.
        glm::vec2 PlaneTexCoordsInt(const glm::vec3& Point); //Returns the texture coordinates based on the ray intersection.
        glm::vec3 ExtractScale(const glm::mat4& matrix);
        glm::mat4* PlaneModel;
        glm::mat4 LastModel;
        glm::vec3 PlaneVertices[4];
        inline static Shader program;
};  