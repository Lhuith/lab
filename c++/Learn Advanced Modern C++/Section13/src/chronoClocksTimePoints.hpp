#ifndef CHRONO_CLOCKS_TIME_POINTS_H
#define CHRONO_CLOCKS_TIME_POINTS_H

#include <chrono>
#include <iostream>
#include <thread>

using namespace std;
using namespace std::chrono;

namespace chronoClocksTimePoints {

long long fibonacci(long long n) {
    return (n < 2) ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

void _sleep() {
    cout << "waiter!" << endl;
    this_thread::sleep_for(2s);
    cout << "you called, sir?" << endl;
}

int main() {
    // auto start = steady_clock::now();
    // long long n = fibonacci(100);
    // std::cout << "fibonacci number is " << n << std::endl;

    // auto finish = steady_clock::now();

    // auto elapsed = duration_cast<milliseconds>(finish - start).count();
    // std::cout << "time taken: " << elapsed << " milliseconds" << std::endl;

    _sleep();

    return 0;
}
}     // namespace chronoClocksTimePoints
#endif     // CHRONO_CLOCKS_TIME_POINTS_H