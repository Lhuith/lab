#ifndef CXX_DECLTYPE_H
#define CXX_DECLTYPE_H

#include <iostream>
#include <vector>

using namespace std;

namespace cxxDecltype {

class Test {};

// return the sum of two arguments of any type
template <typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
    return t + u;
};

// return a vector of n elements, initalized with value x
auto make_vector = [](auto x, size_t n) {
    return vector<decltype(x)>(n, x);
};

int main() {
    // size_t x = 10;
    // for (decltype(x) i{}; i < x; ++i) {
    //     // cout << "decltype rocks" << endl;
    // }

    // const int x{42};
    // // cout << x;
    // auto y = x;           // the type of y is int
    // decltype(x) z{0};     // the type of z is const int

    // cout << "y = " << y << ", z = " << z << endl;
    // ++y;
    // // ++z;     // error!
    // cout << "y = " << y << ", z = " << z << endl;

    // int x{42};

    // // decltype with lvalue variable
    // decltype(x) y{0};     // the type of y is int

    // // decltype with lvalue expression
    // decltype((x)) p{x};     // the type of p is lvalue reference to int

    // // decltype with prvalue
    // decltype(42) z;     // the type of z is int

    // // decltype with xvalue expression
    // decltype(Test()) t;     // the type of t is Test&&

    // const int a{99};          // the type of a is const int
    // auto b = a;               // the type of b is int
    // decltype(auto) c = a;     // the type of c is const int

    // cout << "b = " << b << ", c = " << c << endl;
    // ++b;
    // // ++c;     // error!
    // cout << "b = " << b << ", c = " << c << endl;

    cout << "add(2, 3) => " << add(2, 3) << endl;
    cout << R"(add("Hello", 2) => )" << add("Hello", 2) << endl;

    cout << R"(make_vector(2, 3) => )";
    auto vint = make_vector(2, 3);
    for (auto i : vint)
        cout << i << ", ";
    cout << endl;

    cout << R"(make_vector("Hello", 2) => )";
    auto vstr = make_vector("Hello", 2);
    for (auto s : vstr)
        cout << s << ", ";
    cout << endl;

    return 0;
}
}     // namespace cxxDecltype
#endif     // CXX_DECLTYPE_H