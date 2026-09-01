#ifndef LOCK_FREE_PROG_PRAC_H
#define LOCK_FREE_PROG_PRAC_H

#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

namespace lockFreeProgPrac {

class Test {
    // ...
   public:
    void func() { /*...*/ }
};

std::atomic<Test *> ptest = nullptr;     // variable to be lazily initialized
std::mutex mut;

void process() {     // double checked locking
    // first check of ptest
    if (!ptest) {
        // ---- thread could interleave here

        std::lock_guard<std::mutex> lck_guard(mut);

        // second check of ptest
        if (!ptest) {
            // initialize ptest
            ptest = new Test;
        }
    }

    // atomic pointers cannot be dereferenced
    // copy it to a non-atomic point first
    Test *ptr_test = ptest;
    ptr_test->func();
}

int main() {
    std::vector<std::thread> threads;

    for (int i = 0; i < 10; ++i)
        threads.push_back(std::thread(process));

    for (auto &thr : threads)
        thr.join();

    return 0;
}
}     // namespace lockFreeProgPrac
#endif     // LOCK_FREE_PROG_PRAC_H