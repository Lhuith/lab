#include <iostream>

using namespace std;

int main()
{
    /*
        0
        1
        0101 0110 <- byte, 8 bits

        126 = 1 * 10 ^ 2 + 2 * 10 ^ 1 + 6 * 10 ^ 0

        1 0 1 0 = 1 * 2 ^ 3 + 0 * 2 ^ 2 + 1 * 2 ^ 1 + 0 * 2 ^ 0 = 8 + 0 + 2 + 0 = 10
        1 0 1 0 = 1 * 2 ^ 3 + 2 ^ 1 = 10
        1010 = 10

        1 0 1 1 0 0 = 2 ^ 2 + 2 ^ 3 + 2 ^ 5 = 4 + 8 + 32 = 44

    */

    /*
        Bitwise AND - &
        Bitwise OR  - |
        Bitwise NOT - ~ (tilde)
        Bitwise XOR - ^ (exclusive or/disjunction)
        0 0 0
        0 1 1
        1 0 1
        1 1 0
        Bitwise left shift  <<
        Bitwise right shift >>

    */

    cout << (10 & 2) << endl;
    /*
        1 0 1 0 - 10
        0 0 1 0 - 2
        0 0 1 0 - 2
    */

    cout << (10 | 2) << endl;
    /*
        1 0 1 0 - 10
        0 0 1 0 - 2
        1 0 1 0 - 10
    */

    cout << (10 ^ 2) << endl;
    /*
        1 0 1 0 - 10
        0 0 1 0 - 2
        1 0 0 0 - 8
    */

    cout << (~10) << endl; // many many zeroes
    /*
        00000000000000000 1 0 1 0 - 10
        11111111111111111 0 1 0 1 - -11 and not 5 :(
    */

    cout << (10 << 3) << endl; // 10 * 2 ^ x/1
    /*
         00000000000000001 0 1 0 0 - 10, multiplying 10 by 2 raised to the power x
         20 << 1
         40 << 2
    */

    cout << (10 >> 1) << endl; // 10 / 2 ^ x/1
    /*
         00000000000000000 0 1 0 1 - 10, dividing 10 by 2 raised to the power x
         5 >> 1
    */

    return 0;
}