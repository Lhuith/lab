#ifndef FOR_EACH_ALGOS_H
#define FOR_EACH_ALGOS_H

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

namespace forEachAlgos {
int main() {
    // print each character in str on a separate line
    string str{"a test string"};

    cout << "with for_each: ";
    for_each(cbegin(str), cend(str),
             [](const char c) { cout << c << ", "; });

    // range for loop
    cout << "\nwith range for loop: ";
    for (auto c : str)
        cout << c << ", ";
    cout << endl;

    // character by reference
    string str2{str};
    cout << "str: " << str2 << endl;

    cout << "with for_each: ";
    // convert each element in str to upper case
    for_each(begin(str), end(str),
             [](char& c) { c = toupper(c); });
    cout << "str: " << str;

    cout << "\nwith range for loop: ";
    string str3{"a test string"};
    for (auto& c : str3)
        c = toupper(c);
    cout << str3 << endl;
    cout << endl;

    return 0;
}
}     // namespace forEachAlgos
#endif     // FOR_EACH_ALGOS_H