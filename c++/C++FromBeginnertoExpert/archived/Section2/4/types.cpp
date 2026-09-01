#include <iostream>
using namespace std;

main() {
    // TYPE_OF_VARIABLE nameOfVariable
    // TYPE_OF_VARIABLE nameOfVariable1, nameOfVariable2, nameOfVariable3;

    int a = 40, b = 0, c = 20; // -2billions to 2 billions, 4bytes
    cout << "a : " << a << " address : " << &a << endl;
    cout << "b : " << b << " address : " << &b << endl;
    cout << "c : " << c << " address : " << &c << endl;

    short t1 = 5; // -32768 to 32768, 2bytes
    cout << t1 << endl;

    float t2 = 5.12; // 4 bytes // 38 zeroes
    double t3 = 5.123; // 8 bytes // 308 zeroes

    cout << t2 << endl;
    cout << t3 << endl;

    char t4; //character

    t4 = 'a';
    cout << t4 << endl;

    string t5 = "Helo World!";
    cout << t5 << endl;

    string x = "part1";
    string y = "part2";
    string combined = x + " " + y;

    cout << combined << endl;

    // boolean | true everything else /false 0
    bool t6 = false;
    cout << t6 << endl;

    // for unsigned int, 0 to 65535
    unsigned short t7 = 3700; // -32768 to 32768, 2bytes
    cout << t7 << endl;

    const string NAMEOFGAME = "CONQUERER OF C++";
    cout << NAMEOFGAME << endl;
}
