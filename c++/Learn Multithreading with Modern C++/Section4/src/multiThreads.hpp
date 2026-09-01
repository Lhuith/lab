#ifndef MULTI_THREADS_H
#define MULTI_THREADS_H

#include <iostream>
#include <thread>
using namespace std;

namespace multiThreads {

void hello(int num) {
    // add a delay
    std::this_thread::sleep_for(std::chrono::seconds(num));
    std::cout << "hello from thread " << num << '\n';
}

int main() {
    // start 3 threads
    std::cout << "starting 3 threads\n";
    std::thread thr1(hello, 1);
    std::thread thr2(hello, 2);
    std::thread thr3(hello, 3);

    // wait for the threads to finish
    thr1.join();
    thr2.join();
    thr3.join();

    return 0;
}
}     // namespace multiThreads
#endif     // MULTI_THREADS_H