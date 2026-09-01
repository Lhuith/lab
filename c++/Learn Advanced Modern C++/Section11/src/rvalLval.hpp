#ifndef RVAL_LVAL_H
#define RVAL_LVAL_H

#include <iostream>
using namespace std;

namespace rvalLval {

int get() { return 2; }     // function returning an int

void func(const int& ri) {     // function taking int by const reference
    cout << ri << endl;
}

int main() {
    func(get());     // return value from get() is an rvalue
                     // the rvalue ios passed by const reference

    return 0;
}
}     // namespace rvalLval
#endif     // RVAL_LVAL_H