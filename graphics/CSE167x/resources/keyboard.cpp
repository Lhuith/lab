/*
    Defines what to do when various keys are pressed
*/
void keyboard(unsigned char key, int x, int y) {
    switch(key) {
        case 27: // escape to quit
            exit(0);
            break;
        default:
            break;
    }
}