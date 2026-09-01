#include <iostream>

using namespace std;

unsigned factorial(int);

int main()
{

    /*
        recursive function - function that invokes itself inside its body
        condition - that stops recursion

        1! = 1
        2! = 1 * 2
        3! = 1 * 2 * 3
        4! = 1 * 2 * 3 * 4
        5! = 1 * 2 * 3 * 4 * 5

        5! = 4! * 5;
        factorial(5) = factorial(4) * 5

        4! = 3! * 4
        factorial(4) = factorial(3) * 4

        3! = 2! * 3
        factorial(3) = factorial(2) * 3
    */
    cout << factorial(5) << endl;
    return 0;
}

unsigned factorial(int f)
{
    if (f == 1)
        return 1;

    return factorial(f - 1) * f;
}