#include <iostream>

using namespace std;
// type casting

int main()
{
    double var = 5.5;
    int a = 5;
    int b = 7;

    cout << (double)a / b << endl;
    cout << (int)var << endl; // explicit casting

    int x = 123123414;
    short y = x; // implicit casting

    cout << y << endl;

    cout << int(var) << endl;              // explicit casting C
    cout << static_cast<int>(var) << endl; // explicit casting C++

    char ch = 'k';
    cin >> ch;
    cout << (int)ch << endl;

    return 0;
}