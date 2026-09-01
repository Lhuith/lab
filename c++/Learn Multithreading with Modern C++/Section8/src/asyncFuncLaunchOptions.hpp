#ifndef ASYNC_FUNC_LAUNCH_OPTIONS_H
#define ASYNC_FUNC_LAUNCH_OPTIONS_H

#include <chrono>
#include <future>
#include <iostream>
#include <string>
#include <thread>

using namespace std;

namespace asyncFuncLaunchOptions {

using namespace std::literals;

int task() {
    std::cout << "executing task() in thread ID: ";
    std::cout << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(5s);
    std::cout << "returning from task()\n";
    return 42;
}

void func(const std::string& option = "default"s) {
    std::future<int> result;

    if (option == "async"s)
        result = std::async(std::launch::async, task);
    else if (option == "deferred"s)
        result = std::async(std::launch::deferred, task);
    else
        result = std::async(task);

    std::cout << "calling async with option \"" << option << "\"\n";
    std::this_thread::sleep_for(2s);
    std::cout << "calling get()\n";
    std::cout << "task result: " << result.get() << '\n';
}

int main() {
    std::cout << "in main thread with ID: " << std::this_thread::get_id() << '\n';

    func("async");
    func("deferred");
    func("default");
    func();

    return 0;
}
}     // namespace asyncFuncLaunchOptions
#endif     // ASYNC_FUNC_LAUNCH_OPTIONS_H