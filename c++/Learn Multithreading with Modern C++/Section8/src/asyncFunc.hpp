#ifndef ASYNC_FUNC_H
#define ASYNC_FUNC_H

#include <chrono>
#include <future>
#include <iostream>

using namespace std;

namespace asyncFunc {

// task which returns a value
unsigned long long fibonacci(unsigned long long n) {
    if (n <= 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// task function
void hello() {
    std::cout << "Hello, async!\n";
}

// task which returns a value
int produce() {
    int x = 42;

    using namespace std::literals;
    std::this_thread::sleep_for(2s);

    // some code which may throw an exception
    if (0) {
        throw std::out_of_range("oops");
    }

    std::cout << "produce returning " << x << '\n';
    return x;
}

int main() {
    // call std::async() to perform the task
    // static_cast to avoid (pun) "declared with attribute ‘nodiscard’"
    // static_cast<void>(std::async(hello));

    // std::cout << "calling fibonacci(44)\n";

    // // call async() and store the returned future
    // auto result = std::async(fibonacci, 44);

    // // do some other work
    // [[maybe_unused]] bool finished = false;

    // using namespace std::literals;
    // while (result.wait_for(1s) != std::future_status::ready) {
    //     std::cout << "waiting for the result...\n";
    // }

    // // call get() when we are ready
    // std::cout << result.get() << std::endl;

    // call async() and store the returned future
    auto result = std::async(produce);

    // get the result - mya throw an exception
    std::cout << "future calling get()...\n";
    try {
        int x = result.get();     // get the result
        std::cout << "future returns from calling get()\n";
        std::cout << "the answer is " << x << '\n';
    } catch (std::exception& e) {
        std::cout << "exception caught: " << e.what() << '\n';
    }

    return 0;
}
}     // namespace asyncFunc
#endif     // ASYNC_FUNC_H