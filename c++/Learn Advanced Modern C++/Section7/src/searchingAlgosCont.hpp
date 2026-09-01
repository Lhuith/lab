#ifndef SEARCHING_ALGOS_CONT_H
#define SEARCHING_ALGOS_CONT_H

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace searchingAlgosCont {

void print_vec(const vector<int>& vec) {
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;
}

void includes() {
    // string str{"Hello world"};
    string str{"Hello includes all"};

    string vowels{"aieou"};

    // sort both the strings;
    sort(begin(str), end(str));
    sort(begin(vowels), end(vowels));

    cout << "string to search: " << str << endl;
    cout << "vowels: " << vowels << endl;

    if (includes(cbegin(str), cend(str), cbegin(vowels), cend(vowels)))
        cout << "string contains all characters from vowels\n";
    else
        cout << "string does not contain all characters from vowels\n";
}

void bin_search() {
    vector<int> vec{3, 1, 4, 1, 5, 9};

    // sort the vector
    sort(begin(vec), end(vec));
    cout << "sorted vector: ";
    print_vec(vec);

    if (binary_search(cbegin(vec), cend(vec), 4))
        cout << "vector contains 4\n";
    else
        cout << "vector does not contain 4\n";

    if (binary_search(cbegin(vec), cend(vec), 8))
        cout << "vector contains 8\n";
    else
        cout << "vector does not contain 8\n";
}

void someof() {
    vector<int> vec{2, 4, 6, 8};

    cout << "vec: ";
    print_vec(vec);

    auto is_odd = [](int n) { return n % 2 == 1; };
    auto is_even = [](int n) { return n % 2 == 0; };

    if (all_of(cbegin(vec), cend(vec), is_odd))
        cout << "all elements of vec are odd\n";

    if (all_of(cbegin(vec), cend(vec), is_even))
        cout << "all elements of vec are even\n";

    if (any_of(cbegin(vec), cend(vec), is_odd))
        cout << "some elements of vec are odd\n";

    if (any_of(cbegin(vec), cend(vec), is_even))
        cout << "some elements of vec are even\n";

    if (none_of(cbegin(vec), cend(vec), is_odd))
        cout << "no elements of vec are odd\n";

    if (none_of(cbegin(vec), cend(vec), is_even))
        cout << "no elements of vec are even\n";
}

int main() {
    // vector<int> vec1{1, 2, 2, 3, 2, 3, 3};
    // vector<int> vec2{1, 2, 2, 2, 2, 3, 3};     // vector differ at their fourth element

    // cout << "vec1: ";
    // print_vec(vec1);
    // cout << "vec2: ";
    // print_vec(vec2);

    // // return a pair of iterators to the first mismatched element in each range
    // auto elems = mismatch(cbegin(vec1), cend(vec1), cbegin(vec2), cend(vec2));

    // // elems is a pair of iterators to the corresponding element in the two vectors
    // if (elems.first != cend(vec1) && elems.second != cend(vec2)) {
    //     cout << "found mismatch at index: " << distance(cbegin(vec1), elems.first) << endl;
    //     cout << "vec1 has " << *elems.first << ", vec2 has " << *elems.second << endl;
    // }

    // someof();
    // bin_search();
    includes();
    return 0;
}
}     // namespace searchingAlgosCont
#endif     // SEARCHING_ALGOS_CONT_H