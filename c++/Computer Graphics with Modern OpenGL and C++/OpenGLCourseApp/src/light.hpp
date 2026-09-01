#ifndef LIGHT_H_DEFINED
#define LIGHT_H_DEFINED

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "shadow.hpp"

class Light
{
public:
    Light();
    Light(GLfloat, GLfloat,
          GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);

    Shadow *GetShadowMap() { return sMap; }

    ~Light();

protected:
    glm::vec3 color;
    GLfloat ambientIntensity, diffuseIntensity;

    glm::mat4 lightProj;
    Shadow *sMap;
};

#endif // LIGHT_H_DEFINED