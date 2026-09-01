#ifndef FURTHER_NUMERIC_ALGOS_CONT_H
#define FURTHER_NUMERIC_ALGOS_CONT_H

#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

namespace furtherNumericAlgosCont {

void print(const vector<int>& vec) {
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;
}

void overloaded_inner_prod() {
    vector<double> expected{0.1, 0.2, 0.3, 0.4, 0.5};
    vector<double> actual{0.09, 0.22, 0.27, 0.41, 0.52};

    auto max_diff = inner_product(
        begin(expected), end(expected), begin(actual), 0.0,
        [](auto a, auto b) { return max(a, b); },        // reduce operator
        [](auto l, auto r) { return fabs(r - l); });     // transform operator

    cout << "max difference is: " << max_diff << endl;
}

int main() {
    // vector<int> vec1{1, 3, 6, 10, 15};
    // vector<int> vec2{1, 2, 3, 4, 5};

    // cout << "vec1: ";
    // print(vec1);
    // cout << "vec2: ";
    // print(vec2);

    // auto result = inner_product(cbegin(vec1), cend(vec1), cbegin(vec2), 0);
    // cout << "the inner product of vec1 and vec2 is: " << result << endl;

    // vector<int> vec3;
    // transform(cbegin(vec1), cend(vec1), cbegin(vec2), back_inserter(vec3), multiplies<int>());
    // auto result2 = accumulate(cbegin(vec3), cend(vec3), 0);

    // cout << "the result of transform + accumulate is: " << result2 << endl;
    overloaded_inner_prod();

    return 0;
}
}     // namespace furtherNumericAlgosCont
#endif     // FURTHER_NUMERIC_ALGOS_CONT_H