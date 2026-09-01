#ifndef MANAGING_THREAD_H
#define MANAGING_THREAD_H

#include <iostream>
#include <thread>

using namespace std;

namespace managingThread {

class thread_guard {
    std::thread thr;

   public:
    // constructor takes rvalue reference argument (std::thread is move-only)
    explicit thread_guard(std::thread&& thr) : thr(std::move(thr)) {}

    // destructor - join the thread if necessary
    ~thread_guard() {
        if (thr.joinable())
            thr.join();
    }

    thread_guard(const thread_guard&) = delete;     // deleted copy operators
    thread_guard& operator=(const thread_guard&) = delete;

    //  the move assignment is not synthesized
};

// callable object - thread entry point
void hello() {
    std::cout << "Hello, Thread!\n";
}

void threadGuarding() {
    try {
        std::thread thr(hello);
        thread_guard tguard{std::move(thr)};

        // thread_guard tgaurd{std::thread(hello)};

        // code which might throw an exception
        // throw std::exception();
    }     // calls ~thread_guard() followed by ~thread()
    catch (std::exception& e) {
        std::cout << "exception caught: " << e.what() << '\n';
    }
}

int main() {
    // // create an std::thread object
    // std::thread thr(hello);
    // try {
    //     // code that might throw an exception
    //     // throw std::exception();

    //     // no exception if we got here - call join() as usual
    //     thr.join();

    // } catch (std::exception& e) {
    //     std::cout << "exception caught: " << e.what() << '\n';
    //     thr.join();     // call join() before thr's destructor is called
    // }
    threadGuarding();

    return 0;
}     // calls ~thr()
}     // namespace managingThread
#endif     // MANAGING_THREAD_H