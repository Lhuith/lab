#ifndef SYSTEM_THREAD_INTERFACE_H
#define SYSTEM_THREAD_INTERFACE_H

#include <iostream>
#include <thread>

using namespace std;
using namespace std::literals;

namespace systemThreadInterface {

// task function
void hello() {
    // std::cout << "Hello from thread with ID " << std::this_thread::get_id() << '\n';

    // std::this_thread::sleep_for(std::chrono::seconds(2));
    std::this_thread::sleep_for(2s);
    std::cout << "Hello, Thread!\n";
}

int main() {
    // // create an std::thread object
    // std::thread thr(hello);

    // // display the child thread's native handle
    // std::cout << "hello thread has native handle " << thr.native_handle() << '\n';

    // // wait for the thread to complete
    // thr.join();

    // // display the child thread's native handle again
    // std::cout << "hello thread has native handle " << thr.native_handle() << '\n';

    // display the main thread's ID
    // std::cout << "main thread has ID " << std::this_thread::get_id() << '\n';

    // // create an std::thread object
    // std::thread thr(hello);

    // // display the child thread's ID
    // std::cout << "Hello thread has ID " << thr.get_id() << '\n';

    // // what for the thread to complete
    // thr.join();

    // // display the child thread's ID again
    // std::cout << "hello thread now has ID " << thr.get_id() << '\n';

    // create an std::thread object
    std::cout << "starting thread ... \n";
    std::thread thr(hello);

    // what for the thread to complete
    thr.join();

    return 0;
}
}     // namespace systemThreadInterface
#endif     // SYSTEM_THREAD_INTERFACE_H