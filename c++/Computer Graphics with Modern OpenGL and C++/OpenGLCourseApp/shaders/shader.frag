#version 330

in vec4 vCol;
in vec2 out_uv;
in vec3 Normal;
in vec3 fragPos;
in vec4 dirLightSpacePos;

const int MAX_POINT_LIGHTS=3;
const int MAX_SPOT_LIGHTS=3;

struct Light{
    vec3 color;
    float a_intensity;
    float d_intensity;
};

struct DirectionalLight{
    Light base;
    vec3 direction;
};

uniform int pointLightCount;
struct PointLight{
    Light base;
    vec3 position;
    float constant;
    float linear;
    float exponent;
};

uniform int spotLightCount;
struct SpotLight{
    PointLight base;
    vec3 direction;
    float edge;
};

struct Material{
    float s_intensity;
    float shininess;
};

struct OmniShadowMap{
    samplerCube sMap;
    float farPlane;
};

uniform DirectionalLight directionalLight;
uniform PointLight pointLights[MAX_POINT_LIGHTS];
uniform SpotLight spotLights[MAX_SPOT_LIGHTS];

uniform sampler2D map;
uniform sampler2D dirShadowMap;
uniform OmniShadowMap omniShadowMaps[MAX_POINT_LIGHTS+MAX_SPOT_LIGHTS];

uniform Material mat;

uniform vec3 cameraPosition;

vec3 gridSamplingDisk[20]=vec3[]
(
    vec3(1,1,1),vec3(1,-1,1),vec3(-1,-1,1),vec3(-1,1,1),
    vec3(1,1,-1),vec3(1,-1,-1),vec3(-1,-1,-1),vec3(-1,1,-1),
    vec3(1,1,0),vec3(1,-1,0),vec3(-1,-1,0),vec3(-1,1,0),
    vec3(1,0,1),vec3(-1,0,1),vec3(1,0,-1),vec3(-1,0,-1),
    vec3(0,1,1),vec3(0,-1,1),vec3(0,-1,-1),vec3(0,1,-1)
);

float CalcDirShadowFactor(DirectionalLight l){
    vec3 projCoords=dirLightSpacePos.xyz/dirLightSpacePos.w;
    projCoords=(projCoords*.5)+.5;
    
    float current=projCoords.z;
    
    vec3 normal=normalize(Normal);
    vec3 lightDir=normalize(l.direction);
    
    float bias=max(.05*(1.-dot(normal,lightDir)),.0005);
    
    float shadow=0.;
    
    vec2 texelSize=1./textureSize(dirShadowMap,0);
    
    for(int x=-1;x<=1;++x){
        for(int y=-1;y<=1;++y){
            float pcfDepth=texture(dirShadowMap,projCoords.xy+vec2(x,y)*texelSize).r;
            shadow+=current-bias>pcfDepth?1.f:0.f;
        }
    }
    shadow/=9.f;
    
    if(projCoords.z>1.f){
        shadow=0.;
    }
    
    return shadow;
}

float CalcOmniShadowFactor(PointLight l,int shadowIndex){
    vec3 fragToLight=fragPos-l.position;
    float current=length(fragToLight);
    
    float shadow=0.f;
    float bias=.01f;
    int samples=20;
    
    float viewDistance=length(fragPos-cameraPosition);
    float diskRadius=(1.+(viewDistance/omniShadowMaps[shadowIndex].farPlane))/25.;
    
    for(int i=0;i<samples;i++){
        float closest=texture(
        omniShadowMaps[shadowIndex].sMap,fragToLight+gridSamplingDisk[i]*diskRadius).r;
        
        closest*=omniShadowMaps[shadowIndex].farPlane;// remove 0,1 map scaling done in geo shader
        
        if(current-bias>closest){
            shadow+=1.;
        }
    }
    
    shadow/=float(samples);// yikes
    return shadow;
}

vec4 CalcLightByDirection(Light l,vec3 direction,float shadowFactor){
    vec4 ambient=vec4(l.color,1.f)*l.a_intensity;
    
    float diffuseFactor=max(dot(normalize(Normal),normalize(direction)),0.f);
    vec4 diffuseColor=vec4(l.color*l.d_intensity*diffuseFactor,1.f);
    
    vec4 specularColor=vec4(0.);
    
    if(diffuseFactor>0.f){
        vec3 fragToCam=normalize(cameraPosition-fragPos);
        vec3 reflection=normalize(reflect(direction,normalize(Normal)));
        
        float specularFactor=dot(fragToCam,reflection);
        
        if(specularFactor>0.){
            specularFactor=pow(specularFactor,mat.shininess);
            specularColor=vec4(l.color*mat.s_intensity*specularFactor,1.f);
        }
    }
    
    return(ambient+(1.-shadowFactor)*(diffuseColor+specularColor));
}

vec4 CalcDirectionalLight(){
    float shadowFactor=CalcDirShadowFactor(directionalLight);
    return CalcLightByDirection(directionalLight.base,directionalLight.direction,shadowFactor);
}

vec4 CalcPointLight(PointLight pLight,int shadowIndex){
    vec3 direction=fragPos-pLight.position;
    float dist=length(direction);
    direction=normalize(direction);
    
    float shadowFactor=CalcOmniShadowFactor(pLight,shadowIndex);
    
    vec4 color=CalcLightByDirection(pLight.base,direction,shadowFactor);
    float attenuation=(pLight.exponent*dist*dist)+
    (pLight.linear*dist)+
    (pLight.constant);
    
    return(color/attenuation);
}

vec4 CalcPointLights(){
    vec4 totalColor=vec4(0);
    for(int i=0;i<pointLightCount;i++)
    {
        totalColor+=CalcPointLight(pointLights[i],i);
    }
    return totalColor;
}

vec4 CalcSpotLight(SpotLight sLight,int shadowIndex){
    vec3 rayDirection=normalize(fragPos-sLight.base.position);
    float slFactor=dot(rayDirection,sLight.direction);
    
    if(slFactor>sLight.edge)
    {
        vec4 colour=CalcPointLight(sLight.base,shadowIndex);
        
        return colour*(1.f-(1.f-slFactor)*(1.f/(1.f-sLight.edge)));
        
    }else{
        return vec4(0,0,0,0);
    }
}

vec4 CalcSpotLights(){
    vec4 totalColor=vec4(0,0,0,0);
    for(int i=0;i<spotLightCount;i++)
    {
        // note : [MAX_POINT_LIGHTS+MAX_SPOT_LIGHTS] <-- spot lates deeper in array
        totalColor+=CalcSpotLight(spotLights[i],i+pointLightCount);
    }
    return totalColor;
}

out vec4 fragColor;
void main()
{
    vec4 finalColor=CalcDirectionalLight();
    finalColor+=CalcPointLights();
    finalColor+=CalcSpotLights();
    
    fragColor=texture(map,out_uv)*finalColor;
}