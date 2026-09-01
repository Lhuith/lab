#include "user.hpp"
#include <iostream>

using namespace std;

int User::counter = 0; // init static variable

User::User()
{
    counter++;
    ID = counter;
    // cout << "user construction" << endl;
}

User::~User()
{
}