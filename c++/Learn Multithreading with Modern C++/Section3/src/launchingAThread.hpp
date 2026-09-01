#ifndef LAUNCHING_A_THREAD_H
#define LAUNCHING_A_THREAD_H

#include <iostream>
#include <thread>

using namespace std;

namespace launchingAThread {

// callable object - thread entry point;
void hello() {
    std::cout << "Hello, thread!\n";
}

// functor class with overloaded () operator
class Hello {
   public:
    void operator()() { std::cout << "hello, functor thread!\n"; }
};

int main() {
    // create an std::thread object
    // and pass the task function to the constructor
    // std::thread thr1(hello);
    // std::thread thr2(hello);
    // std::thread thr3(hello);

    // wait for the thread to complete
    // thr1.join();
    // thr2.join();
    // thr3.join();

    // create an object of the functor class
    // Hello hello;

    // pass the functor object to std::threads constructor
    // std::thread thr(hello);

    // pass the lambda expression as the threads entry point
    std::thread thr([]() {
        std::cout << "Hello, Lambda Thread!\n";
    });

    // wait for the thread to complete
    thr.join();

    return 0;
}
}     // namespace launchingAThread
#endif     // LAUNCHING_A_THREAD_H