#ifndef SORTING_ALGOS_CONT_H
#define SORTING_ALGOS_CONT_H

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace sortingAlgosCont {

void print(const vector<int>& vec) {
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;
}

void _nth_element() {
    vector<int> vec{1, 4, 5, 6, 2, 7, 5};
    vector<int> vec2{vec};
    sort(begin(vec2), end(vec2));

    cout << "vec: ";
    print(vec);

    cout << "vec if sorted: ";
    print(vec2);

    cout << endl
         << "calling nth_element" << endl;

    auto mid = begin(vec) + 4;
    nth_element(begin(vec), mid, end(vec));

    cout << "the mid element is " << *mid << endl;

    cout << "vec: ";
    print(vec);
}

void _partial_sort_copy() {
    string keys{"qwertyuiopasdfghjkl"};
    string dest(5, ' ');

    cout << "keys: " << keys << endl
         << endl;

    partial_sort_copy(cbegin(keys), cend(keys), begin(dest), end(dest));

    cout << "first 5 characters of keys are: " << dest << endl;
    cout << "full keys string: " << keys << endl
         << endl;
}

int main() {
    // string keys{"qwertyuiopasdfghjkl"};

    // cout << "keys: " << keys << endl
    //      << endl;

    // auto it = begin(keys);
    // partial_sort(it, it + 5, end(keys));

    // cout << "first 5 characters of keys are: " << keys.substr(0, 5) << endl;
    // cout << "full key string: " << keys << endl
    //      << endl;

    // advance(it, 5);
    // partial_sort(it, it + 5, end(keys));
    // cout << "the next 5 characters of keys are: " << keys.substr(5, 5) << endl;

    // cout << "full keys string: " << keys << endl;
    // _partial_sort_copy();
    _nth_element();

    return 0;
}
}     // namespace sortingAlgosCont
#endif     // SORTING_ALGOS_CONT_H