#include "test.hpp"
#include <iostream>

using namespace std;

Test::Test(const Test &o) // copy constructor
{
    cout << "copy constructor called" << endl;
    this->x = o.x;
    this->y = o.y;
    this->p = new int(*(o.p));
}

Test::Test(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->p = new int(z); // implicit address copy when o2 = o1, this could be bad if not intended
}

Test ::~Test()
{
    delete this->p; // implicit address copy also means this will be deleted twice;
}