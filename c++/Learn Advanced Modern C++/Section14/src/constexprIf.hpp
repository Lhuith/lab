#ifndef CONSTEXPR_IF_H
#define CONSTEXPR_IF_H

#include <iostream>
#include <string>

using namespace std;

namespace constexprIf {
// template <typename T>
// string get_string(const T& arg) {
//     if constexpr (std::is_same_v<std::string, T>) {     // replaced by "true" if T is a string, else "false"
//         return arg;                                     // error if T is a built-in type
//     } else {
//         return to_string(arg);     // error if t is std::string
//     }
// }

// template function for the general case
// template <typename T>
// string get_string(const T& arg) {
//     return to_string(arg);
// }

// // template specialization for std::string
// template <>
// string get_string(const string& arg) {
//     return arg;
// }

// not instantiated if T is std::string
template <typename T, std::enable_if_t<!std::is_same_v<std::string, T>, int> = 99>
string get_string(const T& arg) {
    return to_string(arg);
}

// instantiated only if T is std::string
template <typename T, std::enable_if_t<std::is_same_v<std::string, T>, int> = 99>
string get_string(const T& arg) {
    return arg;
}

int main() {
    int x{42};
    cout << "x: " << x << endl;
    cout << "get_string(x): " << get_string(x) << endl;
    string str{"hello"};
    cout << "str: " << str << endl;
    cout << "get_string(str): " << get_string(str) << endl;

    return 0;
}
}     // namespace constexprIf
#endif     // CONSTEXPR_IF_H