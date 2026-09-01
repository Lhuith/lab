#include <iostream>

// BASHET IMPORTS
// #include "concDataQuePrac.hpp"
// #include "cxxSemaphores.hpp"
#include "threadPoolPrac.hpp"
// #include "monitorClass.hpp"
// #include "monitorClassCont.hpp"
// #include "dataStructsConc.hpp"
// #include "sharedPtr.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    // BASHET FUNCTIONS
    if (threadPoolPrac::main() != 0) {
        return -1;
    }

    // if (concDataQuePrac::main() != 0) {
    //     return -1;
    // }

    // if (cxxSemaphores::main() != 0) {
    //     return -1;
    // }

    // if (monitorClassCont::main() != 0) {
    //     return -1;
    // }

    // if (monitorClass::main() != 0) {
    //     return -1;
    // }

    // if (sharedPtr::main() != 0) {
    //     return -1;
    // }

    // if (dataStructsConc::main() != 0) {
    //     return -1;
    // }

    return 0;
}