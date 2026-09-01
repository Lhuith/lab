#ifndef POINTLIGHT_H_DEFINED
#define POINTLIGHT_H_DEFINED

#include <vector>

#include "light.hpp"
#include "omniShadow.hpp"

class PointLight : public Light
{
public:
    PointLight();
    PointLight(
        GLfloat, GLfloat,           // shadow width, shadow height
        GLfloat, GLfloat,           // near plane, far plane,
        GLfloat, GLfloat, GLfloat,  // rgb
        GLfloat, GLfloat,           // a_intent d_intent
        GLfloat, GLfloat, GLfloat,  // xyz
        GLfloat, GLfloat, GLfloat); // con, lin, exp
    ~PointLight();

    void UseLight(GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint);

    std::vector<glm::mat4> CalculateLightTransform();
    GLfloat GetFarPlane();
    glm::vec3 GetPosition();

protected:
    glm::vec3 position;
    GLfloat constant, linear, exponent;

    GLfloat farPlane;
};

#endif // POINTLIGHT_H_DEFINED