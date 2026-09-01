#include "pointLight.hpp"
#include <cstdio>

PointLight::PointLight() : Light()
{
    position = glm::vec3(0.0, 0.0, 0.0);
    constant = 1.0f;
    linear = 0.0f;
    exponent = 0.0f;
}

PointLight::PointLight(
    GLfloat sW, GLfloat sH,
    GLfloat nP, GLfloat fP,
    GLfloat r, GLfloat g, GLfloat b,
    GLfloat a_i, GLfloat d_i,
    GLfloat x, GLfloat y, GLfloat z,
    GLfloat c, GLfloat l, GLfloat e) : Light(sW, sH, r, g, b, a_i, d_i)
{

    position = glm::vec3(x, y, z);
    constant = c;
    linear = l;
    exponent = e;

    float aspect = (float)sW / (float)sH;
    farPlane = fP;

    lightProj = glm::perspective(glm::radians(90.0f), aspect, nP, fP);

    sMap = new OmniShadow();
    sMap->Init(sW, sH);
}

PointLight::~PointLight()
{
}

std::vector<glm::mat4> PointLight::CalculateLightTransform()
{
    std::vector<glm::mat4> lightMats;

    // positive x
    lightMats.push_back(
        lightProj * glm::lookAt(
                        position, position + glm::vec3(1.0, 0.0, 0.0), glm::vec3(0.0f, -1.0f, 0.0f)));

    // negative x
    lightMats.push_back(
        lightProj * glm::lookAt(
                        position, position + glm::vec3(-1.0, 0.0, 0.0), glm::vec3(0.0f, -1.0f, 0.0f)));

    // positive y
    lightMats.push_back(
        lightProj * glm::lookAt(
                        position, position + glm::vec3(0.0, 1.0, 0.0), glm::vec3(0.0f, 0.0f, 1.0f)));

    // negative y
    lightMats.push_back(
        lightProj * glm::lookAt(
                        position, position + glm::vec3(0.0, -1.0, 0.0), glm::vec3(0.0f, 0.0f, -1.0f)));

    // positive z
    lightMats.push_back(
        lightProj * glm::lookAt(
                        position, position + glm::vec3(0.0, 0.0, 1.0), glm::vec3(0.0f, -1.0f, 0.0f)));

    // negative z
    lightMats.push_back(
        lightProj * glm::lookAt(
                        position, position + glm::vec3(0.0, 0.0, -1.0), glm::vec3(0.0f, -1.0f, 0.0f)));

    return lightMats;
}

GLfloat PointLight::GetFarPlane()
{
    return farPlane;
}

glm::vec3 PointLight::GetPosition()
{
    return position;
}

void PointLight::UseLight(
    GLuint ambientIntensityLocation, GLuint ambientColorLocation, GLuint diffuseIntensityLocation,
    GLuint positionLocation,
    GLuint constantLocation, GLuint linearLocation, GLuint exponentLocation)
{
    glUniform3f(ambientColorLocation, color.x, color.y, color.z);
    glUniform1f(ambientIntensityLocation, ambientIntensity);
    glUniform1f(diffuseIntensityLocation, diffuseIntensity);
    glUniform3f(positionLocation, position.x, position.y, position.z);
    glUniform1f(constantLocation, constant);
    glUniform1f(linearLocation, linear);
    glUniform1f(exponentLocation, exponent);
}