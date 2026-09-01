#include <iostream>

// BASHET IMPORTS
#include "multithread.hpp"
#include "oopPatternsVanish.hpp"
#include "perf.hpp"
// #include "refactoring.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    // BASHET FUNCTIONS
    if (oopPatternsVanish::main() != 0) {
        return -1;
    }

    // if (multithread::main() != 0) {
    //     return -1;
    // }

    // if (perf::main() != 0) {
    //     return -1;
    // }

    // if (refactoring::main() != 0) {
    //     return -1;
    // }

    return 0;
}