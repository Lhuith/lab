#include <iostream>

using namespace std;
// do and do while loops

int main()
{
    const int SIZEOFARRAY = 10;
    int i = 0;
    int array[SIZEOFARRAY];
    // while (i < SIZEOFARRAY) // 0 == false, smexy
    // {
    //     array[i] = 10 * i;
    //     cout << array[i++] << endl;
    // }

    do
    {
        cout << "lala" << endl;
    } while (i);

    return 0;
}