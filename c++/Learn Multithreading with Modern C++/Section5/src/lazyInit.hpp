#ifndef LAZY_INIT_H
#define LAZY_INIT_H

#include <iostream>
#include <mutex>

using namespace std;

namespace lazyInit {

class Test {
    // ...
   public:
    void func() { /* ... */ }
};

Test *ptest = nullptr;     // variable to be lazily initialized
std::mutex mut;

void process() {
    std::unique_lock<std::mutex> uniq_lck(mut);     // protect ptest

    if (!ptest)               // first time variable has been used
        ptest = new Test;     // initialize it
    uniq_lck.unlock();
    ptest->func();     // use it
}

int main() {
    cout << "helo from lazyInit\n";
    return 0;
}
}     // namespace lazyInit
#endif     // LAZY_INIT_H