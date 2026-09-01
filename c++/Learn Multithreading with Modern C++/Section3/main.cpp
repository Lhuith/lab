#include <iostream>

// BASHET IMPORTS
// #include "assignment1.hpp"
#include "threadFunctionsWithArgs.hpp"
// #include "launchingAThread.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    // BASHET FUNCTIONS
    if (threadFunctionsWithArgs::main() != 0) {
        return -1;
    }

    // if (assignment1::main() != 0) {
    //     return -1;
    // }

    // if (launchingAThread::main() != 0) {
    //     return -1;
    // }

    return 0;
}