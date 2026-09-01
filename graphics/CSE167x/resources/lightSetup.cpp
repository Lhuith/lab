#include <stdlib.h> // also stdio.h, assert.h, glm, others
#include <GL/glut.h> // also <GL/glew.h>; <GLUT/glut.h> for Mac OS

void lightHold(void){

        // mapping
    vertexshader = initshaders(GL_VERTEX_SHADER, "shaders/light.vert");
    fragmentshader = initshaders(GL_FRAGMENT_SHADER, "shaders/light.frag");
    shaderprogram = initprogram(vertexshader, fragmentshader);

    // setup shader params mapping properly for lighting
    isLight = glGetUniformLocation(shaderprogram, "isLight");
    light0dirn = glGetUniformLocation(shaderprogram, "light0dirn");
    light0color = glGetUniformLocation(shaderprogram, "light0color");
    light1posn = glGetUniformLocation(shaderprogram, "light1posn");
    light1color = glGetUniformLocation(shaderprogram, "light1color");
    ambient = glGetUniformLocation(shaderprogram, "ambient");
    diffuse = glGetUniformLocation(shaderprogram, "diffuse");
    specular = glGetUniformLocation(shaderprogram, "specular");
    shininess = glGetUniformLocation(shaderprogram, "shininess");

    const GLfloat one[] = {1,1,1,1};
    const GLfloat medium[] = {0.5f, 0.5f, 0.5f, 1};
    const GLfloat small[] = {0.2f, 0.2f, 0.2f, 1};
    const GLfloat high[] = {100};
    const GLfloat zero[] = {0.0, 0.0, 0.0, 1.0};
    const GLfloat light_specular[]  = {1, 0.5, 0, 1};
    const GLfloat light_specular1[] = {0, 0.5, 1, 1};
    const GLfloat light_direction[] = {0.5, 0, 0, 0}; // dir lt
    const GLfloat light_position1[] = {0, -0.5, 0, 1};
    GLfloat light0[4], light1[4];

    // set light and metarial properties for the teapot
    // lights are transformed by current modelview matrix
    // the shader can't do this globally. so we do it manually.

    transformvec(light_direction, light0);
    transformvec(light_position1, light1);

    glUniform3fv(light0dirn, 1, light0);
    glUniform4fv(light0color, 1, light_specular);
    glUniform4fv(light1posn, 1, light1);
    glUniform4fv(light1color, 1, light_specular1);
    glUniform4fv(ambient, 1, small);
    glUniform4fv(diffuse, 1, medium);
    glUniform4fv(specular, 1, one);
    glUniform1fv(shininess, 1, high);

    // enable and disable everything around the teapot
    // generally, we would also need to define normals etc.
    // but teapot object file already defines these for us

    if (DEMO > 4) {
            glUniform1i(islight, lighting); // lighting only teapot
    }



    return
}

void tansformvec(const GLfloat input[4], GLfloat output[4]) {
    glm::vec4 inputvec(input[0], input[1], input[2], input[3]);
    glm::vec4 outputvec = modelview * inputvec;
    output[0] = outputvec[0];
    output[1] = outputvec[1];
    output[2] = outputvec[2];
    output[3] = outputvec[3];
}