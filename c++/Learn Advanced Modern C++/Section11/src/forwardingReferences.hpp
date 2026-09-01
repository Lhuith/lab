#ifndef FORWARDING_REFERENCES_H
#define FORWARDING_REFERENCES_H

#include <iostream>
using namespace std;

namespace forwardingReferences {

// void func(int& x) {
// cout << "func called with argument int&" << endl;
// }

class test {};

template <class T>
void func(T&& x) {     // black magic
    cout << "func called" << endl;
}

int main() {
    // int i{42};
    // // int&& ri = i;     // error

    // using int_ref = int&;     // or typedef int& int_ref;

    // int_ref j{i};       // j is reference to int
    // int_ref& rj{j};     // rj is a reference to (reference to int)

    // func(rj);

    test t;
    test& rt{t};

    // T is test& and x is T&& => test&
    func(t);     // compiler instantiates func(test& x)

    // T is test& and x is T&& => test&
    func(rt);     // compiler instantiates func(test& x)

    // T is test x is T&& => test&&
    func(std::move(t));     // compiler instantiates func(test&& x)

    return 0;
}
}     // namespace forwardingReferences
#endif     // FORWARDING_REFERENCES_H