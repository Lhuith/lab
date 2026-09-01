#ifndef TIMEOUTS_MUTEX_H
#define TIMEOUTS_MUTEX_H

#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

namespace timeoutsMutex {

// std::recursive_mutex rmut;

// int bad_factorial(int n) {
//     if (n <= 1) {
//         std::cout << "returning " << 1 << '\n';
//         return 1;
//     }

//     std::lock_guard<std::recursive_mutex> lck_guard(rmut);
//     // rmut.lock();

//     // start of the critical section
//     int retval = n * bad_factorial(n - 1);
//     std::cout << "returning " << retval << std::endl;
//     // end of critical section

//     // rmut.unlock();
//     return retval;
// }

using namespace std::literals;

std::timed_mutex the_mutex;

void task1() {
    std::cout << "task1 trying to lock the mutex\n";
    // the_mutex.lock();
    std::lock_guard<std::timed_mutex> lck_guard(the_mutex);
    std::cout << "task1 locks the mutex\n";
    std::this_thread::sleep_for(5s);
    std::cout << "task1 unlocking the mutex\n";
    the_mutex.unlock();
}

void task2() {
    std::this_thread::sleep_for(500ms);
    std::cout << "task2 trying to lock the mutex\n";
    // auto deadline = std::chrono::system_clock::now() + 900ms;

    std::unique_lock<std::timed_mutex> uniq_lck(the_mutex, std::defer_lock);

    while (!uniq_lck.try_lock_for(1s)) {
        // try for 1 second to lock the mutex
        // while (!the_mutex.try_lock_for(1s)) {

        // returned false
        // deadline = std::chrono::system_clock::now() + 900ms;
        std::cout << "task2 could not lock the mutex\n";

        // try again on the next iteration
    }

    // returned true - the mutex is now locked

    // start of the critical section
    std::cout << "task2 has locked the mutex\n";
    // end of the critical section

    // the_mutex.unlock();
}

int main() {
    // std::thread thr1(bad_factorial, 10);
    // std::thread thr2(bad_factorial, 11);

    // thr1.join();
    // thr2.join();

    std::thread thr1(task1);
    std::thread thr2(task2);

    thr1.join();
    thr2.join();

    return 0;
}
}     // namespace timeoutsMutex
#endif     // TIMEOUTS_MUTEX_H
