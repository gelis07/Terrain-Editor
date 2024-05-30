#pragma once
#define GLEW_STATIC
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h> 
class Shader{
    public:
        Shader(const std::string& vs, const std::string& fs);
        Shader(const std::string& cs);
        Shader(const std::string& vs, const std::string& gs, const std::string& fs);
        
        void Init(const std::string& vs, const std::string& fs);
        void Init(const std::string& cs);
        void Init(const std::string& vs, const std::string& gs, const std::string& fs);
        Shader() {} // Start unintialized.
        void Bind();
        void Unbind();
        void SetUniform(const std::string& name, int data);
        void SetUniform(const std::string& name, GLuint data);
        void SetUniform(const std::string& name, float data);
        void SetUniform(const std::string& name, const glm::vec3& data);
        void SetUniform(const std::string& name, const glm::vec2& data);
        void SetUniform(const std::string& name, const glm::mat4& mat);
        void SetUniform(const std::string& name, const glm::mat3& mat);
        void Dispatch(const glm::vec3& groups, int BarrierBit); //Only for compute shaders!
        const GLuint GetID() {return ID;}
        bool GetInitState() {return HasInit;}
    private:
        static std::string ReadFile(const std::string& filenPath);
        GLuint ID;
        bool HasInit = false;
        void CheckShader(GLuint shader,const std::string& name);

};

