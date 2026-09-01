#include <iostream>

using namespace std;

int main()
{
    int a = 5;
    int b = 10;

    // condition ? (instruction) true : false
    string message = (a > b) ? "a > b" : "a <= b";

    cout << ((a > b ? a : b) + 10) << endl;
    return 0;
}