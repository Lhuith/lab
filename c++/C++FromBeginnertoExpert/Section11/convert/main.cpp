#include <iostream>
#include "integer.hpp"

using namespace std;
// convert constructor

int main()
{
    Integer a(50);
    int b = a; // should be (int)a
    a = 100;

    cout << a.getNr() << endl;
    cout << b << endl;
    // cout << a + b << endl;

    a += b; // a = a + b;
    cout << a.getNr() << endl;

    return 0;
}