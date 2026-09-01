#include <iostream>

using namespace std;

int main() {

    int a[3];
    a[0] = 42;
    a[1] = 33;
    a[2] = 69;

    short int zm;
    int lala = 6;
    int * const p = &a[0]; // can't change the address

    //a = &lala;
    cout << p << endl;
    cout << a << endl;

    cout << endl << endl << endl;

    cout << &a[0] << endl;
    cout << &a[1] << endl;
    cout << &a[2] << endl;

    cout << endl << endl << endl;

    cout << a << endl;
    cout << a + 1 << endl;
    cout << a + 2 << endl;

    cout << endl << endl << endl;

    cout << *a << endl;
    cout << *(a + 1) << endl;
    cout << *(a + 2) << endl;

    cout << endl << endl << endl;

    cout << a[0] << endl;
    cout << a[1] << endl;
    cout << a[2] << endl;

    //cout << a++ << endl; a = a + 1, but address change change!
    cout << endl << endl << endl;

    int *p2 = &a[0];

    cout << *p2 << endl;    // 0 0 bytes
    cout << ++*p2 << endl;  // 1 4 bytes
    cout << *++p2 << endl;  // 2 8 bytes
    cout << *p2++ << endl;  // 2 8 bytes + 4 bytes after
    cout << *p2 << endl;    // 12 bytes
    return 0;
}
