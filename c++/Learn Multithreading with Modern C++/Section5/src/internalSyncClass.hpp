#ifndef INTERNAL_SYNC_CLASS_H
#define INTERNAL_SYNC_CLASS_H

#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

namespace internalSyncClass {

using namespace std::literals;

class Vector {
    std::mutex mut;
    std::vector<int> vec;

   public:
    void push_back(const int& i) {
        mut.lock();

        // start of critical section
        vec.push_back(i);
        // end of critical section

        mut.unlock();
    }

    void print() {
        mut.lock();
        // start of critical section
        for (auto i : vec)
            std::cout << i << ", ";
        std::cout << '\n';
        // end of critical section
        mut.unlock();
    }
};

void func(Vector& vec) {
    for (int i = 0; i < 5; ++i) {
        vec.push_back(i);
        std::this_thread::sleep_for(50ms);
        vec.print();
    }
}

int main() {
    Vector vec;

    std::thread thr1(func, std::ref(vec));
    std::thread thr2(func, std::ref(vec));
    std::thread thr3(func, std::ref(vec));

    thr1.join();
    thr2.join();
    thr3.join();

    return 0;
}
}     // namespace internalSyncClass
#endif     // INTERNAL_SYNC_CLASS_H