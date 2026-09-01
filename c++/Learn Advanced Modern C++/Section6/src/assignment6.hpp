#ifndef ASSIGNMENT6_H
#define ASSIGNMENT6_H

#include <iostream>
using namespace std;

namespace assignment6 {
int main() {
    int x{42}, y{99}, z{0};

    auto lam = [=, &z]() mutable {++x; ++y; z = x + y; cout << "x: " << x << endl; cout << "y: " << y << endl; };
    lam();
    cout << "z: " << z << endl;
    lam();
    cout << "z: " << z << endl;
    lam();
    cout << "z: " << z << endl;
    return 0;
}
}     // namespace assignment6
#endif     // ASSIGNMENT6_H