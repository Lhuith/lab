#include <GL/glut.h> // also <GL/glew.h>; <GLUT/glut.h> for Mac OS
#include <stdlib.h> // also stdio.h, assert.h, glm, others

using namespace std;

GLuint initshaders(GLenum type, const char *filename) {
    GLint compiled;
    // using GLSL shaders, opengl book, page 679 of 7th ed
    GLuint shader = glCreateShader(type); // Glint compiled;
    string str = textFileRead(filename);

    const GLchar * cstr = str.c_str();
    glShaderSource (shader, 1, &cstr, NULL);
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled)

    if(!compiled) {
        shadererrors(shader);
        throw 3;
    }
    return shader;
}

GLuint initprogram(GLuint vertexshader, GLuint fragmentshader) {
    GLuint program = glCreateProgram();
    GLuint linked;

    glAttachShader(program, vertexshader);
    glAttachShader(program, fragmentshader);
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &linked);
    if (linked) glUseProgram(program);
    else {
        programerrors(program);
        throw 4;
    }
    cout<<"shader program successfully attached and linked." << endl;
    return program;
}