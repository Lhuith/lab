#ifndef ATOMIC_OPS_H
#define ATOMIC_OPS_H

#include <atomic>
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

namespace atomicOps {

// the atomic_flag must be initalized as false
std::atomic_flag lock_cout = ATOMIC_FLAG_INIT;
std::mutex mut;
void task(int n) {
    // test_and_set()
    // returns true if another thread set the flag
    // returns false if this thread set the flag
    while (lock_cout.test_and_set()) {
    }     // spin lock

    // start of critical section
    // do some work
    using namespace std::literals;
    std::this_thread::sleep_for(50ms);
    std::cout << "I'm a task with argument " << n << '\n';
    // end of critical section

    // clear the flag, so another thread can set it
    lock_cout.clear();
}

void taskMute(int n) {
    // // test_and_set()
    // // returns true if another thread set the flag
    // // returns false if this thread set the flag
    // while (lock_cout.test_and_set()) {
    // }     // spin lock

    std::lock_guard<std::mutex> lg(mut);

    // start of critical section
    // do some work
    using namespace std::literals;
    std::this_thread::sleep_for(50ms);
    std::cout << "I'm a task with argument " << n << '\n';
    // end of critical section

    // clear the flag, so another thread can set it
    lock_cout.clear();
}

int main() {
    // std::atomic<int> x = 0;
    // std::cout << "after initialization: x = " << x << '\n';

    // // atomic assignment to x
    // x = 2;

    // // atomic assignment from x. y can be non-atomic
    // int y = x;

    // std::cout << "after assignment: x = " << x << ", y = " << y << '\n';

    // x.store(3);
    // std::cout << "after store: x = " << x.load() << '\n';

    // std::cout << "exchange returns " << x.exchange(y) << '\n';
    // std::cout << "after exchange: x = " << x << ", y = " << y << '\n';

    std::vector<std::thread> threads;

    for (int i = 1; i <= 10; ++i)
        threads.push_back(std::thread(task, i));

    for (auto &thr : threads)
        thr.join();

    return 0;
}
}     // namespace atomicOps
#endif     // ATOMIC_OPS_H