#define GLEW_STATIC
#define STB_IMAGE_IMPLEMENTATION
#include <Imgui/imgui.h>
#include <Imgui/imgui_impl_glfw.h>
#include <Imgui/imgui_impl_opengl3.h>
#include <GL/glew.h>  // Initialize with gl3wInit()
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "stb_image.h"
#include "Shader.h"
#include "Brush.h"
#include "Debug.h"
#include <string>


float radius = 2.0f;
void scrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
    radius -= yoffset * 0.1f; // Adjust zoom based on scroll input
    radius = glm::clamp(radius, 1.0f, 50.0f); // Clamp zoom distance
}



struct Vertex {
    float position[3];
    float texCoords[2];
    float normal[3];
    float tangent[3];
    float bitangent[3];
};
void GenPlane(int triangles, GLuint VBO, GLuint EBO, std::vector<Vertex>* o_vert, int* IndCount){
    // Define the number of subdivisions in each direction
    int subdivisionsX = glm::sqrt(triangles); // Number of subdivisions along the x-axis
    int subdivisionsY = glm::sqrt(triangles); // Number of subdivisions along the y-axis

    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    for (int y = 0; y <= subdivisionsY; ++y) {
        for (int x = 0; x <= subdivisionsX; ++x) {
            float xPos = static_cast<float>(x) / subdivisionsX - 0.5f;
            float yPos = static_cast<float>(y) / subdivisionsY - 0.5f;

            vertices.push_back({{xPos, yPos, 0.0f}, {xPos + 0.5f, yPos + 0.5f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}});

            // Generate indices for quads
            if (x < subdivisionsX && y < subdivisionsY) {
                int currentIndex = x + y * (subdivisionsX + 1);
                int nextIndex = currentIndex + 1;
                int nextRowIndex = nextIndex + (subdivisionsX + 1);

                // Define first triangle of the quad
                indices.push_back(currentIndex);
                indices.push_back(nextIndex);
                indices.push_back(nextRowIndex);

                // Define second triangle of the quad
                indices.push_back(currentIndex);
                indices.push_back(nextRowIndex);
                indices.push_back(currentIndex + (subdivisionsX + 1));
            }
        }
    }
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), indices.data(), GL_STATIC_DRAW);

    *o_vert = vertices;
    *IndCount = indices.size();
}

GLuint LoadTexture(const std::string& path, int* o_width = nullptr, int* o_height = nullptr)
{
    GLuint texture;
    glCreateTextures(GL_TEXTURE_2D, 1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int width, height, nrChannels;
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
    if(o_width)
        *o_width = width;
    if(o_height)
        *o_height = height;
    GLenum format;
    if (nrChannels == 1)
        format = GL_RED;
    else if (nrChannels == 3)
        format = GL_RGB;
    else if (nrChannels == 4)
        format = GL_RGBA;

    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    stbi_image_free(data);
    return texture;
}


int main()
{
    // Initialize GLFW
    if (!glfwInit())
    {
        return 1;
    }

    // Create a window and OpenGL context using GLFW
    GLFWwindow* window = glfwCreateWindow(1280, 720, "New OpenGL Project", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    // Initialize OpenGL loader using gl3w
    if (glewInit() != 0)
    {
        glfwTerminate();
        return 1;
    }

    // Initialize ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Initialize the GLFW and OpenGL3 ImGui backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    //OpenGL Attributes
    glEnable(GL_DEPTH_TEST);
    



    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    
    std::vector<Vertex> vertices;
    int indCount;

    glBindVertexArray(VAO);

    GenPlane(10*10, VBO, EBO, &vertices, &indCount);


    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coordinates attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
    // normal attribute
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(5*sizeof(float)));
    glEnableVertexAttribArray(2);
    // tangent attribute
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(8*sizeof(float)));
    glEnableVertexAttribArray(3);
    // bitangent attribute
    glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(11*sizeof(float)));
    glEnableVertexAttribArray(4);

    Shader shader("shader.vs", "shader.fs");
    Shader comp("Dis.comp");

    GLuint texture = LoadTexture("WaterAlb.jpg");
    GLuint NormalMap = LoadTexture("WaterNorm.jpg");
    int Hwidth,Hheight;
    GLuint Test = LoadTexture("Mountains.jpg", &Hwidth, &Hheight);
    
    GLuint textureHdr;
    int TEXTURE_WIDTH, TEXTURE_HEIGHT;
    glfwGetWindowSize(window, &TEXTURE_WIDTH, &TEXTURE_HEIGHT);
    glGenTextures(1, &textureHdr);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureHdr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, TEXTURE_WIDTH, TEXTURE_HEIGHT, 0, GL_RGBA, GL_FLOAT, nullptr);
    glBindImageTexture(0, textureHdr, 0, GL_FALSE, 0, GL_READ_ONLY, GL_RGBA32F);

    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, texture);
    glActiveTexture(GL_TEXTURE3);
    glBindTexture(GL_TEXTURE_2D, Test);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, NormalMap);
    glActiveTexture(GL_TEXTURE4);
    glBindTexture(GL_TEXTURE_2D, textureHdr);


    glm::mat4 model(1.0f);
    Camera cam(45.0f, 0.3f, 100.0f);
    Brush brush(&model);
    //Runtime variables.
    glm::vec3 LightPos(1.0f, -1.0f, 1.0f);
    glm::vec3 Rotation(90.0f, 0.0f, 0.0f);
    glm::vec3 Scale(1.0f);
    float weight = -4.0f;
    bool Wireframe = false;
    glm::vec3 CameraPos(0.0f, 0.0f, -1.0f);
    glm::vec2 ScreenPoint(0.0f, 0.0f);
    float offset;
    int triangles= 10*10;
    glfwSetScrollCallback(window, scrollCallback);


    double LastTime = 0, DeltaTime;
    bool done = false;

    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, VBO);
    while (!done)
    {
        // Start a new ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        glClearColor(0.1f, 0.3f, 0.8f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);
        glActiveTexture(GL_TEXTURE3);
        glBindTexture(GL_TEXTURE_2D, Test);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, NormalMap);
        glActiveTexture(GL_TEXTURE4);
        glBindTexture(GL_TEXTURE_2D, textureHdr);

        DeltaTime = glfwGetTime() - LastTime;
        LastTime = glfwGetTime();

        int WindowWidth, WindowHeight;
        glfwGetWindowSize(glfwGetCurrentContext(), &WindowWidth, &WindowHeight);
        cam.UpdateProjection(WindowWidth, WindowHeight);


        comp.Bind();
        glUniform1i(glGetUniformLocation(comp.GetID(), "dis"), 4); //! The API just breaks the camera orbit I have no idea why.
        comp.SetUniform("weight", weight);
        comp.Dispatch(glm::vec3((unsigned int)ceil(vertices.size() / 32.0f), 1, 1), GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);
        comp.Unbind();

        // cam.Input(DeltaTime);
        shader.Bind();
        glBindVertexArray(VAO);
        model = glm::mat4(1.0f);
        glm::vec2 NearClipSize;
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
        model = glm::scale(model, Scale);
        model = glm::rotate(model, glm::radians(Rotation.x), glm::vec3(1,0,0));
        model = glm::rotate(model, glm::radians(Rotation.y), glm::vec3(0,1,0));
        model = glm::rotate(model, glm::radians(Rotation.z), glm::vec3(0,0,1));
        glm::mat4 mvp = cam.GetProjection() * cam.GetView() * model;
        shader.SetUniform("mvp", mvp);
        shader.SetUniform("model", model);
        shader.SetUniform("ViewPos", cam.GetPos());
        shader.SetUniform("LightPos", LightPos);
        shader.SetUniform("tex", 0);
        shader.SetUniform("normalMap", 1);
        if(Wireframe)
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        else
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        glDrawElements(GL_TRIANGLES, indCount, GL_UNSIGNED_INT, 0);
        shader.Unbind();


        
        cam.InputOrbit(DeltaTime, radius);
        brush.Draw(cam, textureHdr, TEXTURE_WIDTH, TEXTURE_HEIGHT);

        ImGui::Begin("Editor");
        ImGui::DragFloat3("LightPos", glm::value_ptr(LightPos));
        ImGui::DragFloat3("Rotation", glm::value_ptr(Rotation));
        ImGui::DragFloat3("Scale", glm::value_ptr(Scale));
        ImGui::DragFloat3("Camera Position", glm::value_ptr(CameraPos));
        ImGui::DragFloat2("Screen Point", glm::value_ptr(ScreenPoint));
        ImGui::DragFloat("weight", &weight, 0.01f);
        ImGui::DragFloat("Brush Size", &brush.BrushSize, 0.01f, 0.01f, 0.9f);
        ImGui::DragFloat("Brush Weight", &brush.BrushWeight, 0.01f);
        ImGui::DragFloat("offset", &offset, 0.01f);
        ImGui::DragFloat("Camera Distance Radius", &radius, 0.01f);
        ImGui::Checkbox("Wireframe", &Wireframe);
        ImGui::Text(("Delta time: " + std::to_string(DeltaTime) + " ("+std::to_string(1/DeltaTime)+ " FPS)").c_str());
        ImGui::DragInt("Triangles", &triangles, 1.0f, 0, INT_MAX);
        if(ImGui::Button("Generate Plane")){
            glBindVertexArray(VAO);
            GenPlane(triangles, VBO, EBO, &vertices, &indCount);
        }
        ImGui::End();

        // Render the ImGui frame
        ImGui::Render();
        glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());


        // Swap the front and back buffers and poll for events
        glfwSwapBuffers(window);
        glfwPollEvents();

        // Check if the window should close
        if (glfwWindowShouldClose(window))
        {
            done = true;
        }
    }

    // Shutdown the ImGui and GLFW backends
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();

    // Shutdown ImGui
    ImGui::DestroyContext();
    // Shutdown GLFW
    glfwTerminate();

    return 0;
}
