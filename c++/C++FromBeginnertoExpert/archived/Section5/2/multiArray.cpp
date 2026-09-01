#include <iostream>

using namespace std;

main() {
    int barray[3][4] = {0}; // allocating memory, not setting values!

    cout << &barray[0] << endl;
    cout << &barray[0][0] << endl;
    cout << &barray[0][1] << endl;
    cout << &barray[0][2] << endl;
    cout << &barray[0][3] << endl;
    cout << &barray[1] << endl;
    cout << &barray[1][0] << endl;
}
