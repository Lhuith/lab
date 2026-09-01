#ifndef SKYBOX_H_DEFINED
#define SKYBOX_H_DEFINED

#include <vector>
#include <string>

#include "GL/glew.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "meta.hpp"

#include "mesh.hpp"
#include "shader.hpp"

class Skybox
{
public:
    Skybox();
    Skybox(std::vector<std::string>);

    void DrawSkybox(glm::mat4, glm::mat4);

    ~Skybox();

private:
    Mesh *skyMesh;
    Shader *skyShader;

    GLuint textureId;
    GLuint uniformProjection, uniformView;
};

#endif // SKYBOX_H_DEFINED