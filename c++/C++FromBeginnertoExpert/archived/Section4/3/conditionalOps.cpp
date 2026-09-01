#include <iostream>

using namespace std;

main() {
    int a = 10;
    int b = 20;

    // conditional operator ? a (nope?) then b
    string message = (a >= b) ? "a > b" : "a <= b";

    cout << ((a > b? a : b) + 10) << endl;
}
