#ifndef MESH_H_INCLUDED
#define MESH_H_INCLUDED

#include <GL/glew.h>

class Mesh
{
public:
    Mesh();

    void CreateMesh(GLfloat *, unsigned int *, unsigned int, unsigned int);
    void RenderMesh();
    void ClearMesh();

    ~Mesh();

private:
    GLuint VAO, VBO, IBO;
    GLsizei indexCount;
};

#endif // MESH_H_INCLUDED