#include <iostream>

// BASHET IMPORTS
#include "customException.hpp"
#include "swapFunc.hpp"
// #include "exceptionSpecialMemFuncs.hpp"
// #include "exceptionHierarch.hpp"
// #include "exceptionSubclasses.hpp"
// #include "catchAllHandle.hpp"
// #include "exceptionMech.hpp"
// #include "exceptionsIntro.hpp"
// #include "tryCatchBlock.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    // BASHET FUNCTIONS
    if (swapFunc::main() != 0) {
        return -1;
    }

    // if (customException::main() != 0) {
    //     return -1;
    // }

    // if (exceptionSpecialMemFuncs::main() != 0) {
    //     return -1;
    // }

    // if (exceptionSubclasses::main() != 0) {
    //     return -1;
    // }

    // if (exceptionHierarch::main() != 0) {
    //     return -1;
    // }

    // if (exceptionMech::main() != 0) {
    //     return -1;
    // }

    // if (catchAllHandle::main() != 0) {
    //     return -1;
    // }

    // if (tryCatchBlock::main() != 0) {
    //     return -1;
    // }

    // if (exceptionsIntro::main() != 0) {
    //     return -1;
    // }

    return 0;
}