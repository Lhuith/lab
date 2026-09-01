#ifndef CASTING_H
#define CASTING_H

#include <iostream>
using namespace std;

namespace casting
{

    void print(char *str)
    {
        cout << str << endl;
    }

    void constCast()
    {
        const char *msg = "Helo, world!";
        // print(msg); // invalid conversion
        print(const_cast<char *>(msg));
    }

    int main()
    {

        int c = 'A';
        cout << c << endl;
        cout << char(c) << endl;
        cout << static_cast<char>(c) << endl;
        cout << "\n";
        constCast();

        return 0;
    }
}

#endif // CASTING_H