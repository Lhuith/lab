#ifndef THREAD_LOCAL_VAR_H
#define THREAD_LOCAL_VAR_H

#include <iostream>
#include <random>
#include <thread>

using namespace std;

namespace threadLocalVar {

// thread-local random number engine
std::mt19937 mt;

void func() {
    std::uniform_real_distribution<double> dist(0, 1);     // doubles in the range 0 to 1;

    for (int i = 0; i < 10; ++i)     // generate 10 random numbers
        std::cout << dist(mt) << ", ";
    std::cout << std::endl;
}

int main() {
    std::cout << "thread 1's random values:\n";
    std::thread thr1(func);
    thr1.join();
    std::cout << "thread 2's random values:\n";
    std::thread thr2(func);
    thr2.join();
    std::cout << '\n';

    return 0;
}
}     // namespace threadLocalVar
#endif     // THREAD_LOCAL_VAR_H