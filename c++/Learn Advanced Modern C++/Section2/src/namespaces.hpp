#ifndef NAMESPACES_H
#define NAMESPACES_H

#include <iostream>
using namespace std;

int x{23};

namespace namespaces
{
    namespace abc
    {
        int x{47};

        void func()
        {
            cout << "x = " << x << endl;
            cout << "::x = " << ::x << endl;
        }
    }

    int main()
    {
        abc::func();

        cout << ::x << endl;
        cout << abc::x << endl;
        return 0;
    }
}

#endif // NAMESPACES_H