#include <iostream>

using namespace std;

int power(int, int);
double power(double, int);

int main() {
    cout << power(2, 3) << endl;
    return 0;
}

/*
    2 (base) ^ 3 (power) = 2 * 2 * 2
*/

int power(int b, int e) {
    int tmp = b;
    int i = 0;
    while(i++ < e) {
        cout << tmp << " ^ " << i << " = " << b << endl;
        if (i != e)
            b *= tmp; // b = b * tmp
    } // check then decrease

    return b;
}

double power(double b, int e) {
    int tmp = b;
    while(e-- > 1) // check then decrease
         b *= tmp; // b = b * tmp
    return b;
}
