#ifndef MOVE_ONLY_TYPES_RAII_H
#define MOVE_ONLY_TYPES_RAII_H

#include <iostream>
#include <vector>

using namespace std;

namespace moveOnlyTypesRaii {

class myClass {};

class test {
   private:
    int i{0};
    myClass m;

   public:
    test() = default;

    test(const test&) = delete;                // delete copy constructor
    test& operator=(const test&) = delete;     // delete copy assignment operator

    // implement move constructor
    test(test&& arg) noexcept : i(arg.i), m(std::move(arg.m)) {
        cout << "move constructor called" << endl;
    }

    // implement move assignment operator
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

void captureMove() {
    vector<string> strings(5);

    cout << "capture by reference" << endl;
    [&strings]() { cout << "size in lambda = " << strings.size() << endl; }();
    cout << "after calling lambda, size in main = " << strings.size() << endl;

    cout << endl
         << "capture by move" << endl;
    [vs = std::move(strings)]() { cout << "size in lambda = " << vs.size() << endl; }();
    cout << "after calling lambda, size in main = " << strings.size() << endl
         << endl;
}

int main() {
    // test t;     // call default constructor
    // // cout << "copying: ";
    // // test t2 = t;     // call copy constructor
    // cout << "\nmoving temporary: ";
    // test t3 = test();     // call move constructor by using temporary object
    // cout << t3 << endl;
    // cout << "\nmoving rvalue: ";
    // test t4(std::move(t));     // call move constructor by casting test to rvalue
    // cout << t4 << endl;
    // cout << endl;

    // // test t5;
    // // cout << "\nassigning: ";
    // // t5 = t;

    // test t6;
    // cout << "\nassigning from temporary: ";
    // t6 = test();

    // test t;
    // [t]() { cout << "lambda capturing by value\n" }();

    captureMove();

    return 0;
}
}     // namespace moveOnlyTypesRaii
#endif     // MOVE_ONLY_TYPES_RAII_H