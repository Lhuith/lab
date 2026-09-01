#ifndef PRE_POST_FIX_H
#define PRE_POST_FIX_H

#include <iostream>
using namespace std;

namespace prePostFix {

class complox {
    double real;
    double imag;

   public:
    complox(double r, double i) : real(r), imag(i) {}

    // prefix ++ operator
    complox& operator++() {
        ++real;
        return *this;
    }
    // postfix ++ operator
    complox operator++(int) {
        complox temp(*this);
        ++real;
        return temp;
    }
    // prefix -- operator
    complox& operator--() {
        --real;
        return *this;
    }
    // postfix -- operator
    complox operator--(int) {
        complox temp(*this);
        --real;
        return temp;
    }

    void print() { cout << "(" << real << ", " << imag << ")" << endl; }
};

int main() {
    complox c(5, 6);
    cout << "init value of c: ";
    c.print();

    ++c;
    cout << "after calling ++c: ";
    c.print();

    complox d = c++;
    cout << "after calling c++: ";
    c.print();
    cout << "value of d: ";
    d.print();

    --c;
    cout << "after calling --c: ";
    c.print();

    d = c--;
    cout << "after calling c--: ";
    c.print();
    cout << "value of d: ";
    d.print();

    return 0;
}
}     // namespace prePostFix
#endif     // PRE_POST_FIX_H