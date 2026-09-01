#include <iostream>

using namespace std;

int main() {
    int var = 5;
    int a = 20;

    cout << *&var << endl;

    int * p = &var;      // pointer
    // p = &var;        // storing address

    cout << *p << endl; // point to value from pointer (indicated)

    // *p = 20;  // same
    // var = 60; // same
    // p = &a;     // pointing to a
    *p = 60;    // changing a
    cout << "var: "<< var << endl;
    cout << "*p: " << *p << endl;
    cout << "a: "<< a << endl;

    int * const p_const = &a; // has to be init when defined, and only 1 point address allowed, basically linking
    const int * p_2 = &a; // pointer cant change value (placement matters)
    const int * const p_3 = &a; // 1 link AND cant change value

    cout << endl << endl << endl;

    int ordinary_var = 10;

    int *ordinary_p = &ordinary_var;

    cout << "o_var: " << ordinary_var << endl;        // int
    cout << "&o_var: " << &ordinary_var << endl;      // address
    cout << "o_p: " << ordinary_p << endl;          // address
    cout << "*o_p: " << *ordinary_p << endl;       // int
    cout << "&o_p: " << &ordinary_p << endl;       // address of pointer (it has to be stored too bro)

    int ** ordinary_p_p = &ordinary_p;
    cout << "o_p_p: " << ordinary_p_p << endl;       // address of pointer (it has to be stored too bro)
    return 0;
}
