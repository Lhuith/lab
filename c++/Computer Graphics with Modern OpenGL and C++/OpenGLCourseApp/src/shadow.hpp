#ifndef SHADOW_H_INCLUDED
#define SHADOW_H_INCLUDED

#include "stdio.h"
#include "GL/glew.h"

class Shadow
{
public:
    Shadow();
    ~Shadow();

    virtual bool Init(GLuint, GLuint);
    virtual void Write();
    virtual void Read(GLenum);

    GLuint GetShadowWidth() { return shadowWidth; }
    GLuint GetShadowHeight() { return shadowHeight; }

protected:
    GLuint FBO, shadowMap;
    GLuint shadowWidth, shadowHeight;
};

#endif // SHADOW_H_INCLUDED