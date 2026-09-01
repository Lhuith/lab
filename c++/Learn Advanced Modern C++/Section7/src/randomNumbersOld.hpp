#ifndef RANDOM_NUMBERS_OLD_H
#define RANDOM_NUMBERS_OLD_H

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

namespace randomNumbersOld {
int main() {
    // // print out pseudo-random integer
    // cout << "printing out a random number ...";
    // cout << rand() << endl;

    srand(time(0));     // seeding rand() using current time as seed

    // print out a pseudo-random floating-point number with value between 0 and 1
    cout << 1.0 * rand() / RAND_MAX << endl;     // convert the result to double!

    // print out ten pseudo-random integers with value between 1 and 100
    for (int i = 0; i < 10; ++i)
        cout << (99 * rand() / RAND_MAX + 1) << endl;

    return 0;
}
}     // namespace randomNumbersOld
#endif     // RANDOM_NUMBERS_OLD_H