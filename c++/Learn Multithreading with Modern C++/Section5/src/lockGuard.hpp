#ifndef LOCK_GUARD_H
#define LOCK_GUARD_H

#include <chrono>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

using namespace std;

namespace lockGuard {

using namespace std::literals;

std::mutex task_mutex;     // global mutex object

void task(const std::string& str) {
    for (int i = 0; i < 5; ++i) {
        try {
            // lock the mutex before the critical section
            // task_mutex.lock();
            std::lock_guard<std::mutex> lock_guard(task_mutex);

            // start of critical section
            std::cout << str[0] << str[1] << str[2] << std::endl;

            // critical section threw an exception
            // throw std::exception();
            // end of critical section

            // never gets called
            // task_mutex.unlock();
            std::this_thread::sleep_for(50ms);
        }     // calls ~std::lock_guard()
        catch (std::exception& e) {
            std::cout << "exception caught: " << e.what() << '\n';
        }
    }
}

int main() {
    std::thread thr1(task, "abc");
    std::thread thr2(task, "def");
    std::thread thr3(task, "xyz");

    thr1.join();
    thr2.join();
    thr3.join();

    return 0;
}
}     // namespace lockGuard
#endif     // LOCK_GUARD_H