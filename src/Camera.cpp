#include "Camera.h"
#include "Debug.h"
Camera::Camera(float FOV, float NearPlane, float FarPlane) : nearPlane(NearPlane), farPlane(FarPlane), fov(FOV)
{
    int WindowWidth, WindowHeight;
    glfwGetWindowSize(glfwGetCurrentContext(), &WindowWidth, &WindowHeight);
    Projection = glm::perspective(glm::radians(fov), float(WindowWidth)/float(WindowHeight), nearPlane, farPlane);
}

void Camera::UpdateProjection(float width, float height)
{
    Projection = glm::perspective(glm::radians(fov), float(width)/float(height), nearPlane, farPlane);
}

glm::vec3 Camera::ScreenPointToWorld(const glm::vec2 &point) const
{
    glm::vec2 NearClipSize;
    NearClipSize.y = glm::tan(glm::radians(fov) / 2.0f) * nearPlane * 2.0f;
    NearClipSize.x = NearClipSize.y / ScreenHeight() * ScreenWidth();

    //Normalized point position in screen coordinates.
    glm::vec2 NormPointPos(point.x / ScreenWidth(), 1.0f - point.y / ScreenHeight());
    glm::vec3 Point3D(GetRight() * (NormPointPos.x * NearClipSize.x - NearClipSize.x / 2.0f) + 
                    GetUp() * (NormPointPos.y * NearClipSize.y - NearClipSize.y / 2.0f) +
                    GetFront() * nearPlane);

    return Point3D;
}

float Camera::ScreenWidth() const
{
    int WindowWidth, WindowHeight;
    glfwGetWindowSize(glfwGetCurrentContext(), &WindowWidth, &WindowHeight);
    return float(WindowWidth);
}

float Camera::ScreenHeight() const
{
    int WindowWidth, WindowHeight;
    glfwGetWindowSize(glfwGetCurrentContext(), &WindowWidth, &WindowHeight);
    return float(WindowHeight);
}

void Camera::Input(const float DeltaTime)
{
    double xpos, ypos;
    glfwGetCursorPos(glfwGetCurrentContext(), &xpos, &ypos);
    if(glfwGetMouseButton(glfwGetCurrentContext(), GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS){
        float xoffset = xpos - lastX;
        float yoffset = ypos - lastY;

        const float sensitivity = 0.1f;
        xoffset *= sensitivity;
        yoffset *= sensitivity;
        yaw += xoffset;
        pitch += yoffset;
        if(pitch > 89.0f)
            pitch = 89.0f;
        if(pitch < -89.0f)
            pitch = -89.0f;
        Direction.x = glm::cos(glm::radians(yaw)) * glm::cos(glm::radians(pitch));
        Direction.y = glm::sin(glm::radians(pitch));
        Direction.z = glm::sin(glm::radians(yaw)) * glm::cos(glm::radians(pitch));
        Front = glm::normalize(Direction);
        glfwSetInputMode(glfwGetCurrentContext(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

        if(glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_W)){
            Pos += Front * 10.0f * DeltaTime;
        }else if(glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_S))
            Pos -= Front * 10.0f * DeltaTime;
    }else {
        glfwSetInputMode(glfwGetCurrentContext(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }
    lastX = xpos;
    lastY = ypos;
    view = glm::lookAt(Pos, Pos + Front, glm::vec3(0.0f, 1.0f, 0.0f));
}

void Camera::InputOrbit(const float DeltaTime, float radius)
{
    double xpos, ypos;
    glfwGetCursorPos(glfwGetCurrentContext(), &xpos, &ypos);
    if(glfwGetMouseButton(glfwGetCurrentContext(), GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS || radius != LastRadius){
        float xoffset = xpos - lastX;
        float yoffset = ypos - lastY;


        const float sensitivity = 0.1f;
        xoffset *= sensitivity;
        yoffset *= sensitivity;
        yaw += xoffset;
        pitch += yoffset;
        pitch = glm::clamp(pitch, -89.0f, 89.0f);

        // Calculate orbit camera position
        float x = radius * glm::cos(glm::radians(pitch)) * glm::cos(glm::radians(yaw));
        float y = radius * glm::sin(glm::radians(pitch));
        float z = radius * glm::cos(glm::radians(pitch)) * glm::sin(glm::radians(yaw));
        Pos = glm::vec3(x, y, z);
        Front = -glm::normalize(Pos); // Calculate new front direction

        glfwSetInputMode(glfwGetCurrentContext(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    }else {
        glfwSetInputMode(glfwGetCurrentContext(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }
    lastX = xpos;
    lastY = ypos;
    LastRadius = radius;
    view = glm::lookAt(Pos, glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Look at the origin
}

void Camera::SetView(const glm::vec3 &pos)
{
    view = glm::lookAt(pos, glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Look at the origin
    Front = -glm::normalize(pos); // Calculate new front direction
    Pos = pos;
}
