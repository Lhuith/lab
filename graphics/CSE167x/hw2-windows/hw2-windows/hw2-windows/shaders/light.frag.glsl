# version 330 core
// Do not use any version older than 330!

/* This is the fragment shader for reading in a scene description, including 
   lighting.  Uniform lights are specified from the main program, and used in 
   the shader.  As well as the material parameters of the object.  */

// Inputs to the fragment shader are the outputs of the same name of the vertex shader.
// Note that the default output, gl_Position, is inaccessible!
in vec3 mynormal; 
in vec4 myvertex; 

// You will certainly need this matrix for your lighting calculations
uniform mat4 modelview;

// This first defined output of type vec4 will be the fragment color
out vec4 fragColor;

uniform vec3 color;

const int numLights = 10; 
uniform bool enablelighting; // are we lighting at all (global).
uniform vec4 lightposn[numLights]; // positions of lights 
uniform vec4 lightcolor[numLights]; // colors of lights
uniform int numused;               // number of lights used

// Now, set the material parameters.
// I use ambient, diffuse, specular, shininess. 
// But, the ambient is just additive and doesn't multiply the lights.  

uniform vec4 ambient; 
uniform vec4 diffuse; 
uniform vec4 specular; 
uniform vec4 emission; 
uniform float shininess; 

vec4 CalculateLight(const in vec3 dir, in vec4 col, const in vec3 n, const in vec3 halfv, const in vec4 diff, const in vec4 spec, const in float shine) {
    // do lighting calc here
    float nDotL = dot(n, dir);
    vec4 lam = diff * col * max(nDotL, 0.0);

    float nDotH = dot(n, halfv);
    vec4 phong = spec * col * pow(max(nDotH, 0.0), shine);

    return lam + phong;
}

void main (void) {       
    if (enablelighting) {       
        vec4 finalcolor; 

        // YOUR CODE FOR HW 2 HERE
        // A key part is implementation of the fragment shader
        vec4 lighting = vec4(0,0,0,0);
        const vec3 eyepos = vec3(0, 0, 0);

        vec4 newPos = modelview * myvertex;
        vec3 mypos = newPos.xyz / newPos.w; // dehomogenize location
        vec3 eyedirn = normalize(eyepos - mypos);
        
        mat3 inverseTranspose = mat3(transpose(inverse(modelview)));
        vec3 normal = normalize(inverseTranspose * mynormal);
            
        for(int i = 0; i < numused; i++) {
            vec3 dir = vec3(0,0,0);
            if(lightposn[i].w == 0.0){
                dir = normalize(lightposn[i].xyz);
            } else {
                vec3 pos = lightposn[i].xyz / lightposn[i].w;
                dir = normalize(pos - mypos);
            } 

            vec3 halfy = normalize(dir + eyedirn);
            lighting += CalculateLight(dir, lightcolor[i], normal, halfy, diffuse, specular, shininess);
        }
        // Color all pixels black for now, remove this in your implementation!
        fragColor = ambient + lighting; 
    } else {
        fragColor = vec4(color, 1.0f); 
    }
}
