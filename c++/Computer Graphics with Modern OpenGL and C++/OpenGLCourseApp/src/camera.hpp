#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDEd

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <GLFW/glfw3.h>

class Camera
{
public:
    Camera();
    Camera(glm::vec3, glm::vec3, GLfloat, GLfloat, GLfloat, GLfloat);
    void KeyControl(bool *, GLfloat);
    void MouseControl(GLfloat, GLfloat);

    glm::vec3 GetCameraPosition();
    glm::vec3 GetCameraDirection();
    glm::mat4 CalculateViewMatrix();
    ~Camera();

private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;

    GLfloat yaw;
    GLfloat pitch;

    GLfloat speed;
    GLfloat turnSpeed;

    void Update();
};

#endif // CAMERA_H_INCLUDEd