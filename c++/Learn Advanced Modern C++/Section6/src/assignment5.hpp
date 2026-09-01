#ifndef ASSIGNMENT5_H
#define ASSIGNMENT5_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace assignment5 {

template <typename T>
void print_vec(const vector<T>& v) {
    for (const auto& n : v)
        cout << n << ", ";
    cout << "\n";
}

template <typename T>
void sort_vec(vector<T>& v) {
    cout << "before sorting: ";
    print_vec<T>(v);

    sort(begin(v), end(v), [](T a, T b) { return (a > b); });
}

int main() {
    vector<int> num = {1, 2, 3, 4, 5};
    sort_vec<int>(num);

    cout << "after sorting: ";
    print_vec<int>(num);

    return 0;
}
}     // namespace assignment5
#endif     // ASSIGNMENT5_H