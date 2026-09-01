#ifndef SHARED_DATA_INIT_H
#define SHARED_DATA_INIT_H

#include <iostream>
#include <thread>
#include <vector>

#include "singleton.hpp"

// Singleton* Singleton::single = nullptr;

using namespace std;

namespace sharedDataInit {

void task() {
    Singleton& single = get_Singleton();
    std::cout << &single << std::endl;
}

int main() {
    std::vector<std::thread> threads;

    for (int i = 0; i < 10; ++i)
        threads.push_back(std::thread(task));

    for (auto& thr : threads)
        thr.join();

    return 0;
}
}     // namespace sharedDataInit
#endif     // SHARED_DATA_INIT_H