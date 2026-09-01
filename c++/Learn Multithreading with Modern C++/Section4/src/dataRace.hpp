#ifndef DATA_RACE_H
#define DATA_RACE_H

#include <iostream>
#include <thread>

using namespace std;

namespace dataRace {

void print(std::string str) {
    // a very artificial way to display a string
    for (int i = 0; i < 5; ++i) {
        std::cout << str[0] << str[1] << str[2] << std::endl;
    }
}

int main() {
    std::thread thr1(print, "abc");
    std::thread thr2(print, "def");
    std::thread thr3(print, "xyz");

    // wait for the tasks to complete
    thr1.join();
    thr2.join();
    thr3.join();

    return 0;
}
}     // namespace dataRace
#endif     // DATA_RACE_H