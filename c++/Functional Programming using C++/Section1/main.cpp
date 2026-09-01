#include <iostream>

// BASHET IMPORTS
#include "filter.hpp"
// #include "squareValues.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    // BASHET FUNCTIONS
    if (filter::main() != 0) {
        return -1;
    }

    // if (squareValues::main() != 0) {
    //     return -1;
    // }

    return 0;
}