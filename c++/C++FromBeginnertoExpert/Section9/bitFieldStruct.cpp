#include <iostream>

using namespace std;

typedef struct size
{
    unsigned int a : 3;
    unsigned int b : 29;
    unsigned int c : 1;
} foo;

int main()
{
    foo test = foo();
    cout << sizeof(test) << endl;
    return 0;
}