#include <iostream>

using namespace std;
// fib of 0, 1, 2, 3, 4, 5, 6,  7,  8,  9, 10, 11,  12,  13,  14,  15,  16, ...
// res    0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987,

unsigned fib(int);

int main()
{

    /*
        fibonacci - the sum of two previous numbers, so the next number is found by adding the two numbers before it

        fib(0) = 0
        fib(1) = 1
        ...
        fib(2) = 1
        fib(3) = fib(2) + fib(1) = 1 + 1 = 2;
        fib(4) = fib(3) + fib(2) = 3;
        fib(5) = 5
        fib(6) = 8
        fib(7) = 13
        fib(8) = 21

    */
    cout << fib(60) << endl;
    return 0;
}

unsigned fib(int f)
{
    int previousLeft = 0, previousRight = 1;
    int result;

    if (f == 0)
        return 0;
    else if (f == 1)
        return 1;
    else
    {
        for (int i = 2; i <= f; i++)
        {
            result = previousLeft + previousRight;
            previousLeft = previousRight;
            previousRight = result;
        }
    }
    return result;
}