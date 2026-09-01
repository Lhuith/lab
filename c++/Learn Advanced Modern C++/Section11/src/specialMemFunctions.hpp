#ifndef SPECIAL_MEM_FUNCTIONS_H
#define SPECIAL_MEM_FUNCTIONS_H

#include <iostream>
using namespace std;

namespace specialMemFunctions {

class test {
   public:
    // default constructor
    test() = default;
    // in effect, the copy operators are declared as deleted
    // copy constructor
    // test(const test& other) = delete

    // copy assignment
    // test& operator=(const test& other) = delete;

    // move constructor
    // note move constructors will remove/delete copy constructors if not explicitly implemented
    test(test&& other) noexcept {
        cout << "move constructor called" << endl;
    }

    test& operator=(test&& other) noexcept {
        cout << "move assignment operator called" << endl;
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
    test t;     // ok - uses default constructor
    cout << t;
    test t2(std::move(t));     // ok - uses move constructor
    t2 = std::move(t);         // ok - uses move assignment operator
    // test t4(t);                // ERROR! use of deleted function
    // cout << t4;

    return 0;
}
}     // namespace specialMemFunctions
#endif     // SPECIAL_MEM_FUNCTIONS_H