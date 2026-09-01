#ifndef REMOVE_ALGOS_CONT_H
#define REMOVE_ALGOS_CONT_H

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace removeAlgosCont {

void _unique_copy_pred() {
    vector<int> vec{3, 1, 4, 1, 5, 9};

    cout << "original vector: ";
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;

    // sort the vector that duplicate elements are adjacent to each other
    sort(begin(vec), end(vec));

    cout << "sorted vector: ";
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;

    vector<int> vec2;
    unique_copy(cbegin(vec), cend(vec), back_inserter(vec2),
                [](int m, int n) { return (n == m + 1); });

    cout << "result of calling unique_copy_predicate: ";
    for (auto v : vec2)
        cout << v << ", ";
    cout << endl;
}

void _unique_copy() {
    vector<int> vec{3, 1, 4, 1, 5, 9};

    cout << "original vector: ";
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;

    // sort the vector that duplicate elements are adjacent to each other
    sort(begin(vec), end(vec));

    cout << "sorted vector: ";
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;

    vector<int> vec2;
    unique_copy(cbegin(vec), cend(vec), back_inserter(vec2));

    cout << "result of calling unique_copy: ";
    for (auto v : vec2)
        cout << v << ", ";
    cout << endl;
}

void _unique_pred() {
    vector<int> vec{3, 1, 4, 1, 5, 9};

    cout << "original vector: ";
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;

    // sort the vector so that duplicate elements are adjacent to each other
    sort(begin(vec), end(vec));

    cout << "sorted vector: ";
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;

    cout << "before calling unique, the vector has " << vec.size() << " elements\n";

    // if an element is great by 1 than the previous element, remove it
    auto defunct = unique(begin(vec), end(vec),
                          [](int m, int n) { return (n == m + 1); });

    vec.erase(defunct, end(vec));
    cout << "result of calling unique and erase: ";
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;
}

void _unique() {
    vector<int> vec{3, 1, 4, 1, 5, 9};

    cout << "original vector: ";
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;

    // sort the vector so that duplicate elements are adjacent to each other
    sort(begin(vec), end(vec));

    cout << "sorted vector: ";
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;

    cout << "before calling unique, the vector has " << vec.size() << " elements\n";

    auto defunct = unique(begin(vec), end(vec));

    cout << "before calling erase, the vector has " << vec.size() << " elements\n";
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;

    vec.erase(defunct, end(vec));

    cout << "after calling erase, the vector has " << vec.size() << " elements\n";
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;
}

void _remove_copy_if() {
    vector<int> vec{3, 1, 4, 1, 5, 9};

    cout << "original vector: ";
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;

    vector<int> vec2;
    remove_copy_if(cbegin(vec), cend(vec), back_inserter(vec2),
                   [](int n) { return (n % 3 == 0); });

    cout << "result of remove_copy: ";
    for (auto v : vec2)
        cout << v << ", ";
    cout << endl;

    // can be written using copy_if with the predicate inverted
    vector<int> vec3;
    copy_if(cbegin(vec), cend(vec), back_inserter(vec3),
            [](int n) { return (n % 3 != 0); });

    cout << "results of copy_if: ";
    for (auto v : vec3)
        cout << v << ", ";
    cout << endl;
}

void _remove_copy() {
    vector<int> vec{3, 1, 4, 1, 5, 9};

    cout << "original vector: ";
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;

    vector<int> vec2;
    remove_copy(cbegin(vec), cend(vec), back_inserter(vec2), 1);

    cout << "result of remove_copy: ";
    for (auto v : vec2)
        cout << v << ", ";
    cout << endl;

    // can be written using copy_if with the predicate inverted
    vector<int> vec3;
    copy_if(cbegin(vec), cend(vec), back_inserter(vec3),
            [](int n) { return n != 1; });

    cout << "results of copy_if: ";
    for (auto v : vec3)
        cout << v << ", ";
    cout << endl;
}

int main() {
    // vector<int> vec{3, 1, 4, 1, 5, 9};

    // cout << "original vector: ";
    // for (auto v : vec)
    //     cout << v << ", ";
    // cout << endl;

    // auto defunct = remove_if(begin(vec), end(vec),
    //                          [](int n) { return (n % 3 == 0); });

    // // destroy the removed elements
    // vec.erase(defunct, end(vec));

    // cout << "result of calling remove if and erase: ";
    // for (auto v : vec)
    //     cout << v << ", ";
    // cout << endl;
    // _remove_copy();
    // _remove_copy_if();
    // _unique();
    // _unique_pred();
    // _unique_copy();
    _unique_copy_pred();

    return 0;
}
}     // namespace removeAlgosCont
#endif     // REMOVE_ALGOS_CONT_H