#include <iostream>

using namespace std;

int main()
{
    int a[3];
    short int zm;
    int *const p = &a[0]; // basically what an array name means

    a[0] = 0;
    a[1] = 20;
    a[2] = 40;

    cout << p << endl;
    cout << a << endl;

    cout << endl
         << endl;

    cout << &a[0] << endl;
    cout << &a[1] << endl;
    cout << &a[2] << endl;

    cout << endl
         << endl;

    cout << a << endl;
    cout << a + 1 << endl; // moving 1 size(int) in memory
    cout << a + 2 << endl;

    cout << endl
         << endl;

    cout << *a << endl;
    cout << *(a + 1) << endl; // moving 1 size(int) in memory
    cout << *(a + 2) << endl;

    cout << endl
         << endl;

    cout << a[0] << endl;
    cout << a[1] << endl;
    cout << a[2] << endl;

    cout << endl
         << endl;

    int *a_enum = &a[0];

    cout << *a_enum << endl;   // get value *
    cout << ++*a_enum << endl; // increment, get value
    cout << *++a_enum << endl; // get value at increment
    cout << *a_enum++ << endl; // get value then increment
    cout << *a_enum << endl;   // get value

    // cout << *++a_enum << endl; // get value of random
    // cout << *++a_enum << endl; // get value of random

    return 0;
}