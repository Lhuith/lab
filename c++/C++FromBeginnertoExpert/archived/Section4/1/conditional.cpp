#include <iostream>

using namespace std;

    // conditional statements / instruction

main() {
    int a = 8, b = 9;

    /*
    cout << "Enter a: " << endl;
    cin >> a;

    cout << "Enter b: " << endl;
    cin >> b;
    */


    if ( a > b )
        cout << a << " > " << b << endl;
    else if (a < b) {
        cout << a << " < " << b << endl;
        if (a < 10) {
            cout << "a is smaller then 10" << endl;
        }
    }
    else if (a = b)
        cout << a << " = " << b << endl;
    else
        cout << " conditions weren't met " << endl;

    /*
    if (7 > 4) {
        cout << "something" << endl;
        cout << "test" << endl;
    }

    if (1231231239123)
        cout << "condition above surely not = 0" << endl;

    if((7 < 4 || 0 < 10) && (10 == 9))
        cout << "7 < 4 || 0 < 10" << endl;
    */


}
