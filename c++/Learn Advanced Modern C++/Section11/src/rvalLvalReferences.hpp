#ifndef RVAL_LVAL_REFERENCES_H
#define RVAL_LVAL_REFERENCES_H

#include <iostream>
#include <string>

using namespace std;

namespace rvalLvalReferences {

void func(int&& x) {     // func's argument is an "rvalue reference"
    cout << "called with argument: " << x << endl;
}

void test(const string& s) {
    cout << "lvalue reference version\n";
}

void test(string&& s) {
    cout << "rvalue reference version\n";
}

int main() {
    // int y{2};

    // func(2);     // 2 is an rvalue. OK 👌
    // func(y);     // y is an lvalue

    string l{string{"perm"}};
    string& lr{l};

    cout << "temporary object: ";
    test(string{"temp"});

    cout << "lvalue variable: ";
    test(l);

    cout << "lvalue reference: ";
    test(lr);

    cout << "std::move(): ";
    test(std::move(l));
    cout << "\n";

    string&& r{string{"temp"}};

    cout << "rvalue variable: ";
    test(r);
    cout << "std::move(): ";
    test(std::move(r));

    return 0;
}
}     // namespace rvalLvalReferences
#endif     // RVAL_LVAL_REFERENCES_H