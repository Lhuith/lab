#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// all the opengl/graphics stuff
#include "mesh.hpp"
#include "shader.hpp"
#include "window.hpp"
#include "camera.hpp"
#include "texture.hpp"
#include "material.hpp"
#include "model.hpp"
#include "skybox.hpp"

#include "meta.hpp"

// lights
#include "directionalLight.hpp"
#include "pointLight.hpp"
#include "spotLight.hpp"

#define STB_IMAGE_IMPLEMENTATION // lordy
#include "stb_image.h"

using namespace std;

const float toRadians = 3.14159265f / 180.0f;

unsigned int pointLightCount = 0;
unsigned int spotLightCount = 0;

GLuint uniformProjection = 0;
GLuint uniformModel = 0;
GLuint uniformView = 0;
GLuint uniformCameraPosition = 0;
GLuint uniformSpecularIntensity = 0;
GLuint uniformSpecularShininess = 0;
GLuint uniformOmniLightPosition = 0;
GLuint uniformFarPlane = 0;

Window *mainWindow;
std::vector<Mesh *> meshList;
std::vector<Shader *> shaderList;
Shader *directionalShadowShader;
Shader *omniShadowShader;

Camera *camera;

GLfloat deltaTime = 0.0f;
GLfloat lastTime = 0.0f;

GLfloat hamsterAngle = 0.0f;

Texture *brickTex;
Texture *dirtTex;
Texture plainTex;

DirectionalLight *mainLight;
PointLight pointLights[MAX_POINT_LIGHTS];
SpotLight *spotLights[MAX_SPOT_LIGHTS];

Material *shinyMaterial;
Material *dullMaterial;

std::vector<Model *> models;
Skybox skybox;

void CalcAverageNormals(
    unsigned int *ind, unsigned int indCount,
    GLfloat *v, unsigned int vCount,
    unsigned int vLength, unsigned int normalOffset)
{
    for (size_t i = 0; i < indCount; i += 3)
    {
        unsigned int in0 = ind[i] * vLength;
        unsigned int in1 = ind[i + 1] * vLength;
        unsigned int in2 = ind[i + 2] * vLength;

        glm::vec3 v1(v[in1] - v[in0], v[in1 + 1] - v[in0 + 1], v[in1 + 2] - v[in0 + 2]);
        glm::vec3 v2(v[in2] - v[in0], v[in2 + 1] - v[in0 + 1], v[in2 + 2] - v[in0 + 2]);
        glm::vec3 normal = glm::cross(v1, v2);
        normal = glm::normalize(normal);

        in0 += normalOffset;
        in1 += normalOffset;
        in2 += normalOffset;

        v[in0] += normal.x;
        v[in0 + 1] += normal.y;
        v[in0 + 2] += normal.z;

        v[in1] += normal.x;
        v[in1 + 1] += normal.y;
        v[in1 + 2] += normal.z;

        v[in2] += normal.x;
        v[in2 + 1] += normal.y;
        v[in2 + 2] += normal.z;
    }

    for (size_t i = 0; i < vCount / vLength; i++)
    {
        unsigned int nOffset = i * vLength + normalOffset;
        glm::vec3 vec(v[nOffset], v[nOffset + 1], v[nOffset + 2]);
        vec = glm::normalize(vec);
        v[nOffset] = vec.x;
        v[nOffset + 1] = vec.y;
        v[nOffset + 2] = vec.z;
    }
}

void CreateObjects()
{
    // clang-format off
    unsigned int indices[] = {
        0, 3, 1,
        1, 3, 2,
        2, 3, 0,
        0, 1, 2,
    };
    // clang-format on

    // clang-format off
    GLfloat vertices[] = {
        // x    y   z           u, v            nx     ny   nz
        -1.0f, -1.0f, -0.6f,     0.0f, 0.0f,     0.0f, 0.0f, 0.0f,
        0.0f, -1.0f, 1.0f,      0.5f, 0.0f,     0.0f, 0.0f, 0.0f,
        1.0f, -1.0f, -0.6f,      1.0f, 0.0f,     0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,       0.5f, 1.0f,     0.0f, 0.0f, 0.0f,
    };
    // clang-format on

    // clang-format off
    unsigned int floorIndices[] = {
        0, 2, 1,
        1, 2, 3,
    };
    // clang-format on

    // clang-format off
    GLfloat floorVertices[] = {
        -10.0f, 0.0f, -10.0f,   0.0f,  0.0f,     0.0f, -1.0f, 0.0f,
        +10.0f, 0.0f, -10.0f,   10.0f, 0.0f,     0.0f, -1.0f, 0.0f,
        -10.0f, 0.0f, +10.0f,   0.0f, 10.0f,     0.0f, -1.0f, 0.0f,
        +10.0f, 0.0f, +10.0f,   10.0f, 10.0f,    0.0f, -1.0f, 0.0f,
    };
    // clang-format on

    CalcAverageNormals(indices, 12, vertices, 32, 8, 5);

    Mesh *obj1 = new Mesh();
    obj1->CreateMesh(vertices, indices, 32, 12);
    meshList.push_back(obj1);

    Mesh *obj2 = new Mesh();
    obj2->CreateMesh(vertices, indices, 32, 12);
    meshList.push_back(obj2);

    Mesh *obj3 = new Mesh();
    obj3->CreateMesh(floorVertices, floorIndices, 32, 6);
    meshList.push_back(obj3);
}

void CreateShaders()
{
    Shader *shader1 = new Shader();
    shader1->CreateFromFiles("../shaders/shader.vert", "../shaders/shader.frag");
    shaderList.push_back(shader1);

    directionalShadowShader = new Shader();
    directionalShadowShader->CreateFromFiles(
        "../shaders/directional_shadow_map.vert",
        "../shaders/directional_shadow_map.frag");

    omniShadowShader = new Shader();
    omniShadowShader->CreateFromFiles(
        "../shaders/omni_shadow_map.vert",
        "../shaders/omni_shadow_map.geom",
        "../shaders/omni_shadow_map.frag");
}

void RenderScene()
{
    glm::mat4 model(1.0f);

    model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.5f));
    // model = glm::rotate(model, curAngle * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
    // model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));
    glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

    brickTex->UseTexture();
    shinyMaterial->UseMaterial(uniformSpecularIntensity, uniformSpecularShininess);
    meshList[0]->RenderMesh();

    model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f, 4.0f, -2.5f));
    // model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));
    glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

    dirtTex->UseTexture();
    dullMaterial->UseMaterial(uniformSpecularIntensity, uniformSpecularShininess);
    meshList[1]->RenderMesh();

    model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f, -2.0f, 0.0f));
    // model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));
    glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

    dirtTex->UseTexture();
    shinyMaterial->UseMaterial(uniformSpecularIntensity, uniformSpecularShininess);
    meshList[2]->RenderMesh();

    hamsterAngle += 0.01f;
    if (hamsterAngle > 360)
    {
        hamsterAngle = 0.1f;
    }

    model = glm::mat4(1.0f);
    model = glm::rotate(model, hamsterAngle * toRadians, glm::vec3(0.0f, 1.0f, 0.0f)); // bad
    model = glm::translate(model, glm::vec3(-8.0f, 1.0f, 0.0f));
    model = glm::rotate(model, 20.0f * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::rotate(model, -90 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));

    glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
    shinyMaterial->UseMaterial(uniformSpecularIntensity, uniformSpecularShininess);

    models[0]->RenderModel();

    // model = glm::mat4(1.0f);
    // model = glm::translate(model, glm::vec3(-3.0f, -2.0f, 0.0f));
    // // model = glm::rotate(model, -90 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
    // model = glm::scale(model, glm::vec3(1.5f, 1.5f, 1.5f));

    // glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

    // models[1]->RenderModel();
}

void DirectionalShadowMapPass(DirectionalLight *l)
{
    directionalShadowShader->UseShader();
    glViewport(0, 0, l->GetShadowMap()->GetShadowWidth(), l->GetShadowMap()->GetShadowHeight());

    l->GetShadowMap()->Write();
    glClear(GL_DEPTH_BUFFER_BIT);

    uniformModel = directionalShadowShader->GetModelLocation();

    glm::mat4 lightProj = mainLight->CalculateLightTransform();
    directionalShadowShader->SetDirectionalLightTransform(&lightProj);

    directionalShadowShader->Validate();
    RenderScene();

    glBindFramebuffer(GL_FRAMEBUFFER, 0); // default frame buffer
}

void OmniShadowMapPass(PointLight *l)
{
    glViewport(0, 0, l->GetShadowMap()->GetShadowWidth(), l->GetShadowMap()->GetShadowHeight());

    omniShadowShader->UseShader();
    uniformModel = omniShadowShader->GetModelLocation();
    uniformOmniLightPosition = omniShadowShader->GetOmniLightPositionLocation();
    uniformFarPlane = omniShadowShader->GetFarPlaneLocation();

    l->GetShadowMap()->Write();

    glClear(GL_DEPTH_BUFFER_BIT);

    glUniform3f(uniformOmniLightPosition, l->GetPosition().x, l->GetPosition().y, l->GetPosition().z);
    glUniform1f(uniformFarPlane, l->GetFarPlane());

    omniShadowShader->SetLightMatrices(l->CalculateLightTransform());

    omniShadowShader->Validate();
    RenderScene();

    glBindFramebuffer(GL_FRAMEBUFFER, 0); // default frame buffer
}

void RenderPass(glm::mat4 proj, glm::mat4 view)
{
    glViewport(0, 0, 1366, 768);

    // clear window
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    skybox.DrawSkybox(proj, view);

    shaderList[0]->UseShader();

    uniformModel = shaderList[0]->GetModelLocation();
    uniformProjection = shaderList[0]->GetProjectionLocation();
    uniformView = shaderList[0]->GetViewLocation();
    uniformCameraPosition = shaderList[0]->GetCameraPositionLocation();
    uniformSpecularIntensity = shaderList[0]->GetSpecularIntensityLocation();
    uniformSpecularShininess = shaderList[0]->GetSpecularShininessLocation();

    glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(proj));
    glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(view));
    glUniform3f(uniformCameraPosition,
                camera->GetCameraPosition().x,
                camera->GetCameraPosition().y,
                camera->GetCameraPosition().z);

    shaderList[0]->SetDirectionalLight(mainLight);
    shaderList[0]->SetPointLights(pointLights, pointLightCount, 3, 0);
    shaderList[0]->SetSpotLights(spotLights, spotLightCount, 3 + pointLightCount, pointLightCount);

    glm::mat4 lightProj = mainLight->CalculateLightTransform();
    shaderList[0]->SetDirectionalLightTransform(&lightProj);

    mainLight->GetShadowMap()->Read(GL_TEXTURE2);

    shaderList[0]->SetTexture(1);
    shaderList[0]->SetDirectionalShadowMap(2);

    glm::vec3 lowerLight = camera->GetCameraPosition();
    lowerLight.y -= 0.4f;
    spotLights[0]->SetFlash(lowerLight, camera->GetCameraDirection());

    shaderList[0]->Validate();
    RenderScene();
}

int main()
{
    mainWindow = new Window(1366, 768);
    int initCode = mainWindow->Init();
    if (initCode != 0)
    {
        printf("error initializing window");
        return initCode;
    }

    CreateObjects();
    CreateShaders();

    camera = new Camera(
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        -90.0f, 0.0f, 5.0f, 0.25f);

    brickTex = new Texture("../images/brick.png");
    brickTex->LoadTextureA();

    dirtTex = new Texture("../images/dirt.png");
    dirtTex->LoadTextureA();

    plainTex = Texture("../images/plain.png");
    plainTex.LoadTextureA();

    shinyMaterial = new Material(4.0f, 156);
    dullMaterial = new Material(0.3f, 4);

    mainLight = new DirectionalLight(2048, 2048,
                                     1.0f, 0.53f, 0.3f,
                                     0.1f, 0.9f,
                                     -10.0f, -12.0f, 18.5f);

    pointLights[1] = PointLight(1024, 1024,
                                0.1f, 100.0f,
                                0.0f, 0.0f, 1.0f,
                                0.1f, 0.4f,
                                2.0f, 2.0f, 0.0f,
                                0.3f, 0.2f, 0.1f);
    pointLightCount++;
    pointLights[0] = PointLight(1024, 1024,
                                0.1f, 100.0f,
                                0.0f, 1.0f, 0.0f,
                                0.0f, 0.4f,
                                -2.0f, 2.0f, 0.0f,
                                0.3f, 0.2f, 0.1f);
    pointLightCount++;
    spotLights[0] = new SpotLight(2048, 2048,
                                  0.01f, 200.0f,
                                  1.0f, 1.0f, 1.0f,
                                  0.0f, 2.0f,
                                  0.0f, 0.0f, 0.0f,
                                  0.0f, -1.0f, 0.0f,
                                  1.0f, 0.0f, 0.0f,
                                  20.0f);
    spotLightCount++;
    spotLights[1] = new SpotLight(1024, 1024,
                                  0.1f, 400.0f,
                                  1.0f, 1.0f, 1.0f,
                                  0.0f, 1.0f,
                                  -5.0f, 8.5f, 0.0f,
                                  1.0f, -0.7f, -0.5f,
                                  1.0f, 0.0f, 0.0f,
                                  20.0f);
    spotLightCount++;

    std::vector<std::string> skyboxFaces;
    skyboxFaces.push_back("../textures/cupertin-lake_rt.tga");
    skyboxFaces.push_back("../textures/cupertin-lake_lf.tga");
    skyboxFaces.push_back("../textures/cupertin-lake_up.tga");
    skyboxFaces.push_back("../textures/cupertin-lake_dn.tga");
    skyboxFaces.push_back("../textures/cupertin-lake_bk.tga");
    skyboxFaces.push_back("../textures/cupertin-lake_ft.tga");

    skybox = Skybox(skyboxFaces);

    Model *hamsterModel = new Model();
    hamsterModel->LoadModel("../models/HAM_01.fbx");
    models.push_back(hamsterModel);

    Model *treeModel = new Model();
    treeModel->LoadModel("../models/Tree.obj");
    models.push_back(treeModel);

    glm::mat4 projection = glm::perspective(
        glm::radians(60.0f), mainWindow->GetBufferWidth() / mainWindow->GetBufferHeight(), 0.01f, 100.0f);

    // loop until window closed
    while (!mainWindow->GetShouldClose())
    {
        GLfloat now = glfwGetTime();
        deltaTime = now - lastTime;
        lastTime = now;

        // get + handle user input events
        glfwPollEvents();

        camera->KeyControl(mainWindow->GetKeys(), deltaTime);
        camera->MouseControl(mainWindow->getXChange(), mainWindow->getYChange());

        if (mainWindow->GetKeys()[GLFW_KEY_E])
        {
            spotLights[0]->Toggle();
            mainWindow->GetKeys()[GLFW_KEY_E] = false;
        }

        DirectionalShadowMapPass(mainLight);

        for (size_t i = 0; i < pointLightCount; i++)
        {
            OmniShadowMapPass(&pointLights[i]);
        }
        for (size_t i = 0; i < spotLightCount; i++)
        {
            OmniShadowMapPass(spotLights[i]);
        }

        RenderPass(projection, camera->CalculateViewMatrix());

        glUseProgram(0);

        mainWindow->SwapBuffers();
    }

    for (auto p : meshList)
    {
        delete p;
    }
    meshList.clear();

    for (auto p : shaderList)
    {
        delete p;
    }
    shaderList.clear();

    delete mainWindow;
    delete camera;
    delete brickTex;
    delete dirtTex;
    delete mainLight;
    // delete[] pointLights;
    delete shinyMaterial;
    delete dullMaterial;
    delete directionalShadowShader;
    delete omniShadowShader;
    return 0;
}
