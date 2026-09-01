#ifndef BASIC_STRING_OPS_H
#define BASIC_STRING_OPS_H

#include <iostream>
using namespace std;

namespace basicStringOps
{
    void moreStringOps()
    {
        // default constructor
        string empty;
        cout << "empty has " << empty.size() << " characters: " << empty << endl;

        // c-style string
        string hi{"Hello"};
        cout << "hi has " << hi.size() << " characters: " << hi << endl;

        // repeated value
        string triple_x(3, 'x');
        cout << "triple_x has " << triple_x.size() << " characters: " << triple_x << endl;

        // init list
        string howdy{'H', 'e', 'l', 'l', 'o'};
        cout << "howdy has " << howdy.size() << " characters: " << howdy << endl;

        // substring
        string hello(hi, 1);
        cout << "hello has " << hello.size() << " characters: " << hello << endl;

        string hello2(hi, 1, 3);
        cout << "hello2 has " << hello2.size() << " characters: " << hello2 << endl;
    }

    int main()
    {
        // string str{"Hello World"};
        // string str_x(100, 'x');
        // str[1] = 'a'; // change 2nd character to an 'a'

        // string s1 = str.substr(6);    // returns "world"
        // string s2 = str.substr(6, 2); // returns "wo"

        // cout << str << endl;
        // cout << s1 << endl;
        // cout << s2 << endl;
        // cout << str_x << endl;

        moreStringOps();

        return 0;
    }
}

#endif // BASIC_STRING_OPS_H