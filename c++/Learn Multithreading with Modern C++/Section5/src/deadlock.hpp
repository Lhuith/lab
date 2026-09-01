#ifndef DEADLOCK_H
#define DEADLOCK_H

#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

namespace deadlock {

using namespace std::literals;

std::mutex mut1;
std::mutex mut2;

void funcA() {
    std::cout << "thread A trying to lock mutex 1...\n";
    std::lock_guard<std::mutex> lck_guard(mut1);     // acquire lock on mut1
    std::cout << "thread A has locked mutex 1\n";
    std::this_thread::sleep_for(50ms);     // do some work
    std::cout << "thread A trying to lock mutex 2 ...\n";
    std::lock_guard<std::mutex> lck_guard2(mut2);     // wait for lock on mut2
    std::cout << "thread A has locked mutex 2\n";
    std::this_thread::sleep_for(50ms);     // do some work
    std::cout << "thread A releases all its locks\n";
}

void funcB() {
    std::cout << "thread B trying to lock mutex 1..\n";
    std::lock_guard<std::mutex> lck_guard(mut1);     // acquire lock on mut1
    std::cout << "thread B has locked mutex 1\n";
    std::this_thread::sleep_for(50ms);     // do some work
    std::cout << "thread B trying to lock mutex 2 ...\n";
    std::lock_guard<std::mutex> lck_guard2(mut2);     // wait for lock on mut2
    std::cout << "thread B has locked mutex 2\n";
    std::this_thread::sleep_for(50ms);     // do some work
    std::cout << "thread B releases all its locks\n";
}

int main() {
    std::thread thrA(funcA);
    std::thread thrB(funcB);

    thrA.join();
    thrB.join();

    return 0;
}
}     // namespace deadlock
#endif     // DEADLOCK_H