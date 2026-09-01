#ifndef DIRECTIONALLIGHT_H_DEFINED
#define DIRECTIONALLIGHT_H_DEFINED

#include "light.hpp"

class DirectionalLight : public Light
{
public:
    DirectionalLight();
    DirectionalLight(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);

    void UseLight(GLuint, GLuint, GLuint, GLuint);

    glm::mat4 CalculateLightTransform();

    ~DirectionalLight();

private:
    glm::vec3 direction;
};

#endif // DIRECTIONALLIGHT_H_DEFINED