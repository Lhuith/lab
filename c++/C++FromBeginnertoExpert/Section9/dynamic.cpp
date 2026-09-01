#include <iostream>

using namespace std;
// dynamic allocation

int main()
{
    int var = 1234;

    // int amount;
    // cout << "how many numbers would you like to store in array?" << endl;
    // cin >> amount;

    // // right way, allocate mem using new, just clean up your mess afterwards
    // int *p = new (nothrow) int[amount]; // new returns address

    // if (p != NULL)
    // {
    //     cout << "size will be " << amount << ", wow" << endl;
    //     for (int i = 0; i < amount; i++)
    //     {
    //         cout << " Enter the # for " << (i + 1) << ": ";
    //         cin >> p[i];
    //     }

    //     for (int i = 0; i < amount; i++)
    //     {
    //         cout << "p[" << (i) << "] = " << p[i] << endl;
    //     }
    // }
    // else
    //     cout << "not enough memory!" << endl;

    // wrong
    // int array[amount];
    // cout << sizeof(array) << endl;
    // array[0] = 500;
    // cout << array[0] << endl;

    {
        // grabbing and holding memory
        int *p = new int;
        cout << p << endl;
        delete p;
        p = new int;
        cout << p << endl;
        delete p;

        // *p = 10;

        // cout << *p << endl;

        // delete p;
        // p = NULL; // ensure no more use is possible after memory is released

        // p = &var; // don't have to release this as its the above reserved variable and not new

        // // memory address doesn't belong to us anymore
        // // anymore operations here is bad nasty and sad
        // if (p)
        // {
        //     *p = 100;
        //     cout << *p << endl; // should be random value/not our memory anymore
        // }
    }

    // cout
    //     << var << endl;

    // delete[] p;
    // p = NULL;

    return 0;
}