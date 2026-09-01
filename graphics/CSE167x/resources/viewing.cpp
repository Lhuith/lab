#include <GL/glut.h> // also <GL/glew.h>; <GLUT/glut.h> for Mac OS
#include <stdlib.h> // also stdio.h, assert.h, glm, others

int mouseoldx, mouseoldy; // mouse motion
GLfloat eyeloc = 2.0;
glm::mat4 prjection, modelview; // the mvp matrices themselves

void init(void) {
    /* select clearing color */
    glClearColor(0.0, 0.0, 0.0, 0.0);
    /* initialize viewing values*/
    projection = glm::mat4(1.0f); // the identity matrix
    // think - why is the up vector not normalized
    //   - orthagnical vectors created from up vector, so no need (ortho is always init vectors, relative to the up)
    modelview = glm::lookAt(
                    glm::vec3(0, -eyeloc, eyeloc), 
                    glm::vec3(0, 0, 0), 
                    glm::vec3(0, 1, 1)
                );
   return;
}