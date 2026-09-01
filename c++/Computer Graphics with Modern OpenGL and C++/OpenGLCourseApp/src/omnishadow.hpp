#ifndef OMNISHADOW_H_DEFINED
#define OMNISHADOW_H_DEFINED

#include "shadow.hpp"

class OmniShadow : public Shadow
{
public:
    OmniShadow();
    ~OmniShadow();

    bool Init(GLuint, GLuint);
    void Write();
    void Read(GLenum);

private:
};

#endif // OMNISHADOW_H_DEFINED