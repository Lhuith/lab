#include <iostream>

using namespace std;

int main()
{
    int a = 3, b = 5, c = 4;

    /*
        Pythagorean theorem

        a ^ 2 + b ^ 2 = c ^ 2
    */

    if (a < b + c && b < a + c && c < a + b)
    {
        cout << "can make a triangle!" << endl;
        if (a * a + b * b == c * c || a * a + c * c == b * b || c * c + b * b == a * a)
            cout << "it's also a rectangular triangle" << endl;
    }
    else
        cout << "can't make a triangle :(" << endl;

    return 0;
}