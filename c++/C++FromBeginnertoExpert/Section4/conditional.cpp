#include <iostream>

using namespace std;
// conditional statements / instructions

int main()
{
    int a = 5, b = 6;

    // cout << "Enter a: ";
    // cin >> a;

    // cout << "Enter b: ";
    // cin >> b;

    if (a > b)
        cout << a << " > " << b << endl;
    else if (a < b)
    {
        cout << a << " < " << b << endl;
        if (a < 10)
            cout << "a is smaller then 10" << endl;
    }
    else if (a = b)
        cout << a << " = " << b << endl;
    else
        cout << a << " ? " << b << endl;

    // if (4 > 7)
    // {
    //     cout << "something" << endl;
    //     cout << "test" << endl;
    // }

    // if (123451234123)
    //     cout << "cond above is surely not equal to 0" << endl;

    // if ((7 < 4 || 0 < 10) && (10 == 9))
    //     cout << "(7 < 4 || 0 < 10) && (10 == 9)" << endl;

    return 0;
}