#include <iostream>

using namespace std;
// reference variables

int main()
{
    string name = "Agnes";
    string name2 = "other agnes";

    cout << "value : " << name << ", address " << &name << endl;

    string &nr_6 = name; // reference to name

    // nr_6 = name2; // not creating reference, just changing value

    cout << "value : " << nr_6 << ", address " << &nr_6 << endl;

    nr_6 = "Not Agnes";
    // name = "Not Agnes";

    cout << "value : " << name << ", address " << &name << endl;
    cout << "value : " << nr_6 << ", address " << &nr_6 << endl;

    /*
        ref var must be initalized when created (you can't ref something that wasn't created)
        ref var can't change association/connection
        ref var must be the same type is connected var
    */

    return 0;
}