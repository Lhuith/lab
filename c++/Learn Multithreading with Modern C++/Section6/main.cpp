#include <iostream>

// BASHET IMPORTS
#include "futurePromise.hpp"
// #include "promMultiWait.hpp"
// #include "condVarPrac.hpp"
// #include "condVar.hpp"
// #include "threadCoordPrac.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    // BASHET FUNCTIONS

    if (futurePromise::main() != 0) {
        return -1;
    }

    // if (condVarPrac::main() != 0) {
    //     return -1;
    // }

    // if (condVar::main() != 0) {
    //     return -1;
    // }

    // if (threadCoordPrac::main() != 0) {
    //     return -1;
    // }

    return 0;
}