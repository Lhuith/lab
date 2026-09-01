#ifndef STD_LIB_ARRAY_H
#define STD_LIB_ARRAY_H

#include <array>
#include <iostream>
using namespace std;

namespace stdLibArray {

void someFunc(int *p, int n) {
    for (int i = 0; i < n; ++i)
        cout << p[i] << ", ";
    cout << endl;
}

void someFunc(array<int, 5> arr) {
    for (auto el : arr)
        cout << el << ", ";
    cout << endl;
}

void arrayFuncs() {
    cout << "built-in array\n";
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    someFunc(arr, n);     //&pa[0] will be passed to function (pointer_array[0])

    cout << "std::array\n";
    std::array<int, 5> std_arr{1, 2, 3, 4, 5};
    someFunc(std_arr);
}

void arrayLoops() {
    // std::array can be init'ed the same way as a vector
    std::array<int, 5> arr{1, 2, 3, 4, 5};

    cout << "iterator loop: ";
    for (auto it = begin(arr); it != end(arr); ++it)     // explicit iterator loop
        cout << *it << ", ";
    cout << endl;

    cout << "range-for loop: ";
    for (auto el : arr)     // range-for loop
        cout << el << ", ";
    cout << endl;

    cout << "indexed loop: ";
    for (size_t i = 0; i < arr.size(); ++i)     // indexed loop
        cout << arr[i] << ", ";
    cout << endl;

    // arrays of the same type and size can be assigned
    std::array<int, 5> five_ints;
    five_ints = arr;

    cout << "elements of five_ints: ";
    for (auto el : five_ints)
        cout << el << ", ";
    cout << endl;
}

int main() {
    // // std::array can be list-init'ed
    // std::array<int, 5> arr{1, 2, 3, 4, 5};

    // // elements can be accessed and assigned to using indexing
    // cout << "arr[3] = " << arr[3] << endl;

    // arr[2] = 6;
    // cout << "after assignment, arr[2] = " << arr[2] << endl;

    // arrayLoops();
    arrayFuncs();

    return 0;
}
}     // namespace stdLibArray
#endif     // STD_LIB_ARRAY_H