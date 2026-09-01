#include <iostream>

using namespace std;

int main()
{
    int a = 4, b = 2, c = 5;

    if (a < b + c && b < a + c && c < a + b)
        cout << "can make a triangle!" << endl;
    else
        cout << "can't make a triangle :(" << endl;
    return 0;
}