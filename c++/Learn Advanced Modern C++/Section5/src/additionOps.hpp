#ifndef ADDITION_OPS_H
#define ADDITION_OPS_H

#include <iostream>
using namespace std;

namespace additionOps {
// avoid potential confusion with std::complex
class complox {
   private:
    double real{0.0};
    double imag{0.0};

   public:
    complox(double r, double i) : real(r), imag(i) {}
    complox(double r) : real(r) {}

    // we define the += operator as a member function
    // this adds the real and imaginary parts separately and returns the modified object
    complox& operator+=(const complox& rhs) {
        real += rhs.real;     // assign new value of real number
        imag += rhs.imag;     // assign new value of imag number
        return *this;         // return modified object by value
    }
    void print() {
        cout << "(" << real << ", " << imag << ")" << endl;
    }
};

complox operator+(const complox& lhs, const complox& rhs) {
    complox temp{lhs};     // make a copy of the lhs argument
    temp += rhs;           // add the rhs argument to it
    return temp;           // return the modified copy of the lhs argument
}

int main() {
    complox c1(1, 2);
    complox c2{3, 4};
    cout << "c1: ";
    c1.print();
    cout << "c2: ";
    c2.print();

    complox c3 = c1 + c2;
    cout << "c3: ";
    c3.print();

    c1 += c2;
    cout << "c1: ";
    c1.print();

    complox c4 = 1 + c2;     // compiler figures it out from default constructor with single argument complox(double r)
    cout << "c4: ";
    c4.print();

    return 0;
}
}     // namespace additionOps
#endif     // ADDITION_OPS_H