#ifndef CATCH_ALL_HANDLE_H
#define CATCH_ALL_HANDLE_H

#include <iostream>
#include <vector>
using namespace std;

namespace catchAllHandle {
int main() {
    try {
        // throw 42;
        // throw "something went wrong";
        vector<int> vec;
        cout << vec.at(2) << endl;
    } catch (std::exception& e) {
        cout << "caught std::exception: " << e.what() << endl;
    } catch (...) {
        cout << "caught an exception of unkown type\n";
    }
    return 0;
}
}     // namespace catchAllHandle
#endif     // CATCH_ALL_HANDLE_H