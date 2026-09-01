#ifndef WRITE_ALGOS_H
#define WRITE_ALGOS_H

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int>& vec) {
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;
}

namespace writeAlgos {

void replace_copy_if() {
    vector<int> vec1{3, 1, 4, 1, 5, 9};

    cout << "vec1: ";
    print(vec1);

    vector<int> vec2;

    // replace all even numbers by 6
    replace_copy_if(cbegin(vec1), cend(vec1), back_inserter(vec2), [](int n) { return (n % 2 == 0); }, 6);

    cout << "result of replace_copy_if: ";
    print(vec2);

    vector<int> vec3;
    for (auto v : vec1)     // == loop
        if (v % 2 == 0)
            vec3.push_back(6);
        else
            vec3.push_back(v);
    cout << "result of loop: ";
    print(vec3);
}

void replace_copy() {
    vector<int> vec1{3, 1, 4, 1, 5, 9};

    cout << "vec1: ";
    print(vec1);

    vector<int> vec2;

    // replace all occurrences of 1 with 2
    replace_copy(cbegin(vec1), cend(vec1), back_inserter(vec2), 1, 2);

    cout << "result of replace_copy: ";
    print(vec2);

    vector<int> vec3;
    for (auto v : vec1)     // == loop
        if (v == 1)
            vec3.push_back(2);
        else
            vec3.push_back(v);
    cout << "result of loop: ";
    print(vec3);
}

void replace_if() {
    // replace all even numbers with 6
    vector<int> vec{3, 1, 4, 1, 5, 9};

    cout << "vec: ";
    print(vec);

    // replace all(but for copy) all occurrences of 1 with 2
    replace_if(begin(vec), end(vec), [](int n) { return (n % 2 == 0); }, 6);

    cout << "vector after replace_if: ";
    print(vec);

    vector<int> vec2{3, 1, 4, 1, 5, 9};
    for (auto& v : vec2)     // == loop
        if (v % 2 == 0)
            v = 6;
    cout << "vector after loop: ";
    print(vec2);
}

int main() {
    // // replace all occurrences of 1 with 2
    // vector<int> vec{3, 1, 4, 1, 5, 9};

    // cout << "vec: ";
    // print(vec);

    // replace(begin(vec), end(vec), 1, 2);

    // cout << "vector after replace: ";
    // print(vec);

    // vector<int> vec2{3, 1, 4, 1, 5, 9};
    // for (auto& v : vec2)     // equivalent loop
    //     if (v == 1)
    //         v = 2;
    // cout << "vector after loop: ";
    // print(vec2);

    // replace_if();
    // replace_copy();
    replace_copy_if();

    return 0;
}
}     // namespace writeAlgos
#endif     // WRITE_ALGOS_H