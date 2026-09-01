#ifndef OVERVIEW_PART_ONE_H
#define OVERVIEW_PART_ONE_H

#include <iostream>
#include <string>
#include <vector>

// example of intervals in std::chrono
#include <chrono>

using namespace std;
namespace sc = std::chrono;

namespace overviewPartOne {

void _auto() {
    std::vector<int> vec{4, 2, 3, 5, 1};

    // for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    // *it += 2;

    std::cout << "vector elements: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << ", ";
    cout << endl;

    std::cout << "vector elements before: ";
    for (auto i : vec)
        std::cout << i << ", ";
    std::cout << '\n';

    // we need to use a reference to modify the elements
    for (auto& i : vec)
        i += 2;

    std::cout << "vector elements after: ";
    for (auto i : vec)
        std::cout << i << ", ";
    cout << endl;
}

void _chrono() {
    // interval types defined in the std::chrono library
    sc::seconds(2);           // 2 second interval
    sc::milliseconds(20);     // 20 millisecond interval
    sc::microseconds(50);     // 50 microsecond interval

    // literal suffixes added in c++14
    using namespace std::literals;
    2s;
    20ms;
    50us;
}

void func(int i) {
    std::cout << "func(int) called\n";
}

void func(int* i) {
    std::cout << "func(int *i) called\n";
}

void _nullPtr() {
    // func(NULL);
    func(nullptr);
}

int main() {
    // int x{7};                            // equiv to int x = 7
    // std::string str{"let us begin"};     // equiv to string str("Let us begin"s);

    // std::cout << "x = " << x << '\n';
    // std::cout << "str = \"" << str << "\"\n";

    // // narrowing conversions are not allowed
    // int y = 7.7;     // legal although compilers warn
    // // int y{7.7};     // illegal
    // std::cout << "y = " << y << '\n';

    // // can be used with multiple initial values
    // std::vector<int> vec{4, 2, 3, 5, 1};     // std::vector variables with elements 4,2,3,5,1

    // std::cout << "vec = ";
    // for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    //     std::cout << *it << ", ";
    // cout << endl;

    // _nullPtr();
    // _chrono();
    _auto();

    return 0;
}
}     // namespace overviewPartOne
#endif     // OVERVIEW_PART_ONE_H