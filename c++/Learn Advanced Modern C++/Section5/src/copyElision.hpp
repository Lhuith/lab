#ifndef COPY_ELISION_H
#define COPY_ELISION_H

#include <iostream>
using namespace std;

namespace copyElision {
class Test {
   public:
    Test() { cout << "default constructor\n"; }
    Test(const Test& other) { cout << "copying\n"; }  // copt constructor with side effects
};

// function taking an argument value
void func2(Test test) {
    // do something amazing here
}

// function returning a temporary object
Test func() {
    Test test;
    return test;
}

void funcTest() {
    cout << "calling func()" << endl;
    func2(Test());
    cout << "returned from func()" << endl;
}

int main() {
    // cout << "calling func()" << endl;
    // // Test test = func();  // how many times is "copying" printed out?
    // // compiler warnings as errors turned on so can't compile this example
    // cout << "returned from func()" << endl;
    funcTest();

    return 0;
}

}  // namespace copyElision
#endif  // COPY_ELISION_H