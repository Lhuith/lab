#ifndef PRINT_H
#define PRINT_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

namespace print {

class Test {
    int i{42};
    string str{"Hello"s};

   public:
    // a member function which prints out the data members of the test class
    void print() const {
        cout << "i = " << i << ", str = " << str << endl;
    }

    /*
    a member function which prints out the data members of the Test class.
    this version will work with any output stream, not just cout.
    we pass the output stream by reference as it will be modified inside the function
    */
    void print(ostream& os) const {
        os << "i = " << i << ", str = " << str;
    }
};

/*
        overloaded operator << which prints out the data members of the test class.
        this calls the Test class's print() method and returns the stream
*/

// binary ops
std::ostream& operator<<(std::ostream& os, const Test& test) {
    test.print(os);
    return os;
}

int main() {
    Test test;

    // cout << test << endl; // error: no match for operator <<

    // test.print();
    // test.print(cout);
    cout << test << endl;

    ofstream ofile("../data/test.txt");

    if (!ofile.is_open()) {
        cout << "couldn't open test.txt" << endl;
        return -1;
    }
    // test.print(ofile);
    ofile << test << test << ", added junk" << endl;

    return 0;
}
}     // namespace print
#endif     // PRINT_H