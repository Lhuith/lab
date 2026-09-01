#include <stdlib.h> // also stdio.h, assert.h, glm, others
#include <GL/glut.h> // also <GL/glew.h>; <GLUT/glut.h> for Mac OS
#include "shaders.h"

const GLfloat floorverts[4][3] = {{0.5, 0.5, 0.0}, {-0.5, 0.5, 0.0}, {-0.5, -0.5, 0.0}, {0.5, -0.5, 0.0}};
const GLfloat floorcol[4][3]  = { {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}, {1.0, 1.0, 1.0}};
const GLubyte floorinds[1][6] = {{0, 1, 2, 0, 2, 3}}; // triangles

const GLfloat floorverts2[4][3] = {{0.5, 0.5, 1.0}, {-0.5, 0.5, 1.0}, {-0.5, -0.5, 1.0}, {0.5, -0.5, 1.0}};
const GLfloat floorcol2[4][3]  = { {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0}};
const GLubyte floorinds2[1][6] = {{0, 1, 2, 0, 2, 3}}; // triangles

const int numobjects = 2;               // number of objects for the buffer
const int numperobj = 3;                // vertices, colors, indices

GLuint VAOs[numobjects];                // a vertex array object per object
GLuint buffers[numobjects*numperobj];   // list of buffers geometric data
GLuint objects[numobjects];             // for each object

GLenum  PrimType[numobjects];           // primitive type (triangles, strips)
GLsizei NumElems[numobjects];           // number of geometric elements

// floor geometry is specificed with vertex array
enum{Vertices, Colors, Elements};       // for arrays for object
enum{FLOOR, FLOOR2};                    // for objects, for the floor

// in init below (creates buffer objects for later use)
glGenVertexArrays(numobjects, VAOs);            // create unique identifiers
glGenBuffers(numobjects*numperobj, buffers);    // and for buffers

void deleteBuffers() {
    glDeleteVertexArrays(numobjects, VAOs);
    glDeleteBuffers(numobjects*numperobj, buffers);
}

void initobject(
    GLuint object,                  // object id 
    GLfloat * vert, GLint sizevert, 
    GLfloat * col, GLint sizecol, 
    GLubyte * inds, GLint sizeind, 
    GLenum type
) {
    int offset = object * numperobj;
    glBindVertexArray(VAOs[object]);

    { // vertices, location 0 for vertices
        glBindBuffer(GL_ARRAY_BUFFER, buffers[Vertices+offset]);
        glBufferData(GL_ARRAY_BUFFER, sizevert, vert, GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);
    }
 
    { // colors, location 1 for colors
        glBindBuffer(GL_ARRAY_BUFFER, buffers[Colors+offset]);
        glBufferData(GL_ARRAY_BUFFER, sizecol, col, GL_STATIC_DRAW);
        glEnableVertexAttribArray(1)
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * size(GLfloat), 0);
    }

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[Elements+offset]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeind, inds, GL_STATIC_DRAW);
    PrimType[object] = type;
    NumElems[object] = sizeind;

    // prevent further mods of this VOA by unbinding it
    glBindVertexArray(0);
}

void drawobject(GLuint object) {
    glBindVertexArray(VAOs[object]);
    glDrawElements(PrimType[object], NumElems[object], GL_UNSIGNED_BYTE, 0);
    glBindVertexArray(0); // unbind
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT); // clear all pixels
    drawobject(FLOOR);
    drawobject(FLOOR2);
    glFlush();

    // start processing buffered OpenGL commands
}


GLuint vertexshader, fragmentshader, shaderprogram; // shaders
void holderFunc() {
    // initilaize in init() for drawing
    glGenVertexArrays(numobjects, VAOs);
    glGenBuffers(numperobj*numobjects, buffers);

    initobject(
        FLOOR, 
        (GLfloat *) floorverts, sizeof(floorverts), 
        (GLfloat *) floorcol, sizeof(floorcol), 
        (GLubyte *) floorinds, sizeof(floorinds), 
        GL_TRIANGLES);

    initobject(
        FLOOR2, 
        (GLfloat *) floorverts2, sizeof(floorverts2), 
        (GLfloat *) floorcol2, sizeof(floorcol2), 
        (GLubyte *) floorinds2, sizeof(floorinds2), 
        GL_TRIANGLES); 

    // in init() for shaders
    vertexshader = initshader(GL_VERTEX_SHADER, "shader/nop.vert");
    fragmentshader = initshader(GL_FRAGMENT_SHADER, "shader/nop.frag");
    shaderprogram = initprogram(vertexshader, fragmentshader);
}