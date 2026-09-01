#ifndef STRING_ADD_H
#define STRING_ADD_H

#include <iostream>
using namespace std;

namespace stringAdd
{
    void stringBuffer()
    {
        string str{"orld"};
        cout << "str = " << str << endl;

        auto first = begin(str);
        str.insert(end(str), 16, 'd'); // add enough elements to force a ??

        first = begin(str); // get the new value of the iterator, since last iterator is pointing not wrong address now due to mem buffer shift in string
        str.insert(first, 'w');
        cout << "str = " << str << endl;
    }

    void insert3()
    {
        string str{"word"};
        cout << "str = " << str << endl;

        auto last = end(str) - 1; // get iterator to last character

        // insert 'l' before last character
        str.insert(last, 'l');
        cout << "str = " << str << endl;

        string str2{"ski"};
        cout << "str2 = " << str2 << endl;
        auto last2 = end(str2); // get iterator to last character plus one

        // insert 'l' twice after last character
        str2.insert(last2, 2, 'l');
        cout << "str2 = " << str2 << endl;
    }

    void insert2()
    {
        string str{"xx"};
        cout << "str = " << str << endl;

        string str2{"trombone"};
        cout << "str2 = " << str2 << endl;

        str.insert(1, str2, 4, 2);
        cout << "str = " << str << endl;

        string str3{"cash"};
        cout << "str3 = " << str3 << endl;
        str3.insert(1, 3, 'r');
        cout << "str3 = " << str3 << endl;

        string hello{"Hello"};
        cout << "hello = " << hello << endl;
        auto opos = hello.find('o');

        if (opos != string::npos)
        {
            hello.insert(opos, 2, 'o');
        }

        cout << "hello = " << hello << endl;
    }

    void insert()
    {
        string str{"for"};
        cout << "str = " << str << endl;

        str.insert(2, "lde"s);
        cout << "str = " << str << endl;

        string str2{"care"};
        cout << "str2 = " << str2 << endl;

        string str3{"omp"};
        str2.insert(1, str3);
        cout << "str2 = " << str2 << endl;
    }

    int main()
    {
        // string hello{"Hello"};

        // hello.append(" world"s);
        // cout << "hello = " << hello << endl;

        // string hello2{"Hello"s};

        // hello2.append("wow!!!!"s, 3, 2);
        // cout << "hello2 = " << hello2 << endl;

        // insert();
        // insert2();
        // insert3();
        stringBuffer();

        return 0;
    }
}

#endif // STRING_ADD_H