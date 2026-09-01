#ifndef PACKAGED_TASK_H
#define PACKAGED_TASK_H

#include <chrono>
#include <future>
#include <iostream>
#include <thread>

using namespace std;

namespace packagedTask {

using namespace std::literals;

int main() {
    // packaged task object
    // the callable object is a lambda expression
    // it takes int and int arguments
    // it returns int
    std::packaged_task<int(int, int)> ptask([](int a, int b) {
        std::this_thread::sleep_for(2s);
        return a + b;
    });

    // the promise object us ab std::promise<int>
    // get the future associated with it
    std::future<int> fut = ptask.get_future();

    // invoke the packaged task in this thread
    // ptask(6, 7);
    // start a new thread
    // the packages task will be its entry point
    std::thread thr(std::move(ptask), 6, 7);

    std::cout << "waiting for result\n";

    // call get() to receive the result of the packages task
    std::cout << "6 + 7 is " << fut.get() << '\n';

    thr.join();

    return 0;
}
}     // namespace packagedTask
#endif     // PACKAGED_TASK_H