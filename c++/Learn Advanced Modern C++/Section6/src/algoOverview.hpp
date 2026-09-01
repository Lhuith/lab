#ifndef ALGO_OVERVIEW_H
#define ALGO_OVERVIEW_H

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

namespace algoOverview {

int main() {
    string str{"Hello world"};
    cout << "string: ";

    for (const auto& c : str)
        cout << c << ", ";
    cout << "\n";

    auto res = find(cbegin(str), cend(str), 'l');     // search string for first occurrence of 'l';

    // check if we found it
    if (res != cend(str)) {
        // access the result
        cout << "found a matching element at index: " << res - str.cbegin() << endl;
    }

    cout << "at this point in the string: ";
    for (auto it = res; it != str.cend(); ++it)
        cout << *it;
    cout << endl;

    return 0;
}
}     // namespace algoOverview
#endif     // ALGO_OVERVIEW_H