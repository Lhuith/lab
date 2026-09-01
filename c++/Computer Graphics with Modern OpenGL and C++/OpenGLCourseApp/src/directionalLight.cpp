#include "directionalLight.hpp"

DirectionalLight::DirectionalLight() : Light()
{
    direction = glm::vec3(0.0f, -1.0f, 0.0f);
    lightProj = glm::ortho(-20.0f, 20.0f, -20.0f, 20.0f, 0.1f, 100.0f);
}
DirectionalLight::DirectionalLight(
    GLfloat sW, GLfloat sH,
    GLfloat r, GLfloat g, GLfloat b,
    GLfloat a_i, GLfloat d_i,
    GLfloat x, GLfloat y, GLfloat z) : Light(sW, sH, r, g, b, a_i, d_i)
{
    direction = glm::vec3(x, y, z);
    lightProj = glm::ortho(-20.0f, 20.0f, -20.0f, 20.0f, 0.1f, 100.0f);
}

DirectionalLight::~DirectionalLight()
{
}

glm::mat4 DirectionalLight::CalculateLightTransform()
{
    return lightProj * glm::lookAt(-direction, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
}

void DirectionalLight::UseLight(
    GLuint ambientIntensityLocation, GLuint ambientColorLocation,
    GLuint diffuseIntensityLocation, GLuint directionLocation)
{
    glUniform3f(ambientColorLocation, color.x, color.y, color.z);
    glUniform1f(ambientIntensityLocation, ambientIntensity);

    glUniform3f(directionLocation, direction.x, direction.y, direction.z);
    glUniform1f(diffuseIntensityLocation, diffuseIntensity);
}