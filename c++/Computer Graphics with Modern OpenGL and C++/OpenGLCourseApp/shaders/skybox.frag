#version 330

in vec3 texCoords;
out vec4 color;

uniform samplerCube skyMap;

void main(){
    color=texture(skyMap,texCoords);
}