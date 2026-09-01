#include <iostream>

using namespace std;

// arrays
main() {
    int a;

    // int a,b,c,d,e,f,g,f;

    int array[4]; //TYPE NAME[SIZE];

    array[0] = 32;
    array[1] = 64;
    array[2] = 128;
    array[3] = 256;
    // array[4] = 10000 * doesn't exist

    /*
        0 1 2 3 4 5 6 7 8 9 a b c d e f

        1 2 a =  1 * 16^2 + 2 * 16^1 + a * 16^0 = 256 + 32 + (a * 1)/10 = 298
    */

    cout << "array [0]: " << array[0] << ", at: " << &array[0] << endl;
    cout << "array [1]: " << array[1] << ", at: " << &array[1] << endl;
    cout << "array [2]: " << array[2] << ", at: " << &array[2] << endl;
    cout << "array [3]: " << array[3] << ", at: " << &array[3] << endl;

    // name of array = address of the first index of an array
    cout << "array [0]: " << array[0] << ", at: " << array << endl;

    if (array == &array[0])
        cout << "that's true" << endl;
}
