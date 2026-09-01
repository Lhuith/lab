#ifndef SPOTLIGHT_H_DEFINED
#define SPOTLIGHT_H_DEFINED

#include "pointLight.hpp"

class SpotLight : public PointLight
{
public:
    SpotLight();
    ~SpotLight();

    SpotLight(
        GLfloat, GLfloat,          // shadow width, shadow height
        GLfloat, GLfloat,          // near plane, far plane
        GLfloat, GLfloat, GLfloat, // rgb
        GLfloat, GLfloat,          // a_intent d_intent
        GLfloat, GLfloat, GLfloat, // xyz
        GLfloat, GLfloat, GLfloat, // dx, dy, dz
        GLfloat, GLfloat, GLfloat, // con, lin, exp
        GLfloat);                  // edge

    void UseLight(
        GLuint, GLuint, GLuint,
        GLuint, // position
        GLuint, // direction
        GLuint, GLuint, GLuint,
        GLuint); // edge

    void SetFlash(glm::vec3 pos, glm::vec3 dir);
    void Toggle()
    {
        // isOn = !isOn;

        if (isOn)
        {
            isOn = false;
        }
        else
        {
            isOn = true;
        }
    }

private:
    glm::vec3 direction;
    GLfloat edge, procEdge;
    bool isOn;
};

#endif