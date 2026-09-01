#include "shader.hpp"

Shader::Shader()
{
    shaderId = 0;
    uniformModel = 0;
    uniformProjection = 0;

    pointLightCount = 0;
    spotLightCount = 0;
}
Shader::~Shader()
{
    ClearShader();
}

// PUBLIC
void Shader::CreateFromString(const char *_v, const char *_f)
{
    CompileShader(_v, _f);
}
void Shader::CreateFromFiles(const char *vLoc, const char *fLoc)
{
    std::string vString = ReadFile(vLoc);
    std::string fString = ReadFile(fLoc);
    const char *vertexCode = vString.c_str();
    const char *fragmentCode = fString.c_str();

    CompileShader(vertexCode, fragmentCode);
}

void Shader::CreateFromFiles(const char *vLoc, const char *gLoc, const char *fLoc)
{
    std::string vString = ReadFile(vLoc);
    std::string gString = ReadFile(gLoc);
    std::string fString = ReadFile(fLoc);
    const char *vertexCode = vString.c_str();
    const char *geomCode = gString.c_str();
    const char *fragmentCode = fString.c_str();

    CompileShader(vertexCode, geomCode, fragmentCode);
}

std::string Shader::ReadFile(const char *location)
{
    std::string content;
    std::ifstream fileStream(location, std::ios::in);

    if (!fileStream.is_open())
    {
        printf("failed to read: %s, file doesn't exist \n", location);
        return "";
    }

    std::string line = "";
    while (!fileStream.eof())
    {
        std::getline(fileStream, line);
        content += line + "\n";
    }

    fileStream.close();
    return content;
}

GLuint Shader::GetProjectionLocation()
{
    return uniformProjection;
}
GLuint Shader::GetModelLocation()
{
    return uniformModel;
}

GLuint Shader::GetViewLocation()
{
    return uniformView;
}

GLuint Shader::GetColorLocation()
{
    return uniformDirectionalLight.uniformColor;
}
GLuint Shader::GetAmbientIntensityLocation()
{
    return uniformDirectionalLight.uniformAmbientIntensity;
}

GLuint Shader::GetDiffuseIntensityLocation()
{
    return uniformDirectionalLight.uniformDiffuseIntensity;
}
GLuint Shader::GetLightDirectionLocation()
{
    return uniformDirectionalLight.uniformDirection;
}

GLuint Shader::GetSpecularIntensityLocation()
{
    return uniformSpecularIntensity;
}
GLuint Shader::GetSpecularShininessLocation()
{
    return uniformSpecularShininess;
}

GLuint Shader::GetCameraPositionLocation()
{
    return uniformCameraPosition;
}

GLuint Shader::GetOmniLightPositionLocation()
{
    return uniformOmniLightPosition;
}

GLuint Shader::GetFarPlaneLocation()
{
    return uniformFarPlane;
}

void Shader::SetDirectionalLight(DirectionalLight *l)
{
    l->UseLight(
        uniformDirectionalLight.uniformAmbientIntensity,
        uniformDirectionalLight.uniformColor,
        uniformDirectionalLight.uniformDiffuseIntensity,
        uniformDirectionalLight.uniformDirection);
}

void Shader::SetPointLights(
    PointLight *lights, unsigned int lCount, unsigned int sTexUnit, unsigned int offset)
{
    if (lCount > MAX_POINT_LIGHTS)
    {
        lCount = MAX_POINT_LIGHTS;
        printf("current point light max is %d, lightCount set to max.", MAX_POINT_LIGHTS);
    }

    glUniform1i(uniformPointLightCount, lCount);

    for (size_t i = 0; i < lCount; i++)
    {
        lights[i].UseLight(
            uniformPointLight[i].uniformAmbientIntensity,
            uniformPointLight[i].uniformColor,
            uniformPointLight[i].uniformDiffuseIntensity,
            uniformPointLight[i].uniformPosition,
            uniformPointLight[i].uniformConstant,
            uniformPointLight[i].uniformLinear,
            uniformPointLight[i].uniformExponent);

        lights[i].GetShadowMap()->Read(GL_TEXTURE0 + sTexUnit + i);
        glUniform1i(uniformOmniShadowMap[i + offset].uniformShadowMap, sTexUnit + i);
        glUniform1f(uniformOmniShadowMap[i + offset].uniformFarPlane, lights[i].GetFarPlane());
    }
}

void Shader::SetSpotLights(SpotLight **lights, unsigned int lCount, unsigned int sTexUnit, unsigned int offset)
{
    if (lCount > MAX_SPOT_LIGHTS)
    {
        lCount = MAX_SPOT_LIGHTS;
        printf("current spot light max is %d, lightCount set to max.", MAX_SPOT_LIGHTS);
    }

    glUniform1i(uniformSpotLightCount, lCount);
    for (size_t i = 0; i < lCount; i++)
    {
        lights[i]->UseLight(
            uniformSpotLight[i].uniformAmbientIntensity,
            uniformSpotLight[i].uniformColor,
            uniformSpotLight[i].uniformDiffuseIntensity,
            uniformSpotLight[i].uniformPosition,
            uniformSpotLight[i].uniformDirection,
            uniformSpotLight[i].uniformConstant,
            uniformSpotLight[i].uniformLinear,
            uniformSpotLight[i].uniformExponent,
            uniformSpotLight[i].uniformEdge);

        lights[i]->GetShadowMap()->Read(GL_TEXTURE0 + sTexUnit + i);
        glUniform1i(uniformOmniShadowMap[i + offset].uniformShadowMap, sTexUnit + i);
        glUniform1f(uniformOmniShadowMap[i + offset].uniformFarPlane, lights[i]->GetFarPlane());
    }
}

void Shader::SetTexture(GLuint texUnit)
{
    glUniform1i(uniformTexture, texUnit);
}
void Shader::SetDirectionalShadowMap(GLuint texUnit)
{
    glUniform1i(uniformDirectionalShadowMap, texUnit);
}
void Shader::SetDirectionalLightTransform(glm::mat4 *t)
{
    glUniformMatrix4fv(uniformDirectionalLightTransform, 1, GL_FALSE, glm::value_ptr(*t));
}

void Shader::SetLightMatrices(std::vector<glm::mat4> lMats)
{
    for (size_t i = 0; i < 6; i++)
    {
        glUniformMatrix4fv(uniformLightMatrices[i], 1, GL_FALSE, glm::value_ptr(lMats[i]));
    }
}

void Shader::UseShader()
{
    glUseProgram(shaderId);
}
void Shader::ClearShader()
{
    if (shaderId != 0)
    {
        glDeleteProgram(shaderId);
        shaderId = 0;
    }
    uniformModel = 0;
    uniformProjection = 0;
}

// PRIVATE
void Shader::CompileShader(const char *_v, const char *_f)
{
    shaderId = glCreateProgram();

    if (!shaderId)
    {
        printf("error creating shader program");
        return;
    }
    AddShader(shaderId, _v, GL_VERTEX_SHADER);
    AddShader(shaderId, _f, GL_FRAGMENT_SHADER);

    CompileProgram();
}

void Shader::CompileShader(const char *_v, const char *_g, const char *_f)
{
    shaderId = glCreateProgram();

    if (!shaderId)
    {
        printf("error creating shader program");
        return;
    }
    AddShader(shaderId, _v, GL_VERTEX_SHADER);
    AddShader(shaderId, _g, GL_GEOMETRY_SHADER);
    AddShader(shaderId, _f, GL_FRAGMENT_SHADER);

    CompileProgram();
}

void Shader::Validate()
{
    GLint result = 0;
    GLchar log[1024] = {0};

    glValidateProgram(shaderId);
    glGetProgramiv(shaderId, GL_VALIDATE_STATUS, &result);

    if (!result)
    {
        glGetProgramInfoLog(shaderId, sizeof(log), NULL, log);
        printf("error validating program: '%s'\n", log);
        return;
    }
}

void Shader::CompileProgram()
{
    GLint result = 0;
    GLchar log[1024] = {0};

    glLinkProgram(shaderId);
    glGetProgramiv(shaderId, GL_LINK_STATUS, &result);

    if (!result)
    {
        glGetProgramInfoLog(shaderId, sizeof(log), NULL, log);
        printf("error linking program: '%s'\n", log);
        return;
    }

    uniformModel = glGetUniformLocation(shaderId, "model");
    uniformProjection = glGetUniformLocation(shaderId, "projection");
    uniformView = glGetUniformLocation(shaderId, "view");

    uniformDirectionalLight.uniformColor = glGetUniformLocation(
        shaderId, "directionalLight.base.color");
    uniformDirectionalLight.uniformAmbientIntensity = glGetUniformLocation(
        shaderId, "directionalLight.base.a_intensity");
    uniformDirectionalLight.uniformDiffuseIntensity = glGetUniformLocation(
        shaderId, "directionalLight.base.d_intensity");
    uniformDirectionalLight.uniformDirection = glGetUniformLocation(shaderId, "directionalLight.direction");

    uniformCameraPosition = glGetUniformLocation(shaderId, "cameraPosition");
    uniformSpecularIntensity = glGetUniformLocation(shaderId, "mat.s_intensity");
    uniformSpecularShininess = glGetUniformLocation(shaderId, "mat.shininess");

    uniformPointLightCount = glGetUniformLocation(shaderId, "pointLightCount");
    for (size_t i = 0; i < MAX_POINT_LIGHTS; i++)
    {
        char locBuff[100] = {'\0'};

        snprintf(locBuff, sizeof(locBuff), "pointLights[%d].base.color", i);
        uniformPointLight[i].uniformColor = glGetUniformLocation(shaderId, locBuff);

        snprintf(locBuff, sizeof(locBuff), "pointLights[%d].base.a_intensity", i);
        uniformPointLight[i].uniformAmbientIntensity = glGetUniformLocation(shaderId, locBuff);

        snprintf(locBuff, sizeof(locBuff), "pointLights[%d].base.d_intensity", i);
        uniformPointLight[i].uniformDiffuseIntensity = glGetUniformLocation(shaderId, locBuff);

        snprintf(locBuff, sizeof(locBuff), "pointLights[%d].position", i);
        uniformPointLight[i].uniformPosition = glGetUniformLocation(shaderId, locBuff);

        snprintf(locBuff, sizeof(locBuff), "pointLights[%d].constant", i);
        uniformPointLight[i].uniformConstant = glGetUniformLocation(shaderId, locBuff);

        snprintf(locBuff, sizeof(locBuff), "pointLights[%d].linear", i);
        uniformPointLight[i].uniformLinear = glGetUniformLocation(shaderId, locBuff);

        snprintf(locBuff, sizeof(locBuff), "pointLights[%d].exponent", i);
        uniformPointLight[i].uniformExponent = glGetUniformLocation(shaderId, locBuff);
    }

    uniformSpotLightCount = glGetUniformLocation(shaderId, "spotLightCount");
    for (size_t i = 0; i < MAX_SPOT_LIGHTS; i++)
    {
        char locBuff[100] = {'\0'};

        snprintf(locBuff, sizeof(locBuff), "spotLights[%d].base.base.color", i);
        uniformSpotLight[i].uniformColor = glGetUniformLocation(shaderId, locBuff);

        snprintf(locBuff, sizeof(locBuff), "spotLights[%d].base.base.a_intensity", i);
        uniformSpotLight[i].uniformAmbientIntensity = glGetUniformLocation(shaderId, locBuff);

        snprintf(locBuff, sizeof(locBuff), "spotLights[%d].base.base.d_intensity", i);
        uniformSpotLight[i].uniformDiffuseIntensity = glGetUniformLocation(shaderId, locBuff);

        snprintf(locBuff, sizeof(locBuff), "spotLights[%d].base.position", i);
        uniformSpotLight[i].uniformPosition = glGetUniformLocation(shaderId, locBuff);

        snprintf(locBuff, sizeof(locBuff), "spotLights[%d].base.constant", i);
        uniformSpotLight[i].uniformConstant = glGetUniformLocation(shaderId, locBuff);

        snprintf(locBuff, sizeof(locBuff), "spotLights[%d].base.linear", i);
        uniformSpotLight[i].uniformLinear = glGetUniformLocation(shaderId, locBuff);

        snprintf(locBuff, sizeof(locBuff), "spotLights[%d].base.exponent", i);
        uniformSpotLight[i].uniformExponent = glGetUniformLocation(shaderId, locBuff);

        snprintf(locBuff, sizeof(locBuff), "spotLights[%d].direction", i);
        uniformSpotLight[i].uniformDirection = glGetUniformLocation(shaderId, locBuff);

        snprintf(locBuff, sizeof(locBuff), "spotLights[%d].edge", i);
        uniformSpotLight[i].uniformEdge = glGetUniformLocation(shaderId, locBuff);
    }

    uniformTexture = glGetUniformLocation(shaderId, "map");
    uniformDirectionalLightTransform = glGetUniformLocation(shaderId, "dirLightSpaceTransform");
    uniformDirectionalShadowMap = glGetUniformLocation(shaderId, "dirShadowMap");

    uniformOmniLightPosition = glGetUniformLocation(shaderId, "lightPos");
    uniformFarPlane = glGetUniformLocation(shaderId, "farPlane");

    for (size_t i = 0; i < 6; i++)
    {
        char locBuff[100] = {'\0'};

        snprintf(locBuff, sizeof(locBuff), "lightMatrices[%d]", i);
        uniformLightMatrices[i] = glGetUniformLocation(shaderId, locBuff);
    }

    for (size_t i = 0; i < MAX_POINT_LIGHTS + MAX_SPOT_LIGHTS; i++)
    {
        char locBuff[100] = {'\0'};

        snprintf(locBuff, sizeof(locBuff), "omniShadowMaps[%d].sMap", i);
        uniformOmniShadowMap[i].uniformShadowMap = glGetUniformLocation(shaderId, locBuff);

        snprintf(locBuff, sizeof(locBuff), "omniShadowMaps[%d].farPlane", i);
        uniformOmniShadowMap[i].uniformFarPlane = glGetUniformLocation(shaderId, locBuff);
    }
}

void Shader::AddShader(GLuint _p, const char *_c, GLenum _t)
{
    GLuint shader = glCreateShader(_t);

    const GLchar *codePointer[1];
    codePointer[0] = _c;

    GLint codeLength[1];
    codeLength[0] = strlen(_c);

    glShaderSource(shader, 1, codePointer, codeLength);
    glCompileShader(shader);

    GLint result = 0;
    GLchar log[1024] = {0};
    glGetShaderiv(shader, GL_COMPILE_STATUS, &result);

    if (!result)
    {
        glGetShaderInfoLog(shader, sizeof(log), NULL, log);
        printf("error compiling %d shader: '%s'\n", _t, log);
        return;
    }

    glAttachShader(_p, shader);
}