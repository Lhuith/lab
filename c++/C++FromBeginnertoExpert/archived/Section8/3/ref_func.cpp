#include <iostream>

using namespace std;

int & swap(int &, int &);

int main() {
    int a = 10;
    int b = 20;

    int & c =  swap(a, b); // linked/referencing a
    int & d =  swap(a, b); // linked/referencing a

    c = 100; // linked to a
    d = 50;  // linked to c, need to be careful with this

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
    cout << "d: " << d << endl;

    return 0;
}


int & swap(int & a, int & b) {
    int t;
    t = a;
    a = b;
    b = t;

    // cout << "a: " << a << endl;
    // cout << "b: " << b << endl;
    return a; // returning reference to a
}
