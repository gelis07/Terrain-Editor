#pragma once
#define GLEW_STATIC
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtx/norm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h> 
#include <GLFW/glfw3.h>
#include <Imgui/imgui.h>
#include <Imgui/imgui_impl_glfw.h>
#include <Imgui/imgui_impl_opengl3.h>

class Camera {
    public:
        Camera(float FOV, float NearPlane, float FarPlane);
        void Input(const float DeltaTime);
        void InputOrbit(const float DeltaTime, float radius);
        void SetView(const glm::vec3& pos);

        void UpdateProjection(float width, float height);
        glm::vec3 ScreenPointToWorld(const glm::vec2& point) const;

        //Getters
        float ScreenWidth() const;
        float ScreenHeight() const;
        const float& GetNearClipPlane() {return nearPlane;}
        glm::vec3 GetRight() const {return glm::normalize(glm::cross(GetFront(), glm::vec3(0, 1, 0)));}
        glm::vec3 GetUp() const {return glm::normalize(glm::cross(GetRight(), GetFront()));}
        const glm::vec3& GetFront() const {return Front;}
        const glm::vec3& GetPos() const {return Pos;}
        glm::vec3& GetPos() {return Pos;}
        const float& GetFOV() {return fov;}
        const glm::mat4& GetView() const {return view;}
        const glm::mat4& GetProjection() const {return Projection;}
    private:
        glm::vec3 Direction = glm::vec3(0.0f, 0.0f, 1.0f);
        glm::vec3 Front = glm::vec3(0.0f, 0.0f, 1.0f);
        glm::vec3 Pos = glm::vec3(0.0f);
        glm::mat4 Projection;
        glm::mat4 view = glm::mat4(1.0f);

        float lastX, lastY;
        float LastRadius;
        float yaw, pitch = -90.0f;
        float nearPlane;
        float farPlane;
        float fov;
};