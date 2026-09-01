#include <iostream>

// BASHET IMPORTS
#include "weakPointerCyclePrevention.hpp"
// #include "sharedPointer.hpp"
#include "weakPointer.hpp"
// #include "pimplIdiom.hpp"
// #include "referenceCounting.hpp"
// #include "uniqPointerCustomDelete.hpp"
// #include "uniqPointer.hpp"
// #include "uniqPointerPoly.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    // BASHET FUNCTIONS
    if (weakPointerCyclePrevention::main() != 0) {
        return -1;
    }

    // if (weakPointer::main() != 0) {
    //     return -1;
    // }

    // if (sharedPointer::main() != 0) {
    //     return -1;
    // }

    // if (referenceCounting::main() != 0) {
    //     return -1;
    // }

    // if (pimplIdiom::main() != 0) {
    //     return -1;
    // }

    // if (uniqPointerCustomDelete::main() != 0) {
    //     return -1;
    // }

    // if (uniqPointerPoly::main() != 0) {
    //     return -1;
    // }

    // if (uniqPointer::main() != 0) {
    //     return -1;
    // }

    return 0;
}