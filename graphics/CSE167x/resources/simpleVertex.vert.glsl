#version 330 core // do not use any version older than 330

// inputs
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords;

// Extra ouputs, in any
out vec4 myvertex;
out vec4 mynormal;
out vec2 texcoord;

// uniform variables
uniform mat4 projection;
uniform mat4 modelview;
uniform int istex;

void main() {
    gl_position = projection * modelview * vec4(position, 1.0f);
    mynormal = mat3(transpose(inverse(modelview))) * normal;
    myvertex = modelview * vec4(position, 1.0f);
    texcoord = vec2(0.0, 0.0); // defualt value just to prevent errors
    if (istex != 0) {texcoord = texCoords;}
}