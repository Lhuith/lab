#ifndef ASSIGNMENT3_H
#define ASSIGNMENT3_H

#include <iostream>
#include <thread>

using namespace std;

namespace assignment3 {
int x{0};

void func() {
    while (x == 0) {
        cout << x << endl;
        x = 1 - x;
        cout << x << endl;
    }
}

int main() {
    std::thread thr1{func};
    std::thread thr2{func};
    // std::thread thr3{func};
    // std::thread thr4{func};

    thr1.join();
    thr2.join();
    // thr3.join();
    // thr4.join();

    return 0;
}
}     // namespace assignment3
#endif     // ASSIGNMENT3_H
