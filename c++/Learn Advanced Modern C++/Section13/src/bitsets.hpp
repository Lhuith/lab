#ifndef BITSETS_H
#define BITSETS_H

#include <bitset>
#include <iostream>

using namespace std;

namespace bitsets {

void moreBitMethods() {
    bitset<8> b1{"10101110"};     // bitset with value 174
    cout << "b1 = " << b1 << endl;

    bitset<8> b2;
    b2.set();     // set all bits to true
    cout << "b2 = " << b2 << endl;

    bitset<8> b3;
    b3.reset();     // set all bits to false
    cout << "b3 = " << b3 << endl
         << endl;

    cout << boolalpha << "are all the bits set?" << endl;
    cout << "b1: " << b1.all() << endl;
    cout << "b2: " << b2.all() << endl;
    cout << "b3: " << b3.all() << endl;

    cout << "are any the bits set?" << endl;
    cout << "b1: " << b1.any() << endl;
    cout << "b2: " << b2.any() << endl;
    cout << "b3: " << b3.any() << endl;

    cout << "are no bits set?" << endl;
    cout << "b1: " << b1.none() << endl;
    cout << "b2: " << b2.none() << endl;
    cout << "b3: " << b3.none() << endl;

    cout << "number of bits set" << endl;
    cout << "b1: " << b1.count() << endl;
    cout << "b2: " << b2.count() << endl;
    cout << "b3: " << b3.count() << endl;

    cout << noboolalpha;
}

void bitMethods() {
    bitset<8> b1{"10101110"};     // bitset with value 174

    cout << "b1 = " << b1 << endl;

    auto b2 = b1;
    cout << "calling b2.set()" << endl;
    b2.set();     // set all bits to true
    cout << "b2 = " << b2 << endl;

    auto b3 = b1;
    cout << "calling b3.set(0)" << endl;
    b3.set(0);     // set bit 0 to true
    cout << "b3 = " << b3 << endl;

    cout << "calling b3.set(0, false)" << endl;
    b3.set(0, false);     // set bit 0 to false
    cout << "b3 = " << b3 << endl;

    auto b4 = b1;
    cout << "calling b4.reset()" << endl;
    b4.reset();     // set all bits to false
    cout << "b4 = " << b4 << endl;

    auto b5 = b1;
    cout << "calling b5.reset(7)" << endl;
    b5.reset(7);     // set bit 7 to false
    cout << "b5 = " << b5 << endl;

    auto b6 = b1;
    cout << "calling b6.flip()" << endl;
    b6.flip();     // invert all bits
    cout << "b6 = " << b6 << endl;

    auto b7 = b1;
    cout << "calling b7.flip(7)" << endl;
    b7.flip(7);     // invert bit 7
    cout << "b7 = " << b7 << endl;
}

void bitwiseOps() {
    bitset<8> b1{"10101110"};     // bitset with value 174
    bitset<8> b2{0b010'1110};     // bitset with value 42

    cout << "b1 is " << b1 << endl;       // displays 10101110
    cout << "~b1 is " << ~b1 << endl;     // displays 01010001
    cout << "b2 is " << b2 << endl;       // displays 00101010

    cout << "b1 & b2 is " << (b1 & b2) << endl;     // displays 00101010
    cout << "b1 | b2 is " << (b1 | b2) << endl;     // displays 10001110
    cout << "b1 ^ b2 is " << (b1 ^ b2) << endl;     // displays 10000100

    cout << "b1 << 4 is " << (b1 << 4) << endl;     // displays 11100000
    cout << "b2 >> 2 is " << (b2 >> 2) << endl;     // displays 00001011
}

int main() {
    // bitset<8> b1{"10101110"};      // initialize from string literal - bitset with value 174
    // bitset<8> b2{0xae};            // initialize from integer (decimal or hexidecimal)
    // bitset<8> b3{0b1010'1110};     // initialize from binary constant (c++14)

    // cout << "b1 is " << b1 << endl;                             // displays 10101110
    // cout << "b2 in decimal is " << b2.to_ulong() << endl;       // displays 174
    // cout << "b2 as a string is " << b2.to_string() << endl;     // displays 10101110
    // cout << "b3 is " << b3 << endl;                             // displays 10101110

    // cout << "b1 has " << b1.size() << " bits\n";     // displays 8

    // // display all the bits in b1
    // cout << "the bits of b1 are: ";
    // for (std::size_t i = 0; i < b1.size(); ++i)
    //     std::cout << b1[i] << ",";
    // cout << endl;

    // // bit access with bounds checking
    // cout << "trying access to bit 8 of b1 with bounds checking\n";
    // try {
    //     std::cout << "b1 by " << 8 << " = " << b1.test(8) << endl;
    // } catch (exception& e) {
    //     cout << "caught exception: " << e.what() << endl;
    // }
    // bitwiseOps();
    // bitMethods();
    moreBitMethods();

    return 0;
}
}     // namespace bitsets
#endif     // BITSETS_H