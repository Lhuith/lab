#include "light.hpp"

Light::Light()
{
    color = glm::vec3(1.0f, 1.0f, 1.0f);
    ambientIntensity = 1.0f;
    diffuseIntensity = 0.0f;
}
Light::Light(GLfloat sW, GLfloat sH,
             GLfloat r, GLfloat g, GLfloat b, GLfloat a_i, GLfloat d_i)
{
    sMap = new Shadow();
    sMap->Init(sW, sH);

    color = glm::vec3(r, g, b);
    ambientIntensity = a_i;
    diffuseIntensity = d_i;
}

Light::~Light()
{
    // delete sMap;
}