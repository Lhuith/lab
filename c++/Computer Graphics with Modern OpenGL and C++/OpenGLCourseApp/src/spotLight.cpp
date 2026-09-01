#include "spotLight.hpp"
#include <cstdio>

SpotLight::SpotLight() : PointLight()
{
    direction = glm::vec3(0.0f, -1.0f, 0.0f);
    edge = 0.0f;
    procEdge = cosf(glm::radians(edge));
    isOn = true;
}

SpotLight::~SpotLight()
{
}

SpotLight::SpotLight(
    GLfloat sW, GLfloat sH,
    GLfloat nP, GLfloat fP,
    GLfloat r, GLfloat g, GLfloat b,
    GLfloat a_i, GLfloat d_i,
    GLfloat x, GLfloat y, GLfloat z,
    GLfloat dx, GLfloat dy, GLfloat dz,
    GLfloat c, GLfloat l, GLfloat e,
    GLfloat _edge) : PointLight(sW, sH, nP, fP, r, g, b, a_i, d_i, x, y, z, c, l, e)
{
    direction = glm::normalize(glm::vec3(dx, dy, dz));
    edge = _edge;
    procEdge = cosf(glm::radians(edge));
}

void SpotLight::UseLight(
    GLuint ambientIntensityLocation, GLuint ambientColorLocation, GLuint diffuseIntensityLocation,
    GLuint positionLocation, GLuint directionLocation,
    GLuint constantLocation, GLuint linearLocation, GLuint exponentLocation,
    GLuint edgeLocation) // edge
{

    glUniform3f(ambientColorLocation, color.x, color.y, color.z);

    if (isOn)
    {
        glUniform1f(ambientIntensityLocation, ambientIntensity);
        glUniform1f(diffuseIntensityLocation, diffuseIntensity);
    }
    else
    {
        glUniform1f(ambientIntensityLocation, 0.0f);
        glUniform1f(diffuseIntensityLocation, 0.0f);
    }

    glUniform3f(positionLocation, position.x, position.y, position.z);
    glUniform1f(constantLocation, constant);
    glUniform1f(linearLocation, linear);
    glUniform1f(exponentLocation, exponent);

    glUniform3f(directionLocation, direction.x, direction.y, direction.z);
    glUniform1f(edgeLocation, procEdge);
}

void SpotLight::SetFlash(glm::vec3 pos, glm::vec3 dir)
{
    position = pos;
    direction = dir;
}