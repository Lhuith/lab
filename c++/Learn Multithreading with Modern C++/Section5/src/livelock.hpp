#ifndef LIVELOCK_H
#define LIVELOCK_H

#include <chrono>
#include <iostream>
#include <mutex>
#include <random>
#include <string>
#include <thread>

using namespace std;

namespace livelock {

using namespace std::literals;

std::mutex mut1, mut2;
std::mt19937 mt;

void funcA() {
    // uniform_int_distribution<int> uid(0, 1);

    // std::this_thread::sleep_for(10ms);
    // bool locked = false;
    // while (!locked) {
    //     std::lock_guard<std::mutex> lock_guard(mut1);     // lock mut1
    //     string toSay = "";
    //     toSay += "after you, Claude!\n";

    //     std::cout << toSay;

    //     std::this_thread::sleep_for(2s);
    //     locked = mut2.try_lock();     // try to lock mut2
    // }
    // if (locked)
    //     std::cout << "threadA has locked both mutexes\n";

    std::this_thread::sleep_for(10ms);

    std::cout << "after you, Claude!" << std::endl;
    std::scoped_lock scoped_lck(mut1, mut2);     // lock both mutexes
    std::this_thread::sleep_for(2s);
    std::cout << "thread A has locked both mutexes";
}

void funcB() {
    // uniform_int_distribution<int> uid(0, 1);
    // bool locked = false;
    // while (!locked) {
    //     std::lock_guard<std::mutex> lk(mut2);     // lock mut2

    //     string toSay = "";
    //     toSay += "after you, Cecil!\n";

    //     std::cout << toSay;

    //     std::this_thread::sleep_for(2s);
    //     locked = mut1.try_lock();     // try to lock mut1
    // }
    // if (locked)
    //     std::cout << "threadB has locked both mutexes\n";

    std::cout << "after you, Cecil!" << std::endl;
    std::scoped_lock scoped_lck(mut2, mut1);     // lock mutexes
    std::this_thread::sleep_for(2s);
    std::cout << "thread B has locked both mutexes" << std::endl;
}

int main() {
    std::thread thrA(funcA);
    std::this_thread::sleep_for(10ms);
    std::thread thrB(funcB);

    thrA.join();
    thrB.join();

    return 0;
}
}     // namespace livelock
#endif     // LIVELOCK_H