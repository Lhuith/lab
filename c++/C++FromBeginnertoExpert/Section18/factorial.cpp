#include <iostream>

using namespace std;

unsigned factorial(int);

int main()
{

    /*
        factorial - product of positive integers up to the provided number
        1! = 1
        2! = 1 * 2
        3! = 1 * 2 * 3
        4! = 1 * 2 * 3 * 4
        5! = 1 * 2 * 3 * 4 * 5
    */
    cout << factorial(3) << endl;
    return 0;
}

unsigned factorial(int f)
{
    unsigned result = 1;
    for (int i = 1; i < f; i++, result *= i)
    {
    }
    return result;
}