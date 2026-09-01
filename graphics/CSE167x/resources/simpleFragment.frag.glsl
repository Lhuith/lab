#version 330 core // do not use any version older than 330

// inputs fragment shader are ouputs of same name of vertex shader
in vec4 myvertex;
in vec4 mynormal;
in vec2 texcoord;

// output the frag color
out vec4 fragColor;

uniform sample2D tex;
uniform int istex;
uniform in islight; // are we lighting.
uniform vec3 color;

// assume light 0 is directional, light 1 is a point light
// actaul light values are passed from the main openGL program
uniform vec3 light0dirn;
uniform vec4 light0color;
uniform vec4 light1posn;
uniform vec4 light1color;

// now set the mat parameters. This could be bount to a buffer
// ambient is just additive and doesn't multiply the lights
uniform vec4 ambient;
uniform vec4 diffuse;
uniform vec4 specular;
uniform float shininess;

vec4 ComputeLight(
    const in vec3 direction, const in vec4 lightcolor, 
    const in vec3 normal, const in vec3 halfvec, 
    const in vec4 mydiffuse, const in vec4 myspecular, 
    const in float myshininess) {
        
        float nDotL = dot(normal, direction);
        vec4 lambert = mydiffuse * lightcolor * max(nDotL, 0.0);
        float nDotH = dot(normal, halfvec);
        vec4 phong = myspecular * lightcolor * pow(max(nDotH, 0.0), myshininess);
        vec4 retval = lambert + phong;
        return retval;
}

void main(void) {
    if(istex > 0) fragColor = texture(tex, texcoord);
    else if (islight == 0) fragColor = vec4(color, 1.0f);
    else {
        // the eye is always at (0,0,0) looking down -z axis
        // also compute current fragment position, direction to eye

        const vec3 eyepos = vec3(0,0,0);
        vec3 mypos = myvertex.xyz / myvertex.w; // dohomogenize
        vec3 eyedirn = normalize(eyepos - mypos);

        // compute normal, needed for shading
        vec3 normal = normalize(mynormal);

        // light 0, directional
        vec3 direction0 = normalize(light0dirn);
        vec3 half0 = normalize(direction0 + eyedirn);
        vec4 col0 = ComputeLight(direction0, light0color, normal, half0, diffuse, specular, shininess);

        // light 1, point
        vec3 position = light1posn.xyz / light1posn.w;
        vec3 direction1 = normalize(position - mypos);
        // no atten
        vec3 half1 = normalize(direction1 + eyedirn);
        vec4 col1 = ComputeLight(direction1, light1color, normal, half1, diffuse, specular, shininess);
        fragColor = ambient + col0 + col1; 
    }
}