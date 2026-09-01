#include "camera.hpp"

Camera::Camera()
{
}
Camera::Camera(glm::vec3 _pos, glm::vec3 _wUp, GLfloat _y, GLfloat _p, GLfloat _s, GLfloat _tspeed) // start values
{
    position = _pos;
    worldUp = _wUp;
    yaw = _y;
    pitch = _p;
    front = glm::vec3(0.0f, 0.0f, -1.0f);

    speed = _s;
    turnSpeed = _tspeed;

    Update();
}

Camera::~Camera()
{
}

void Camera::KeyControl(bool *keys, GLfloat dt)
{
    GLfloat vel = speed * dt;

    if (keys[GLFW_KEY_W])
    {
        position += front * vel;
    }
    if (keys[GLFW_KEY_S])
    {
        position -= front * vel;
    }
    if (keys[GLFW_KEY_A])
    {
        position -= right * vel;
    }
    if (keys[GLFW_KEY_D])
    {
        position += right * vel;
    }
}

void Camera::MouseControl(GLfloat dx, GLfloat dy)
{
    dx *= turnSpeed;
    dy *= turnSpeed;

    yaw += dx;
    pitch += dy;

    if (pitch > 89.0f)
    {
        pitch = 89.0f;
    }

    if (pitch < -89.0f)
    {
        pitch = -89.0f;
    }
    Update();
}

glm::mat4 Camera::CalculateViewMatrix()
{
    return glm::lookAt(position, position + front, up);
}
void Camera::Update()
{
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(front);

    right = glm::normalize(glm::cross(front, worldUp));
    up = glm::normalize(glm::cross(right, front));
}

glm::vec3 Camera::GetCameraPosition()
{
    return position;
}

glm::vec3 Camera::GetCameraDirection()
{
    return front;
}