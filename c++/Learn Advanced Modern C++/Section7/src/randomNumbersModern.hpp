#ifndef RANDOM_NUMBERS_MODERN_H
#define RANDOM_NUMBERS_MODERN_H

#include <iostream>
#include <random>

using namespace std;

namespace randomNumbersModern {

void _m19937() {
    mt19937 mt;     // create engine object - generates sequence

    uniform_int_distribution<int> idist(0, 10);     // we want ints in the range 0 to 100 (inclusive)

    cout << "five random integers between 0 and 10:\n";
    for (int i = 0; i < 5; ++i)
        cout << idist(mt) << ", ";     // call the functor to get the next number

    cout << endl
         << endl;

    uniform_real_distribution<double> fdist(0, 10);     // doubles in the rand 0 to 10

    cout << "five random floating-point numbers between 0 and 10:\n";
    for (int i = 0; i < 5; ++i)
        cout << fdist(mt) << ", ";
    cout << endl;
}

int main() {
    // default_random_engine eng;     // create engine object - generates sequence

    // cout << "five random integers\n";
    // for (int i = 0; i < 5; ++i)
    //     cout << eng() << ", ";     // call the functor to get the next number
    // cout << endl;
    _m19937();

    return 0;
}
}     // namespace randomNumbersModern
#endif     //
