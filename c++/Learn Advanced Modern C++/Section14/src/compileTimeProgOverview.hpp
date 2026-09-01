#ifndef COMPILE_TIME_PROG_OVERVIEW_H
#define COMPILE_TIME_PROG_OVERVIEW_H

#include <iostream>
#include <type_traits>

using namespace std;

namespace compileTimeProgOverview {

#define Max(x, y) ((x) > (y) ? (x) : (y))
class A {
};

int main() {
    // int a{5}, b{2};
    // std::cout << "a = " << a << ", b = " << b << std::endl;
    // std::cout << "Max(a, b): " << Max(a, b) << std::endl;     // replaced by ((a) > (b) > (a):(b))
    // std::cout << "a = " << a << ", b = " << b << std::endl;
    // std::cout << "Max(++a, b): " << Max(++a, b) << std::endl;     // replaced by((++a) > (b) > (++a):(b))
    // std::cout << "a = " << a << ", b = " << b << std::endl;

    std::cout << std::boolalpha;
    std::cout << "is_arithmetic<int>: " << std::is_arithmetic<int>::value << '\n';                 // true
    std::cout << "is_floating_point<int>: " << std::is_floating_point<int>::value << '\n';         // false
    std::cout << "is_class<A>: " << std::is_class<A>::value << '\n';                               // true
    std::cout << "is_pointer<const char *>: " << std::is_pointer<const char *>::value << '\n';     // true
    std::cout
        << std::noboolalpha;

    return 0;
}
}     // namespace compileTimeProgOverview
#endif     // COMPILE_TIME_PROG_OVERVIEW_H