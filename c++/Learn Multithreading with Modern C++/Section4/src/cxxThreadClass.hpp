#ifndef CXX_THREAD_CLASS_H
#define CXX_THREAD_CLASS_H

#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

namespace cxxThreadClass {

// void hello() {
//     using namespace std::literals;
//     std::this_thread::sleep_for(1s);
//     std::cout << "Hello, Thread!\n";
// }

// // function taking a thread object as argument
// // the object must be moved into the argument
// void func(std::thread&& thr) {
//     std::cout << "received thread with ID " << thr.get_id() << std::endl;

//     // the function argument now "owns" the system thread
//     // it is responsible for calling join()
//     thr.join();
// }

// // task function for the thread
// void hello() {
//     std::cout << "Hello, Thread!\n";
// }

// // function returning a std::thread_object
// std::thread func() {
//     // start the thread
//     std::thread thr(hello);

//     // return a local variable
//     return thr;
//     // return a temporary object
//     // return std::thread(hello)
// }

// task function
void hello() {
    // try {
    //     // throw an exception
    //     throw std::exception();
    // } catch (std::exception& e) {
    //     std::cout << "exception caught: " << e.what() << '\n';
    // }

    throw std::exception();
    std::cout << "Hello, Thread!\n";
}

int main() {
    // // std::thread is move-only object
    // std::thread thr(hello);

    // // display the child thread's ID
    // std::cout << "hello thread has ID " << thr.get_id() << '\n';

    // // pass a named object using std::move()
    // func(std::move(thr));

    // pass a temporary object
    // func(std::thread(hello));
    // thr.join();

    // // call a function which returns an std::thread object
    // std::thread thr = func();
    // std::cout << "received thread with ID " << thr.get_id() << '\n';

    // // our thr object now "owns" the system thread
    // // it is responsible for calling join()
    // thr.join();

    // // create a std::thread object
    // std::thread thr(hello);
    // thr.join();

    // create a std::thread object
    try {
        std::thread thr{hello};
        thr.join();
    } catch (std::exception& e) {
        std::cout << "exception caught" << e.what() << '\n';
    }

    // check that the program is still running
    std::cout << "finished\n";

    return 0;
}
}     // namespace cxxThreadClass
#endif     // CXX_THREAD_CLASS_H