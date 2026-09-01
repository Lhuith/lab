#ifndef MATERIAL_H_INCLUDED
#define MATERIAL_H_INCLUDED
#include "GL/glew.h"

class Material
{
public:
    Material();
    Material(GLfloat, GLfloat);

    void UseMaterial(GLuint, GLuint);

    ~Material();

private:
    GLfloat specularIntensity;
    GLfloat shininess;
};

#endif