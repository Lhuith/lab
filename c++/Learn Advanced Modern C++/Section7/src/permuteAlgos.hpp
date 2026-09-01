#ifndef PERMUTE_ALGOS_H
#define PERMUTE_ALGOS_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace permuteAlgos {

void print_vec(const vector<int>& vec) {
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;
}

void is_perm() {
    vector<int> vec{3, 1, 4, 1, 5, 9};
    vector<int> vec2{1, 3, 4, 5, 9, 1};

    cout << "vec: ";
    print_vec(vec);
    cout << "vec2: ";
    print_vec(vec2);

    if (is_permutation(cbegin(vec), cend(vec), cbegin(vec2), cend(vec2))) {
        cout << "vec is permutation of vec2\n";
    } else {
        cout << "vec is not a permutation of vec2\n";
    }
}

int main() {
    // string str{"abc"};

    // cout << "the permutations of " << str << " are: " << endl;

    // // loop to print out all permutations of str, in order
    // do {
    //     cout << str << endl;
    // } while (next_permutation(begin(str), end(str)));

    // cout << "-------------------------" << endl;

    // cout << "the permutations of " << str << "in reverse order are: " << endl;

    // sort(begin(str), end(str), [](int m, int n) { return m > n; });
    // // loop to print out all permutations of str, in reverse order
    // do {
    //     cout << str << endl;
    // } while (prev_permutation(begin(str), end(str)));

    is_perm();

    return 0;
}
}     // namespace permuteAlgos
#endif     // PERMUTE_ALGOS_H