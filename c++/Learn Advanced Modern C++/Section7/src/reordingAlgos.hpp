#ifndef REORDING_ALGOS_H
#define REORDING_ALGOS_H

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace reordingAlgos {

void print(const vector<int>& vec) {
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;
}

void _rotate_copy() {
    vector<int> vec{1, 2, 3, 4, 5};

    cout << "initial vector: ";
    print(vec);

    // use the third element as the pivot
    auto pivot = begin(vec);
    advance(pivot, 2);

    // perform rotation
    vector<int> vec2(vec.size());
    auto res = rotate_copy(begin(vec), pivot, end(vec), begin(vec2));

    cout << "result of rotate: ";
    print(vec2);

    // res is an iterator to the element in vec2 with value 2
    cout << "the original first element was " << *(res - 1) << endl;
}

void _rotate() {
    vector<int> vec{1, 2, 3, 4, 5};

    cout << "initial vector: ";
    print(vec);

    // use the third element as the pivot
    auto pivot = begin(vec);
    advance(pivot, 2);

    // perform rotation
    auto res = rotate(begin(vec), pivot, end(vec));

    cout << "result of rotate: ";
    print(vec);

    // res is an iterator to the element with value 1
    cout << "the original first element was " << *res << endl;
}

int main() {
    // vector<int> vec{3, 1, 4, 1, 5, 9};
    // vector<int> vec2;

    // cout << "original vector: ";
    // print(vec);

    // // make copy of original vector for use in loop later
    // copy(cbegin(vec), cend(vec), back_inserter(vec2));
    // reverse(begin(vec), end(vec));

    // cout << "result of reverse: ";
    // print(vec);

    // // use a loop to reverse the elements
    // size_t len{vec2.size() - 1};

    // for (size_t i = 0; i <= len / 2; ++i) {
    //     /*		// basically a swap op
    //             int temp{vec[i]};
    //             vec2[i] = vec2[len-i];
    //             vec2[len-i] = temp;
    //     */
    //     swap(vec2[i], vec2[len - i]);
    // }
    // cout << "result of loop reversal: ";
    // print(vec2);
    // cout << endl;
    // _rotate();
    _rotate_copy();

    return 0;
}
}     // namespace reordingAlgos
#endif     // REORDING_ALGOS_H