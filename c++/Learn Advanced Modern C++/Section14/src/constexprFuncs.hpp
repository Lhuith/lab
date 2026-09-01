#ifndef CONSTEXPR_FUNCS_H
#define CONSTEXPR_FUNCS_H

#include <iostream>
using namespace std;

namespace constexprFuncs {

// constexpr function
constexpr double miles_to_km(double miles) { return miles * 1.602; }

// the argument is a constant expression
// the return value is a constant expression
// the function is evaluated at compile time, which is hot as fuck
const double dist1 = miles_to_km(40);

// the argument is not a constant expression
// the return value is not a constant expression
// the function is evaluated at run time, which is yuck
double arg{40};
double dist2 = miles_to_km(arg);

// the argument is not constant expression
// the return value is not a constant expression
// the return value is required to be a constant expression
// error!
// constexpr double dist4 = miles_to_km(arg);

int main() {
    cout << "helo from constexprFuncs\n";
    return 0;
}
}     // namespace constexprFuncs
#endif     // CONSTEXPR_FUNCS_H