#include <iostream>

using namespace std;
// arrays

int main()
{
    const int a = 10;

    // int a, b, c, d, e, f, g, h, i, j, k; // bad
    // int v1,v2,v3,v4,v5,v6,v7,v8,v9,v10 ... // bad

    int arr[a]; // TYPE NAME[SIZE]

    arr[0] = 10;
    arr[1] = 50;
    arr[2] = 256;
    arr[3] = 125;
    // arr[3] = ??? doesn't exist atm
    // arr[3] = 0;

    /*  hexidecimal
        0 1 2 3 4 5 6 7 8 9 a b c d e f

        1 2 a = 1 * 16 ^ 2  + 2 * 16 ^ 1 + a * 16 ^ 0 = 256 + 32 + 10 = 298
    */

    cout << "array [0] = " << arr[0] << ", address: " << &arr[0] << endl;
    cout << "array [1] = " << arr[1] << ", address: " << &arr[1] << endl;
    cout << "array [2] = " << arr[2] << ", address: " << &arr[2] << endl;
    cout << "array [3] = " << arr[3] << ", address: " << &arr[3] << endl;

    cout << "array [0] = " << arr[0] << ", address: " << arr << endl;

    if (&arr[0] == arr)
        cout << "same address bro" << endl;

    if (&arr[1] == arr)
        cout << "same address bro" << endl;
    return 0;
}