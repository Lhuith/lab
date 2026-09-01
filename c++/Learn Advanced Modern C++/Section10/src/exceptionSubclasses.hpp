#ifndef EXCEPTION_SUBCLASSES_H
#define EXCEPTION_SUBCLASSES_H

#include <cmath>
#include <fstream>
#include <ios>     //for I/O exceptions
#include <iostream>

using namespace std;

namespace exceptionSubclasses {
int main() {
    try {
        cout << sqrt(-1) << endl;
    } catch (const std::exception& e) {
        cout << e.what() << endl;
    }

    ifstream ifile;

    // enable exceptions for ifile
    ifile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        // throws an exception if text.txt connect be opened for reading
        ifile.open("text.txt");
    } catch (const std::exception& e) {
        cout << "exception caught: " << e.what() << endl;
    }

    return 0;
}
}     // namespace exceptionSubclasses
#endif     // EXCEPTION_SUBCLASSES_H