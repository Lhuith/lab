#ifndef OVERVIEW_PART_FOUR_H
#define OVERVIEW_PART_FOUR_H

#include <iostream>
#include <utility>

using namespace std;

namespace overviewPartFour {

// define a movable type
// (the compiler will provide move operators)
// class Test {};

// // function which takes lvalue reference
// void func(const Test& test) {
//     std::cout << "lvalue reference\n";
// }

// // function which takes revalue reference
// void func(Test&& test) {
//     std::cout << "rvalue reference\n";
// }

// move-only class
class Test {
   public:
    // =delete means the function exists but cannot be called
    // in older c++, we had to delcare the member function private
    Test(const Test&) = delete;
    Test& operator=(const Test&) = delete;

    // =default means the compiler will synthesize
    // the default version of the operator
    Test(Test&&) noexcept = default;
    Test& operator=(Test&&) noexcept = default;

    Test() = default;
};

int main() {
    // Test test;

    // std::cout << "argument is test variable:\t\t";
    // func(test);

    // std::cout << "argument is temporary object:\t\t";
    // func(Test());

    // std::cout << "argument is through std::move():\t\t";
    // func(std::move(test));
    // std::cout << '\n';

    Test test1, test2, test3;
    // Test test4(test1);
    // test2 = test1;
    Test test4(std::move(test1));
    test3 = std::move(test2);

    return 0;
}
}     // namespace overviewPartFour
#endif     // OVERVIEW_PART_FOUR_H