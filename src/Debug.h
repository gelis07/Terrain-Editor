#pragma once
#define LOG_VEC(vec) std::cout << vec.x << " , " << vec.y << " , " << vec.z << '\n'

#include <iostream>
#include <typeinfo>
#include <cxxabi.h>
#include "Shader.h"

inline unsigned int sphereVAO = 0;
inline unsigned int indexCount;
inline unsigned int sh = 0;

#define DRAW_POINT(vec, cam) \
    do { \
        if (sphereVAO == 0) \
        { \
            Shader shader("Point.vs", "Point.fs"); \
            sh = shader.GetID(); \
            glGenVertexArrays(1, &sphereVAO); \
            unsigned int vbo, ebo; \
            glGenBuffers(1, &vbo); \
            glGenBuffers(1, &ebo); \
            std::vector<glm::vec3> positions; \
            std::vector<glm::vec2> uv; \
            std::vector<glm::vec3> normals; \
            std::vector<unsigned int> indices; \
            const unsigned int X_SEGMENTS = 64; \
            const unsigned int Y_SEGMENTS = 64; \
            const float PI = 3.14159265359f; \
            for (unsigned int x = 0; x <= X_SEGMENTS; ++x) \
            { \
                for (unsigned int y = 0; y <= Y_SEGMENTS; ++y) \
                { \
                    float xSegment = (float)x / (float)X_SEGMENTS; \
                    float ySegment = (float)y / (float)Y_SEGMENTS; \
                    float xPos = std::cos(xSegment * 2.0f * PI) * std::sin(ySegment * PI); \
                    float yPos = std::cos(ySegment * PI); \
                    float zPos = std::sin(xSegment * 2.0f * PI) * std::sin(ySegment * PI); \
                    positions.push_back(glm::vec3(xPos, yPos, zPos)); \
                    uv.push_back(glm::vec2(xSegment, ySegment)); \
                    normals.push_back(glm::vec3(xPos, yPos, zPos)); \
                } \
            } \
            bool oddRow = false; \
            for (unsigned int y = 0; y < Y_SEGMENTS; ++y) \
            { \
                if (!oddRow) \
                { \
                    for (unsigned int x = 0; x <= X_SEGMENTS; ++x) \
                    { \
                        indices.push_back(y * (X_SEGMENTS + 1) + x); \
                        indices.push_back((y + 1) * (X_SEGMENTS + 1) + x); \
                    } \
                } \
                else \
                { \
                    for (int x = X_SEGMENTS; x >= 0; --x) \
                    { \
                        indices.push_back((y + 1) * (X_SEGMENTS + 1) + x); \
                        indices.push_back(y * (X_SEGMENTS + 1) + x); \
                    } \
                } \
                oddRow = !oddRow; \
            } \
            indexCount = static_cast<unsigned int>(indices.size()); \
            std::vector<float> data; \
            for (unsigned int i = 0; i < positions.size(); ++i) \
            { \
                data.push_back(positions[i].x); \
                data.push_back(positions[i].y); \
                data.push_back(positions[i].z); \
                if (normals.size() > 0) \
                { \
                    data.push_back(normals[i].x); \
                    data.push_back(normals[i].y); \
                    data.push_back(normals[i].z); \
                } \
                if (uv.size() > 0) \
                { \
                    data.push_back(uv[i].x); \
                    data.push_back(uv[i].y); \
                } \
            } \
            glBindVertexArray(sphereVAO); \
            glBindBuffer(GL_ARRAY_BUFFER, vbo); \
            glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW); \
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo); \
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW); \
            unsigned int stride = (3 + 2 + 3) * sizeof(float); \
            glEnableVertexAttribArray(0); \
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0); \
            glEnableVertexAttribArray(1); \
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (void*)(3 * sizeof(float))); \
            glEnableVertexAttribArray(2); \
            glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, stride, (void*)(6 * sizeof(float))); \
        } \
        glUseProgram(sh); \
        glm::mat4 model(1.0f); \
        model = glm::translate(model, vec); \
        model = glm::scale(model, glm::vec3(BrushSize)); \
        glm::mat4 mvp = cam.GetProjection() * cam.GetView() * model; \
        glUniformMatrix4fv(glGetUniformLocation(sh, "mvp"), 1, GL_FALSE, glm::value_ptr(mvp));\
        glBindVertexArray(sphereVAO); \
        glDrawElements(GL_TRIANGLE_STRIP, indexCount, GL_UNSIGNED_INT, 0); \
        glUseProgram(0); \
    } while(0)



inline static const char* demangle(const char* mangled_name) {
    int status;
    char* demangled = abi::__cxa_demangle(mangled_name, nullptr, nullptr, &status);
    if (status == 0) {
        return demangled;
    } else {
        return mangled_name;
    }
}

#define HAS_INIT(init1)\
    if(!init1)\
    {\
        std::cout << "Class " << demangle(typeid(*this).name()) << " not initialized! File: " << __FILE__ << ", function: " << __func__ << "()" <<'\n';\
        return;\
    }

