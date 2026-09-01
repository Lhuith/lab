#ifndef ASSIGNMENT5_H
#define ASSIGNMENT5_H

#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

namespace assignment5 {

class Test {
    // ...
   public:
    Test() { std::cout << "constructor called\n"; }
    void func(const std::thread::id& id) { std::cout << "thread " << id << " called func()" << '\n'; }
};

std::atomic<Test*> ptr{nullptr};     // variable to be lazily initialized
std::mutex mut;

void process() {
    if (!ptr) {
        std::lock_guard<std::mutex> lck_grd(mut);     // protect ptest

        if (!ptr)
            ptr = new Test;     // initialize it
    }
    Test* aTestPtr = ptr;
    aTestPtr->func(this_thread::get_id());     // use it
}     // lck_grd ~() called/unlocks

int main() {
    std::thread thr1(process);
    std::thread thr2(process);
    std::thread thr3(process);
    std::thread thr4(process);

    thr1.join();
    thr2.join();
    thr3.join();
    thr4.join();

    return 0;
}

}     // namespace assignment5
#endif     // ASSIGNMENT5_H