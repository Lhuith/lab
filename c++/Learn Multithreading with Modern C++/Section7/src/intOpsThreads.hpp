#ifndef INT_OPS_THREADS_H
#define INT_OPS_THREADS_H

#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

namespace intOpsThreads {

std::mutex mut;

std::atomic<int> counter = 0;

void task() {
    for (int i = 0; i < 100'000; ++i) {
        // std::lock_guard<std::mutex> lck_guard(mut);
        ++counter;
    }
}

int main() {
    std::vector<std::thread> tasks;

    for (int i = 0; i < 10; ++i)
        tasks.push_back(std::thread(task));

    for (auto& thr : tasks)
        thr.join();

    std::cout << counter << '\n';

    return 0;
}
}     // namespace intOpsThreads
#endif     // INT_OPS_THREADS_H