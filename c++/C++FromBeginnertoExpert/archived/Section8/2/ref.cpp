#include <iostream>

using namespace std;

int main() {


    string name = "Agnes";

    cout << "Value of var: " << name << ", address of var " << &name << endl;

    string &nr_6 = name; // (reference, linking, assocation) with name

    cout << "Value of var: " << nr_6 << ", address of var " << &nr_6 << endl;

    nr_6 = "Scott";

    cout << "Value of var: " << name << ", address of var " << &name << endl;
    cout << "Value of var: " << nr_6 << ", address of var " << &nr_6 << endl;

    /*
        ref var must be inited when created i.e assign
        ref var can't change assocations/connections &1:1, but you can change the value
        ref var must be the same type


    */

    return 0;
}
