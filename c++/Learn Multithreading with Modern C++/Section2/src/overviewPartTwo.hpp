#ifndef OVERVIEW_PART_TWO_H
#define OVERVIEW_PART_TWO_H

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace overviewPartTwo {

void lamPredicate() {
    std::vector<int> vec{4, 2, 3, 5, 1};
    std::cout << "elements of a vector: ";

    for (auto i : vec)
        std::cout << i << ", ";
    std::cout << '\n';

    int radix = 3;

    // call std::count_if() algorithm using a lambda expression as a predicate
    auto n_even = std::count_if(vec.begin(), vec.end(),
                                // the lambda definition goes inside the call!
                                [radix](int n) { return (n % radix == 0); });
    std::cout << "the vector has " << n_even << " element(s) which are exact multiples of " << radix << '\n';
}

void capture() {
    int n = 2;

    // captures the local variable n by reference
    [&n](int arg) { return (++n * arg); }(3);

    std::cout << "n = " << n << '\n';
}

int main() {
    // // c++14, the compiler can deduce the return type
    // [](int arg) { return 2 * arg; };

    // // in c++11, it must be specified with a trailing return type
    // //[](int arg)->{arg = 2 * arg; return arg;};

    // // a lambda expression is callable object
    // // it can be invoked by putting () after the body, with any arguments
    // [](int arg) { return 2 * arg; }(3);

    // // a lambda expression can before stored in a variable of the type "auto"
    // auto lam = [](int arg) { return 2 * arg; };

    // std::cout << "calling lam with arguments 3\n";
    // std::cout << "return " << lam(3) << '\n';

    // capture();
    lamPredicate();

    return 0;
}
}     // namespace overviewPartTwo
#endif     // OVERVIEW_PART_TWO_H