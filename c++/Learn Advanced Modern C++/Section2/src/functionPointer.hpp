#ifndef FUNC_POINT_H
#define FUNC_POINT_H

#include <iostream>
using namespace std;

namespace funcPoint
{
    void func(int x, int y)
    {
        cout << x << " + " << y << " = " << x + y << endl;
    }

    using pfunc = void (*)(int, int); // function signature

    // typedef void (*)(const string&, const string&) pfunc; //older c++

    void some_func(int x, int y, pfunc func_ptr)
    {
        (*func_ptr)(x, y);
        // func_ptr(1, 2); // the * is optional
    }

    pfunc other_func()
    {
        return &func;
    }

    int main()
    {
        auto func_ptr = other_func();

        some_func(4, 4, func_ptr);
        return 0;
    }
}

#endif // FUNC_POINT_H