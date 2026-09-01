#ifndef DOUBLE_CHECKED_LOCKING_H
#define DOUBLE_CHECKED_LOCKING_H

#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

namespace doubleCheckedLocking {

class Test {
    // ...
   public:
    Test() {
        std::cout << "Test constructor called\n";
    }

    void func() {
        /* ... */
    }
};

Test* ptest = nullptr;         // variable to be lazily initialzed
std::once_flag ptest_flag;     // the flag stores syncronization data

void process() {
    // // pass a callable object with performs the initialization
    // std::call_once(ptest_flag, []() {
    //     ptest = new Test;
    // });
    // ptest->func();

    // meyers singleton
    static Test ptest;     // variable which is lazily initalized
    ptest.func();
}

int main() {
    std::thread thr1(process);
    std::thread thr2(process);

    thr1.join();
    thr2.join();

    return 0;
}
}     // namespace doubleCheckedLocking
#endif     // DOUBLE_CHECKED_LOCKING_H