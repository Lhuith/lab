#ifndef SHADER_H_INCLUDED
#define SHADER_H_INCLUDED

#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "meta.hpp"

#include "directionalLight.hpp"
#include "pointLight.hpp"
#include "spotLight.hpp"

class Shader
{
public:
    Shader();

    void CreateFromString(const char *, const char *);
    void CreateFromFiles(const char *, const char *);
    void CreateFromFiles(const char *, const char *, const char *);

    void Validate();

    std::string ReadFile(const char *);

    GLuint GetProjectionLocation();
    GLuint GetModelLocation();
    GLuint GetViewLocation();
    GLuint GetAmbientIntensityLocation();
    GLuint GetColorLocation();
    GLuint GetDiffuseIntensityLocation();
    GLuint GetLightDirectionLocation();
    GLuint GetSpecularIntensityLocation();
    GLuint GetSpecularShininessLocation();
    GLuint GetCameraPositionLocation();
    GLuint GetOmniLightPositionLocation();
    GLuint GetFarPlaneLocation();

    void SetDirectionalLight(DirectionalLight *);

    void SetPointLights(PointLight *, unsigned int, unsigned int, unsigned int);
    void SetSpotLights(SpotLight **, unsigned int, unsigned int, unsigned int);

    void SetTexture(GLuint);
    void SetDirectionalShadowMap(GLuint);
    void SetDirectionalLightTransform(glm::mat4 *);
    void SetLightMatrices(std::vector<glm::mat4>);

    void UseShader();
    void ClearShader();

    ~Shader();

private:
    GLuint shaderId, uniformProjection, uniformModel, uniformView, uniformCameraPosition,
        uniformSpecularIntensity, uniformSpecularShininess,
        uniformTexture,
        uniformDirectionalLightTransform, uniformDirectionalShadowMap,
        uniformOmniLightPosition, uniformFarPlane;

    GLuint uniformLightMatrices[6];

    struct
    {
        GLuint uniformColor;
        GLuint uniformAmbientIntensity;
        GLuint uniformDiffuseIntensity;

        GLuint uniformDirection;

    } uniformDirectionalLight;

    int pointLightCount;
    GLuint uniformPointLightCount;
    struct
    {
        GLuint uniformColor;
        GLuint uniformAmbientIntensity;
        GLuint uniformDiffuseIntensity;

        GLuint uniformPosition;
        GLuint uniformConstant;
        GLuint uniformLinear;
        GLuint uniformExponent;
    } uniformPointLight[MAX_POINT_LIGHTS];

    int spotLightCount;
    GLuint uniformSpotLightCount;
    struct
    {
        GLuint uniformColor;
        GLuint uniformAmbientIntensity;
        GLuint uniformDiffuseIntensity;

        GLuint uniformPosition;
        GLuint uniformConstant;
        GLuint uniformLinear;
        GLuint uniformExponent;

        GLuint uniformDirection;
        GLuint uniformEdge;
    } uniformSpotLight[MAX_SPOT_LIGHTS];

    struct
    {
        GLuint uniformShadowMap;
        GLuint uniformFarPlane;
    } uniformOmniShadowMap[MAX_POINT_LIGHTS + MAX_SPOT_LIGHTS];

    void CompileShader(const char *, const char *);
    void CompileShader(const char *, const char *, const char *);
    void AddShader(GLuint, const char *, GLenum);

    void CompileProgram();
};

#endif // SHADER_H_INCLUDED