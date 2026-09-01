#ifndef MATHMATICAL_TYPES_H
#define MATHMATICAL_TYPES_H

#include <complex>
#include <iostream>

using namespace std;

namespace mathmaticalTypes {
int main() {
    // complex<double> p;
    // complex<double> q{3.0, 4.0};
    // cout << q << endl;     // displays (3.0, 4.0);

    // cout << "enter complex number, e.g. (1.5, 2.7)\n";
    // cin >> p;
    // cout << "number entered is " << p << endl;
    // cout << "real part: " << p.real() << ", imaginary part: " << p.imag() << endl;

    // complex<double> p{1.0, 2.0};
    // cout << "p = " << p << endl;

    // complex<double> q{3.0, 4.0};
    // cout << "q = " << q << endl;

    // cout << "r = p + q" << endl;
    // complex<double> r = p + q;
    // cout << "r = " << r << endl;

    // cout << boolalpha << "p == q is " << (p == q) << endl;
    // cout << noboolalpha;

    // // ++p :(
    // p += 1;
    // cout << "incrementing p gives " << p << endl;

    // complex<double> p{1.0, 2.0};
    // cout << "p = " << p << endl;

    // auto s = 2i;     // complex number, real part 0.0, imaginary part 2.0
    // cout << "s = " << s << endl;

    // auto z = 3.0 + 4i;     // complex number, real part 3.0, imaginary part 4.0
    // cout << "z = " << z << endl;

    // p += 4i;     // increase p's imaginary part by 4.0
    // cout << "p = " << p << endl;

    complex<double> p{3.0, 4.0};
    cout << "p = " << p << endl;

    cout << "p's magnitude is " << abs(p) << endl;
    cout << "p's phase angle is " << arg(p) << endl;
    cout << "p's conjugate is " << conj(p) << endl;
    cout << "p's square is " << pow(p, 2.0) << endl;
    cout << "p's sine is " << sin(p) << endl;

    return 0;
}
}     // namespace mathmaticalTypes
#endif     // MATHMATICAL_TYPES_H