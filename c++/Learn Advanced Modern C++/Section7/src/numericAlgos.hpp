#ifndef NUMERIC_ALGOS_H
#define NUMERIC_ALGOS_H

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

namespace numericAlgos {

void sum_odd() {
    vector<int> vec{3, 1, 4, 1, 5, 9};

    cout << "vector: ";
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;

    auto sum = accumulate(cbegin(vec), cend(vec), 0,
                          [](int sum, int n) { return (n % 2 == 1) ? sum + n : sum; });

    cout << "sum of odd elements: " << sum << endl;
}

void sum() {
    vector<int> vec{3, 1, 4, 1, 5, 9};

    cout << "vector: ";
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;

    auto sum = accumulate(cbegin(vec), cend(vec), 0);     // returns the sum of the elements

    cout << "sum calculated by algorithm: " << sum << endl;
    sum = 0;
    for (auto v : vec)
        sum += v;
    cout << "sum calculated by loop: " << sum << endl;
}
int main() {
    // vector<int> vec(10);     // create a vector with 10 elements

    // // call iota() with the start value 1
    // iota(begin(vec), end(vec), 1);     // populate the vector elements as 1, 2, 3, 4, ...

    // cout << "vector populated by itoa: ";
    // for (auto v : vec)
    //     cout << v << ", ";

    // vector<int> vec2(10);
    // int n{1};
    // for (auto& v : vec2) {
    //     v = n;
    //     ++n;
    // }

    // cout << "\nvector populated by loop: ";
    // for (auto v : vec2)
    //     cout << v << ", ";
    // cout << endl;
    // sum();
    sum_odd();
    return 0;
}
}     // namespace numericAlgos
#endif     // NUMERIC_ALGOS_H