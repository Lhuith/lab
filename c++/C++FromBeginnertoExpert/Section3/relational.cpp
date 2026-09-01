#include <iostream>

using namespace std;
// relational operator

int main()
{
    int a = 10;
    int b = 5;

    cout << (a == b) << endl; // true 1, when both are equal
    cout << (a != b) << endl; // false 0, when both are NOT equal
    cout << (a > b) << endl;  // true 1, when a is GREATER then b
    cout << (a < b) << endl;  // false 0, when a is LESS then b
    cout << (a >= b) << endl; // true 1, when a is GREATER or EQUAL then b
    cout << (a <= b) << endl; // false 0, when a is LESS or EQUAL then b

    cout << !(a == b) << endl; // logic FLIP, same as (a != b)

    return 0;
}