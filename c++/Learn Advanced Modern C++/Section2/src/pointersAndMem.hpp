#ifndef POINT_MEM_H
#define POINT_MEM_H

#include <iostream>
using namespace std;

void badfunc()
{
    int *p_4 = new int{42}; // allocate mem to func
    // ....
    delete p_4;
    // *p_4 = 10; // using after delete, dingle dangle brother, dont do this, after delete
    // cout << "after assigning to a dangler \n";

    return; // return without releasing mem
} // memory LEAK!!!!!!!!!!!!

void array_pointers()
{
    cout << "allocating memory for array \n";
    int *p_a = new int[20];

    cout << "populating array\n";
    for (int i = 0; i < 20; ++i)
    {
        p_a[i] = i;
    }

    cout << "array of elements:\n";
    for (int i = 0; i < 20; i++)
    {
        cout << p_a[i] << ", ";
    }
    cout << endl;

    cout << "releasing array's memory\n";
    delete[] p_a;
    cout << "finished!\n";
}

namespace pointMem
{

    int main()
    {
        // int i{1};      // i is a stack variable;
        // int *p_i = &i; // p1 is a pointer to int. its value is the address of i
        // cout << "p_i = " << p_i << "\n";
        // cout << "*p_i = " << *p_i << "\n";

        // int *p_2 = new int;     // p_2 points to memory allocated from the heap
        // int *p_3 = new int{36}; // p_3 points to int with init value of 36 (c++11)
        // // int *p_3 = new int(36)   // older version
        // cout << "*p_2 = " << *p_2 << endl;
        // cout << "*p_3 = " << *p_3 << endl;

        // delete p_2;
        // delete p_3;
        // badfunc();
        // // cout << "after bad func \n";

        array_pointers();

        return 0;
    }
}

#endif // POINT_MEM_H