#ifndef USING_SPECIAL_MEM_FUNCTIONS_H
#define USING_SPECIAL_MEM_FUNCTIONS_H

#include <iostream>
using namespace std;

namespace usingSpecialMemFunctions {

class test {
   public:
    // default constructor
    test() = default;

    // // the copy operators are declared as deleted
    // // copy constructor
    // test(const test& other) = delete;

    // copy constructor
    test(const test& o) {
        cout << "copy constructor called" << endl;
    }

    // // copy assignment operator
    // test& operator=(const test& other) = delete;

    test& operator=(const test& o) {
        cout << "copy assignment operator called" << endl;
        return *this;
    }

    // /*
    //         the compiler does not generate any move operators
    // */

    // the move operators are declared as deleted
    test(test&& other) noexcept = delete;
    // move assignment operator
    test& operator=(test& o) noexcept = delete;

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
    // test t2(std::move(t));     // error! use of deleted function
    // cout << t2;
    // test t3(test)					// error! use of deleted function

    test t2(std::move(test));     // does not fall back to copy constructor
    test t3(t);                   // ok - uses copy constructor
    cout << t3;

    return 0;
}
}     // namespace usingSpecialMemFunctions
#endif     // USING_SPECIAL_MEM_FUNCTIONS_H