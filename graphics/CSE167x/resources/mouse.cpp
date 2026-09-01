void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if(state == GLUT_UP){ /* do nothing*/;}
        else if (state == GLUT_DOWN) {
            mouseoldx = x; mouseoldy = y; // so we can move wrt x, y
        } 
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        // reset gluLookAt
        eyeloc = 2.0;
        modelview = glm::lookAt(
            glm::vec3(0, -eyeloc, eyeloc),
            glm::vec3(0, 0, 0), 
            glm::vec3(0, 1, 1)
        );
        // send updated matrix to the shader
        glUniformMatrix4fv(modelviewPos, 1, GL_FALSE, &modelview[0][0]);
        glutPostRedisplay(); // redraw scene
    }
}