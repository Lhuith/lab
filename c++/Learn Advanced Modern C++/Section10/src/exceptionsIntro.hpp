#ifndef EXCEPTIONS_INTRO_H
#define EXCEPTIONS_INTRO_H

#include <iostream>
#include <vector>
using namespace std;

namespace exceptionsIntro {
int main() {
    vector<int> vec;
    // cout << vec[2] << endl;     // invalid element access - undefined behavior

    try {
        cout << vec.at(2) << endl;                            // throws an exception
    } catch (const std::exception& e) {                       // will handle all subclasses of std::exception
        cout << "exception caught: " << e.what() << endl;     // print out a description of the error condition
    }

    cout << "finished!\n";

    return 0;
}
}     // namespace exceptionsIntro
#endif     // EXCEPTIONS_INTRO_H