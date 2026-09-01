/*
    reshapes the window appropriatley
*/
void reshape(int w, int h) {
    glViewPort(0, 0, (GLsizei) w, (GLsizei) h);
    // note that the field of view takes in a radian angle
    // (fovy in radians, aspect ratio, near, far)
    projection = glm::perspective(30.0f / 180.0f * glm::pi<float>(), (GLfloat)w / (GLfloat)h, 1.0f, 10.0f);

    // in shader
    // (position in the shader, of the position of the projection matrix)
    glUniformMatrix4fv(projectionPos, 1, GL_FALSE, &projection[0][0]);
    // to send the projection matrix to the shader
}