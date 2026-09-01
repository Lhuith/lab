#ifndef NUMERIC_ALGOS_CONT_H
#define NUMERIC_ALGOS_CONT_H

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

namespace numericAlgosCont {

void print(const vector<int>& vec) {
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;
}

void inner_prod() {
    vector<int> vec1{1, 3, 6, 10, 15};
    vector<int> vec2{1, 2, 3, 4, 5};

    cout << "vec1: ";
    print(vec1);
    cout << "vec2: ";
    print(vec2);

    auto result = inner_product(cbegin(vec1), cend(vec1), cbegin(vec2), 0);
    cout << "the inner product of vec1 and vec2 is: " << result << endl;
}

void adj_diff() {
    vector<int> vec1{1, 3, 6, 10, 15};
    vector<int> vec2;

    cout << "source vector: ";
    print(vec1);

    adjacent_difference(cbegin(vec1), cend(vec1), back_inserter(vec2));

    cout << "target vector: ";
    print(vec2);
}

int main() {
    // vector<int> vec1{1, 2, 3, 4, 5};
    // vector<int> vec2;

    // cout << "source vector: ";
    // print(vec1);

    // partial_sum(cbegin(vec1), cend(vec1), back_inserter(vec2));

    // cout << "target vector: ";
    // print(vec2);

    // adj_diff();

    inner_prod();

    return 0;
}
}     // namespace numericAlgosCont
#endif     // NUMERIC_ALGOS_CONT_H