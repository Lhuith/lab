#ifndef INTERFACING_TO_C_H
#define INTERFACING_TO_C_H

// #include <add.h>
// #include <stdio.h>

#include <iostream>
#include <vector>

extern "C" {
#include "array.h"
}

using namespace std;

namespace interfacingToC {
int main() {
    vector<int> vec{3, 1, 4, 1, 5, 9};

    cout << "vector elements: ";
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;

    cout << "calling array_print(): ";
    array_print(vec.data(), vec.size());

    // printf("add(2,3) returns %d\n", add(2, 3));
    return 0;
}
}     // namespace interfacingToC
#endif     // INTERFACING_TO_C_H