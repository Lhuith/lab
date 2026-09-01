#ifndef NUM_TYPE_LITERAL_H
#define NUM_TYPE_LITERAL_H

#include <iostream>
#include <cstdint>

using namespace std;

namespace numTypeLiteral
{

    void numbers()
    {
        const int one_million = 1'000'000;
        const int one_lakh = 1'00'000;
        double pi = 3.141'593;

        cout << "one million: " << one_million << endl;
        cout << "on lakh: " << one_lakh << endl;
        cout << "pi: " << pi << endl;
    }

    void sizes()
    {
        cout << "char: " << sizeof(char) << endl;
        cout << "int: " << sizeof(int) << endl;
        cout << "long: " << sizeof(long) << endl;
        cout << "long long: " << sizeof(long long) << endl;
        cout << endl;

        cout << "int8_t: " << sizeof(int8_t) << endl;
        cout << "int16_t: " << sizeof(int16_t) << endl;
        cout << "int32_t: " << sizeof(int32_t) << endl;
        cout << "int64_t: " << sizeof(int64_t) << endl;
        cout << endl;

        cout << "uint8_t: " << sizeof(uint8_t) << endl;
        cout << "uint16_t: " << sizeof(uint16_t) << endl;
        cout << "uint32_t: " << sizeof(uint32_t) << endl;
        cout << "uint64_t: " << sizeof(uint64_t) << endl;
        cout << endl;
    }

    void literals()
    {
        // numeric literals are decimal by default
        int decimal = 42; // 4*10 + 2*1 = 42
        cout << "Decimal: " << decimal << endl;

        // hexadecimal numbers have 0x or 0X in front
        int hexadecimal = 0x2a; // 2*16 + 10*1 = 42
        cout << "Hexadecimal: " << hexadecimal << endl;

        // Octal numbers have 0 in front
        int octal = 052; // 5*8 + 2*1 = 42
        cout << "Octal: " << octal << endl;

        // Binary numbers have 0b or 0B in front (C++14 onwards)
        int binary = 0b101010; // 1*32 + 1*8 + 1*2 = 42
        cout << "Binary: " << binary << endl;
    }
    int main()
    {
        // sizes();
        // literals();
        numbers();
        return 0;
    }
}

#endif // NUM_TYPE_LITERAL_H