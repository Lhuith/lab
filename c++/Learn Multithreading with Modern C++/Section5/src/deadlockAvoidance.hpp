#ifndef DEADLOCK_AVOIDANCE_H
#define DEADLOCK_AVOIDANCE_H

#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

namespace deadlockAvoidance {

using namespace std::literals;

std::mutex mut1;
std::mutex mut2;

void funcA() {
    std::unique_lock<std::mutex> uniq_lk1(mut1, std::defer_lock);     // associate mutex with lock ...
    std::unique_lock<std::mutex> uniq_lk2(mut2, std::defer_lock);     // ... but don't lock it yet

    std::cout << "thread A trying to lock mutexes 1 and 2 ... \n";
    // // std::scoped_lock scoped_lck(mut1, mut2);
    // std::lock(uniq_lk1, uniq_lk2);     // lock both mutexes
    // std::cout << "thread A has locked mutexes 1 and 2\n";
    // // adopt the locks
    // // std::unique_lock<std::mutex> uniq_lk1(mut1, std::adopt_lock);     // associate each mutex
    // // std::unique_lock<std::mutex> uniq_lk2(mut2, std::adopt_lock);     // with a unique lock
    // // std::cout << "thread A has adopted the locks\n";

    // std::this_thread::sleep_for(50ms);
    // std::cout << "thread A releasing mutexes 1 and 2 ... \n";

    auto idx = std::try_lock(uniq_lk1, uniq_lk2);
    if (idx != -1) {
        std::cout << "try_lock failed on mutex with index " << idx << '\n';
    } else {
        std::cout << "thread A has locked mutexes 1 and 2\n";
        std::this_thread::sleep_for(50ms);
        std::cout << "thread A releasing mutexes 1 and 2 ...\n";
    }
}

void funcB() {
    std::unique_lock<std::mutex> uniq_lk1(mut1, std::defer_lock);
    std::unique_lock<std::mutex> uniq_lk2(mut2, std::defer_lock);

    std::cout << "thread B trying to lock mutexes 2 and 1...\n";
    // // std::scoped_lock scoped_lck(mut2, mut1);
    // // std::cout << "thread B has locked mutexes 2 and 1\n";
    // std::lock(uniq_lk2, uniq_lk1);     // lock both mutexes
    // std::cout << "thread B has locked mutexes 2 and 1\n";

    // // adopt the locks
    // // std::unique_lock<std::mutex> uniq_lk1(mut1, std::adopt_lock);     // associate each mutex
    // // std::unique_lock<std::mutex> uniq_lk2(mut2, std::adopt_lock);     // with a unique lock
    // // std::cout << "thread B has adopted the locks\n";

    // std::this_thread::sleep_for(50ms);
    // std::cout << "thread B releasing mutexes 2 and 1 ...\n";

    auto idx = std::try_lock(uniq_lk2, uniq_lk1);
    if (idx != -1) {
        std::cout << "try_lock failed on mutex with index " << idx << '\n';
    } else {
        std::cout << "thread B has locked mutexes 1 and 2\n";
        std::this_thread::sleep_for(50ms);
        std::cout << "thread B releasing mutexes 1 and 2 ...\n";
    }
}

int main() {
    std::thread thrA(funcA);
    std::thread thrB(funcB);

    thrA.join();
    thrB.join();

    return 0;
}
}     // namespace deadlockAvoidance
#endif     // DEADLOCK_AVOIDANCE_H