#ifndef TRY_CATCH_BLOCK_H
#define TRY_CATCH_BLOCK_H

#include <iostream>
#include <vector>
using namespace std;

namespace tryCatchBlock {

void func(const vector<int>& vec) {
    cout << vec.at(2) << endl;
}

int main() {
    // try {
    //     vector<int> v;
    //     cout << v.at(2) << endl;          // may throw an exception of type std::out_of_range
    // } catch (const out_of_range& e) {     // only handles exceptions of type std::out_of_range
    //     cout << "std::out_of_range\n";
    // } catch (const exception& e) {     // will handle all sub-classes of std::exception
    //     cout << "std::exception\n";
    // }

    // which catch block handles the exception?

    // vector<int> vec;
    // try {
    //     try {
    //         cout << vec.at(2) << endl;     // throws an exception
    //     } catch (const std::bad_alloc& e) {
    //         cout << "bad alloc catch block\n";
    //         cout << "exception caught: " << e.what() << endl;     // print out a description of the exception
    //     }
    // } catch (const std::exception& e) {     // will handle all subclasses std::exception
    //     cout << "std::exception catch block\n";
    //     cout << "exception caught: " << e.what() << endl;     // print out a description of the exception
    // }

    vector<int> vec;

    // catch any exceptions thrown by func()
    try {
        func(vec);
    }
    // handle the exception
    catch (const std::exception& e) {
        cout << "std::exception catch block\n";
        cout << "exception caught: " << e.what() << endl;     // print out a description of the exception
    }

    return 0;
}
}     // namespace tryCatchBlock
#endif     // TRY_CATCH_BLOCK_H