#include <iostream>

using namespace std;

int main()
{
    // type_of_var nameOfVar
    // type_of_var nameOfVar1, type_of_var nameOfVar2

    int a = 40, b = 0, c = 20; // -2 billion to 2 billions, 4 bytes

    cout << a << " address: " << &a << endl;
    cout << b << " address: " << &b << endl;
    cout << c << " address: " << &c << endl;

    short t1 = 5; // -32768 to 32767, 2 bytes
    cout << t1 << endl;

    float t2 = 5.12;  // 4 bytes, 38 zeroes
    double t3 = 5.12; // 8 bytes, 308 zeroes

    cout << t2 << endl;
    cout << t3 << endl;

    char t4; // character
    t4 = 'a';

    cout << t4 << endl;

    string t5 = "Hello World!";
    cout << t5 << endl;

    string x = "part 1";
    string y = "part 2";
    string combined = x + " " + y;
    cout << combined << endl;

    // boolean true | false
    bool t6 = 0; // any number that is not 0 is true in c++
    cout << t6 << endl;

    // for unsigned short int, 0 - 65535
    unsigned short t7 = 3700;
    cout << t7 << endl;

    const string NAMEOFGAME = "SLASHER";
    cout << NAMEOFGAME << endl;

    return 0;
}