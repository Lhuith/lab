int main (int argc, char** argv) {
    glutInit(&argc, argv);
    // Requests the type of buffers (Single, RGB)
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    // Need to add GLUT_3_2_CORE_PROFILE for Apple/Mac OS
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Simple Demo with Shaders");
    // glewInit()l // GLEW related stuff for non-Apple systems
    init(); // always init first

    // Now, we define callbacks and functions for varoius tasks
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseDrag)
    glutMainLoop(); // start the main code
    deleteBuffers(); // termination. delete generated in init()
    return 0; /* ANSI C requires main to return int. */
}