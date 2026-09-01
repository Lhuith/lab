#ifndef MUTEX_CLASS_H
#define MUTEX_CLASS_H

#include <chrono>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

using namespace std;

namespace mutexClass {

using namespace std::literals;
// global mutex object
std::mutex the_mutex;

// void task(const std::string& str) {
//     for (int i = 0; i < 5; ++i) {
//         // lock the mutex before the critical section
//         task_mutex.lock();

//         // start of critical section
//         std::cout << str[0] << str[1] << str[2] << std::endl;
//         // end of critical section

//         // unlock the mutex after the critical section
//         task_mutex.unlock();
//     }
// }

void task1() {
    std::cout << "task1 trying to lock the mutex" << std::endl;
    the_mutex.lock();
    std::cout << "task1 has locked the mutex" << std::endl;
    std::this_thread::sleep_for(500ms);
    std::cout << "task1 unlocking the mutex" << std::endl;
    the_mutex.unlock();
}

void task2() {
    std::this_thread::sleep_for(100ms);
    std::cout << "task2 trying to lock the mutex" << std::endl;
    while (!the_mutex.try_lock()) {
        std::cout << "task2 could not lock the mutex" << std::endl;
        std::this_thread::sleep_for(100ms);
    }
    std::cout << "task2 has locked the mutex" << std::endl;
    the_mutex.unlock();
}

int main() {
    // std::thread thr1(task, "abc");
    // std::thread thr2(task, "def");
    // std::thread thr3(task, "xyz");

    // thr1.join();
    // thr2.join();
    // thr3.join();

    std::thread thr1(task1);
    std::thread thr2(task2);

    thr1.join();
    thr2.join();

    return 0;
}
}     // namespace mutexClass
#endif     // MUTEX_CLASS_H