#ifndef OVERVIEW_PART_THREE_H
#define OVERVIEW_PART_THREE_H

// program which passes a large object by value
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace overviewPartThree {

// pass by value
// arg will be a copy of the object passed by the caller
// void func(std::vector<std::string> arg) {
//     std::cout << "argument vector as " << arg.size() << " elements" << std::endl;
// }

// the caller's object will be moved into x

// pass by move
// the object passed by the caller is moved into arg
void func(std::vector<std::string>&& arg) {
    for (auto s : arg)
        cout << s << ", ";
    cout << endl;

    std::cout << "argument vector as " << arg.size() << " elements" << std::endl;
}

// void func(int&& x) {
//     std::cout << "rvalue reference" << std::endl;
// }

int main() {
    std::vector<std::string> vec{"testy test data", "yum so data", "hopefully I dont get moved"};
    std::cout << "before calling func, vector has " << vec.size() << " elements\n";
    // casts vec to an rvalue
    func(std::move(vec));

    for (auto s : vec)
        cout << s << ", ";
    cout << endl;
    std::cout << "After calling func, vector has " << vec.size() << " elements\n";

    // func(2);
    // int y = 2;
    // func(y);     // error! move be moveable rvalue

    return 0;
}
}     // namespace overviewPartThree
#endif     // OVERVIEW_PART_THREE_H