#ifndef ASSIGNMENT2_H
#define ASSIGNMENT2_H

#include <iostream>
#include <thread>

using namespace std;

namespace assignment2 {

int counter = 0;

void increment() {
    for (int i = 0; i < 100'000; ++i)
        counter++;
}

int main() {
    std::thread thr1(increment);
    std::thread thr2(increment);

    thr1.join();
    thr2.join();

    cout << "final counter value is: " << counter << endl;
    return 0;
}
}     // namespace assignment2
#endif     // ASSIGNMENT2_H