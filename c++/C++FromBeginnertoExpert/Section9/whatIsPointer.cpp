#include <iostream>

using namespace std;
// pointers, normal variables that store address's of the same type

int main()
{

    int var = 5;
    int a = 15;

    cout << *&var << endl;

    int *p_var = &var; // address variable declaration

    // p_var = &var;
    cout << *p_var << endl; // retrieve value at pointer/address

    // *p_var = 20;
    // var = 20;
    // p_var = &a;

    *p_var = 60;
    cout << "var : " << var << endl;
    cout << "pointer: " << *p_var << endl; // retrieve value at pointer/address
    cout << "a : " << a << endl;

    int *const p_const_var = &a; // address locked in
    const int *p_2 = &a;         // value locked in
    const int *const p3 = &a;    // address and value locked, basically doing int &p4 = a;

    cout << endl
         << endl
         << endl;

    int normal_var = 10;
    int *normal_p = &normal_var;

    cout << "n_var : " << normal_var << endl;
    cout << "&n_var : " << &normal_var << endl;
    cout << "n_poi : " << normal_p << endl;
    cout << "*n_poi : " << *normal_p << endl;
    cout << "&n_poi : " << &normal_p << endl;

    int **p_normal_p = &normal_p;
    cout << "p_normal_p : " << p_normal_p << endl;

    return 0;
}