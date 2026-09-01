#include <iostream>
#include "test.hpp"

using namespace std;

int main()
{
    int a = 10;
    int b = a;

    a = 60;

    // cout << "a: " << a << endl;
    // cout << "b: " << b << endl;

    Test o1(100, 400, 10);
    Test o2 = o1; // implicit copy constructor, address's can be copied too!!

    o2.x = 300;
    *(o1.p) = 700;

    cout << "o1.x: " << o1.x << endl;
    cout << "o1.y: " << o1.y << endl;
    cout << "*(o1.p): " << *(o1.p) << endl
         << endl;

    cout << "o2.x: " << o2.x << endl;
    cout << "o2.y: " << o2.y << endl;
    cout << "*(o2.p): " << *(o2.p) << endl;
    return 0;
}