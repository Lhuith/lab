#include <iostream>

using namespace std;
// operators

int main()
{
    int a = 10;
    int b = 4;

    // cout << a + b << endl; // addition operator
    // cout << a - b << endl; // subtraction operator
    // cout << a * b << endl; // multiplication operator
    // cout << a / b << endl; // division operator
    // cout << a % b << endl;
    // 10 % 4 = 2 - remainder 10 - 6 = 2
    // 1 % 5 = 1

    // incrementation - increase by 1
    // decrementation - decrease by 1

    // int c = 1;
    // // c = c + 1;
    // c += 1; // same as c = c + 1;

    // cout << c << endl;
    // /*
    //     /=, -=, %=, *=
    // */

    int d = 1;

    cout << d++ << endl; //++ here is increment, x++ post increment, ++x pre increment
    cout << ++d << endl;

    cout << d-- << endl; // x-- post decrement, --x pre decrement
    cout << --d << endl;
    return 0;
}