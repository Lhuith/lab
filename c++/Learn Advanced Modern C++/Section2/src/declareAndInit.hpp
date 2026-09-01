#ifndef DEC_INIT_H
#define DEC_INIT_H

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Test
{
    string who;

public:
    Test(string w)
    {
        who = w;
        cout << who << " is made" << endl;
    }
    ~Test()
    {
        cout << who << " is unmade" << endl;
    }
};

void print(const vector<int> &vec)
{
    for (auto v : vec)
        cout << v << ", ";

    cout << endl;
}

int new_syntax()
{
    int x{7};                 // = to int x = 7;
    string s{"Let us begin"}; // = to string s("Let us begin");

    cout << "x  = " << x << endl;
    cout << "s = \"" << s << "\"" << endl;

    vector<int> vec{4, 2, 3, 5, 1}; // std::vector var with elements 4, 2, 3, 5, 1;

    cout << "vec = ";
    print(vec);

    return 0;
}

int old_syntax()
{
    // Narrowing conversion are now allowed!
    int y = 7.7; // truncated :(    legal, although compiler will warn
    // int y{7.7}; // illegal, cannot do do
    cout << "y = " << y << endl;

    // avoids inconsistency
    vector<int> old_one(4);    // std::vector var with elements 0,0,0,0
    vector<int> old_two(4, 2); // std::vector var with elements 2,2,2,2
    vector<int> uni_one{4};    // std::vector var with elements 4 ...
    vector<int> uni_two{4, 2}; // std::vector var with elements 4,2 ...

    cout << "old one = ";
    print(old_one);

    cout << endl
         << "old two = ";
    print(old_two);

    cout << endl
         << "uni_one = ";
    print(uni_one);

    cout << endl
         << "uni_two = ";
    print(uni_two);

    Test test1("normal"); // object creation or function declare? "most vexing parse"
    Test test2{"curly"};  // object creation

    return 0;
}

void decFunc(int i)
{
    cout << "func(int) called\n";
}

void decFunc(int *i)
{
    cout << "func(int *) called\n";
}

// typedef vector<int> intVec;
using intVec = vector<int>; // alias

int section2_6()
{
    // return new_syntax();

    vector<intVec> vec_of_vec; // instead of vector<vector<int> > in c++03 (the space in the arrows)

    // decFunc(NULL);    // null is an int ... so 0 :|
    // decFunc(nullptr); // actually an empty pointer

    return old_syntax();
}

#endif // DEC_INIT_H