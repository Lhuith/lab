#ifndef DATA_STRUCTS_CONC_H
#define DATA_STRUCTS_CONC_H

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
using namespace std;

namespace dataStructsConc {

// shared vector
std::vector<int> vec;

// mutex to protect std::vector's data
std::mutex mut;

void func1() {
    // potentially conflicting access - must be protected
    std::lock_guard<std::mutex> lgd(mut);
    for (int i = 0; i < 100'000; ++i)
        vec.push_back(i);
}

void func2() {
    // potentially conflicting access - must be protected
    std::lock_guard<std::mutex> lgd(mut);
    for (int i = 100'000; i < 200'000; ++i)
        vec.push_back(i);
}

int main() {
    std::thread thr1(func1);
    std::thread thr2(func2);

    thr1.join();
    thr2.join();

    std::cout << "shptr data: ";
    for (int i = 0; i < 200'000; ++i)
        std::cout << vec[i] << ", ";

    std::cout << "finished\n";
    return 0;
}
}     // namespace dataStructsConc
#endif     // DATA_STRUCTS_CONC_H