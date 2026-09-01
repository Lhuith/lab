#include <iostream>

// BASHET IMPORTS
// #include "lockFreeProgPrac.hpp"
#include "lockFreeProgPracCont.hpp"
// #include "assignment5.hpp"
// #include "atomicOps.hpp"
// #include "intOpsThreads.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    // BASHET FUNCTIONS
    if (lockFreeProgPracCont::main() != 0) {
        return -1;
    }

    // if (lockFreeProgPrac::main() != 0) {
    //     return -1;
    // }

    // if (atomicOps::main() != 0) {
    //     return -1;
    // }

    // if (assignment5::main() != 0) {
    //     return -1;
    // }

    // if (intOpsThreads::main() != 0) {
    //     return -1;
    // }

    return 0;
}