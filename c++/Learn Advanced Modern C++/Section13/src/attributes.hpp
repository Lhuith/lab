#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

#include <iostream>
using namespace std;

namespace attributes {
// function that never returns
[[noreturn]]
void server() {
    while (true) {
        // processing incoming connection
    }
}
// this will give a compiler warning whenever func() is called
[[deprecated("use the version 2.0 interface in new code")]]
void func() {
    cout << "I've been deprecated!\n";
}

[[nodiscard]] int func2() {
    return 42;
}

// nodiscard type
// all functions which return Test are nodiscard
struct [[nodiscard]] Test {};

// function whose return value should not be ignored
Test func3() {
    return Test{};
}

int main() {
    // server();
    // func();
    // func2();     // call func and ignore its returned value
    // cout << func2() << endl;
    // func3(); // call func and ignore its returned value

    // requires c++17 compiler
    // [[maybe_unused]] char buffer[128];

    return 0;
}

}     // namespace attributes
#endif     // ATTRIBUTES_H