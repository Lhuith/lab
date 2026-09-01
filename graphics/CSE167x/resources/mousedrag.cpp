void mousedrag(int x, int y){
    int yloc = y - mouseoldy; // we will use the y coord to zoom in/out
    eyeloc += 0.005*yloc; // where we do the look from

    if (eyeloc < 0) eyeloc = 0.0;
    mouseoldy = y;

    /* set the eye location */
    modelview = glm::lookAt(
            glm::vec3(0, -eyeloc, eyeloc),
            glm::vec3(0, 0, 0), 
            glm::vec3(0, 1, 1)
        );
    // send updated matrix to the shader
    glUniformMatrix4fv(modelviewPos, 1, GL_FALSE, &modelview[0][0]);

    glutPostRedisplay();
}