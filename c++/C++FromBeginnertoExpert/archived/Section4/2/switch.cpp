#include <iostream>

using namespace std;

main() {
    // character = number/int
    char x = 100;
    /*
        4.123123123123
        4.112223123123
        not the same, precision!
    */
    switch (x) {
    case 'd': // 100
        cout << "this is for 0 instruction" << endl;
        break;
    case 25:
        cout << "this is for 25 instruction" << endl;
        break;
    case 50:
        cout << "this is for 50 instruction" << endl;
        break;
    default:
        cout << "this is for default instruction" << endl;
        break;
    }
}
