#ifndef PERFECT_FORWARDING_H
#define PERFECT_FORWARDING_H

#include <iostream>
using namespace std;

namespace perfectForwarding {

class test {};

void g(test& x) {
    std::cout << "modifiable version of g called\n";
}

void g(const test& x) {
    std::cout << "immutable version of g called\n";
}

void g(test&& x) {
    std::cout << "move version of g called\n";
}

template <class T>
void f(T&& x) {
    g(std::forward<T>(x));     // a huge amount of crazy black magic
}

int main() {
    test x;
    const test cx;

    cout << "calling f() with lvalue argument\n";
    f(x);
    cout << "\ncalling f() with const lvalue argument\n";
    f(cx);
    cout << "\ncalling f() with rvalue argument\n";
    f(std::move(x));

    return 0;
}
}     // namespace perfectForwarding
#endif     // PERFECT_FORWARDING_H