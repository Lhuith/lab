#ifndef EXCEPTION_HIERARCH_H
#define EXCEPTION_HIERARCH_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace exceptionHierarch {

int at(const vector<int>& vec, size_t pos) {
    // check index corresponds to a valid element
    // if not, throw std::out_of_range with a suitable error message
    if (vec.size() < pos + 1) {
        string str{"no element at index "s + to_string(pos)};
        throw std::out_of_range(str);
    }
    // return the element
    return vec[pos];
}

int main() {
    vector<int> vec;
    // vector<int> vec{1, 2, 3};

    try {
        int el = at(vec, 2);
        cout << "vec[2] = " << el << endl;
    } catch (const std::exception& e) {                       // will handle all subclasses of std::exception
        cout << "exception caught: " << e.what() << endl;     // print out a description of the exception
    }

    return 0;
}
}     // namespace exceptionHierarch
#endif     // EXCEPTION_HIERARCH_H