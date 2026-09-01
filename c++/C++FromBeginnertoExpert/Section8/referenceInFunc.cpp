#include <iostream>

using namespace std;

int &swap(int &, int &);

int main()
{
    int a = 10;
    int b = 20;

    int &c = swap(a, b);

    cout << "a : " << a << ", b: " << b << ", c: " << c << endl;
    c = 50;
    cout << "a : " << a << ", b: " << b << ", c: " << c << endl;
    return 0;
}

int &swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;

    return a;
}