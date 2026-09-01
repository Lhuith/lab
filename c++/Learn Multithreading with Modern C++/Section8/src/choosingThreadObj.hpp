#ifndef CHOOSING_THREAD_OBJ_H
#define CHOOSING_THREAD_OBJ_H

#include <chrono>
#include <future>
#include <iostream>
#include <string>
#include <thread>

using namespace std;

namespace choosingThreadObj {

using namespace std::literals;

void task() {
    std::this_thread::sleep_for(5s);
    std::cout << "task result: " << 42 << '\n';
}

void func() {
    std::cout << "calling async\n";
    auto result = std::async(std::launch::async, task);
}

int main() {
    func();
    std::cout << "task started\n";

    return 0;
}
}     // namespace choosingThreadObj
#endif     // CHOOSING_THREAD_OBJ_H