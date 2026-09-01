#ifndef MOVE_OPERATORS_H
#define MOVE_OPERATORS_H

#include <iostream>
#include <ostream>

using namespace std;

namespace moveOperators {

class myClass {};

class test {
   private:
    int i{0};
    myClass m;

   public:
    test() = default;

    // copy constructor
    test(const test& arg) : i(arg.i), m(arg.m) {
        cout << "copy constructor called" << endl;
    }
    // move constructor
    test(test&& arg) noexcept : i(arg.i), m(std::move(m)) {
        cout << "move constructor called" << endl;
    }
    // copy assignment operator
    test& operator=(const test& arg) {
        cout << "copy assignment operator called" << endl;
        if (this != &arg) {
            i = arg.i;
            m = arg.m;
        }
        return *this;
    }

    // move assignment operator
    test& operator=(test&& arg) noexcept {
        cout << "move assignment operator called" << endl;
        if (this != &arg) {
            i = arg.i;
            m = std::move(arg.m);     // force move assignment operator to be called
        }
        return *this;
    }

    void print(std::ostream& os) const {
        os << "";
    }
};

std::ostream& operator<<(std::ostream& os, const test& t) {
    t.print(os);
    return os;
}

int main() {
    test t;     // call default constructor
    cout << "copying: ";
    test t2 = t;     // call copy constructor
    cout << "\nmoving temporary: ";
    test t3 = test();     // call move constructor by using temporary object
    cout << t3;
    cout << "\nmoving rvalue ref: ";
    test t4(std::move(t));     // call move constructor by casting test to rvalue

    cout << endl;

    test t5;
    cout << "\nassigning: ";
    t5 = t2;     // call copy assignment operator

    test t6;
    cout << "\nassigning from temporary: ";
    t6 = test();     // call move assignment operator

    return 0;
}
}     // namespace moveOperators
#endif     // MOVE_OPERATORS_H