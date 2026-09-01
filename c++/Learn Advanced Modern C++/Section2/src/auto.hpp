#ifndef AUTO_H
#define AUTO_H

#include <iostream>
using namespace std;

namespace _auto
{
    void autoConst()
    {
        const int &x{6};
        auto y = x; // = to in y = x
        ++y;        // now legal, auto be dammed
        // instead
        const auto &y2 = x;
        // ++y2; // now not legal, as its const/ref

        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
        cout << "y2 = " << y2 << endl;
    }

    int main()
    {
        auto i{42}; // type of i deduced as int
        // auto str1 = "Hello";  // type of str1 is deduced as const char*
        auto str2 = "Hello"s; // type of str2 is deduced as std::string

        cout << "i * 2 = " << i * 2 << endl;
        auto it = str2.begin();
        cout << "first element of str2 = " << *it << endl;

        cout << "\n";

        autoConst();

        return 0;
    }
}

#endif