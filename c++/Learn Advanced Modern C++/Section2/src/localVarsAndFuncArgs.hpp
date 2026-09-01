#ifndef LOCAL_VAR_FUNC_ARGS
#define LOCAL_VAR_FUNC_ARGS

#include <iostream>

using namespace std;

int func(const int &y) // notes const TYPE &x, means read, but can't change,
                       // no overhead also / copy's being made
{                      // y will be a copy of the caller's variable x
    cout << "Address of y is " << &y << endl;
    // y = 1;
    return y;
}

int section2_4()
{
    int x = 2;
    cout << "Address of x is " << &x << endl;
    int z = func(x); // z will be a copy of func's return value
    cout << "Address of z is " << &z << endl;
    cout << "After calling func(), x = " << x << endl;
    cout << "After calling func(), z = " << z << endl;
    return 0;
}

#endif // LOCAL_VAR_FUNC_ARGS