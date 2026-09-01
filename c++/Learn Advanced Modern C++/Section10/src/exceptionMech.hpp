#ifndef EXCEPTION_MECH_H
#define EXCEPTION_MECH_H

#include <iostream>
#include <vector>

using namespace std;

namespace exceptionMech {

void func(const vector<int>& vec) {
    try {
        cout << vec.at(2) << endl;
    } catch (const std::out_of_range& e) {
        cout << "abandoning operation due to exception\n";
        cout << "exception caught: " << e.what() << endl;     // print out a description of the exception
        throw std::exception(e);
        // throw;
    }
}

int main() {
    vector<int> vec;
    try {
        func(vec);
    } catch (const std::exception& e) {
        cout << "call to func failed\n";
        cout << "exception caught: " << e.what() << endl;     // print
    }
    return 0;
}
}     // namespace exceptionMech
#endif     // EXCEPTION_MECH_H