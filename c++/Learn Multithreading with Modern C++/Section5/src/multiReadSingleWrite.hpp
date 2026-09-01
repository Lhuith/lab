#ifndef MULTI_READ_SINGLE_WRITE_H
#define MULTI_READ_SINGLE_WRITE_H

#include <chrono>
#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include <vector>

using namespace std;

namespace multiReadSingleWrite {

// std::mutex mut;
std::shared_mutex shmut;

// shared variable
int x = 0;

void write() {
    // exclusive lock
    std::lock_guard<std::shared_mutex> lck_guard(shmut);

    // start of critical section
    ++x;
    // end of critical section
}

void read() {
    // shared locking
    std::shared_lock<std::shared_mutex> lck_guard(shmut);

    // start of critical section
    using namespace std::literals;
    std::this_thread::sleep_for(100ms);
    // end of critical section
}

int main() {
    std::vector<std::thread> threads;

    for (int i = 0; i < 20; ++i)
        threads.push_back(std::thread(read));

    threads.push_back(std::thread(write));
    threads.push_back(std::thread(write));

    for (int i = 0; i < 20; ++i)
        threads.push_back(std::thread(read));

    for (auto& thr : threads)
        thr.join();

    return 0;
}
}     // namespace multiReadSingleWrite
#endif     // MULTI_READ_SINGLE_WRITE_H