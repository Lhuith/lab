#include <iostream>

using namespace std;

// void multiplyBy(int &, int);
int *multiplyBy(int *, int);
void multiplyArrayBy(int *, int, int);

int main()
{
    // int a = 10;
    // int *b = multiplyBy(&a, 5);

    // *b = 999;

    // cout << a << endl;
    // cout << *b << endl;

    int array[10];
    // cout << sizeof(array) / sizeof(array[0]) << endl;

    for (int i = 0; i < 10; i++)
    {
        array[i] = i;
        // cout << "array[" << i << "] = " << array[i] << endl;
    }
    multiplyArrayBy(&array[0], 5, sizeof(array) / sizeof(array[0])); // &array[0] == array

    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        cout << "array[" << i << "] = " << array[i] << endl;
    }
    return 0;
}

void multiplyArrayBy(int *a, int c, int size)
{
    while (size--)
        a[size] *= c;
}

int *multiplyBy(int *v, int c)
{
    // int * v = ^a; // nickname
    *v = *v * c;
    return v;
}