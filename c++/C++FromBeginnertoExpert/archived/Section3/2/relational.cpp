#include <iostream>

using namespace std;

// relational operator
main () {
    int a = 10;
    int b = 5;
    bool t;

    cout << (a == b) << endl; // a is greater or equal to b
    cout << (a != b) << endl; // a does not equal b
    cout << (a > b) << endl; // a is greater then b
    cout << (a < b) << endl; // a is lesser then b
    cout << (a >= b) << endl; // a is greater or equal to b
    cout << (a <= b) << endl; // a is lesser or equal to b

    cout << !(a == b) << endl; // NOT(a is greater or equal to b)
}
