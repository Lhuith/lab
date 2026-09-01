#ifndef ASSIGNMENT7_H
#define ASSIGNMENT7_H

#include <iostream>
#include <string>
using namespace std;

namespace assignment7 {
int main() {
    int y = 1;
    auto lambda = [y = y + 1](int x) { return x + y; };
    cout << lambda(5) << endl;
    cout << y << endl;

    return 0;
}
}     // namespace assignment7
#endif     // ASSIGNMENT7_H