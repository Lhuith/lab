#include "people.hpp"
#include <iostream>

using namespace std;

PersonalData::PersonalData()
{
    static int i = 0;
    cout << "this constructor has just been invoked " << ++i << endl;
    age = 10;
    p = new int[5];
}

PersonalData::PersonalData(short age)
{
    cout << "this is overload constructor has just been invoked " << endl;
    this->age = age;
}

PersonalData::~PersonalData() // garbage collection spot
{
    static int j = 0;
    cout << "this deconstructor has just been invoked " << ++j << endl;

    delete[] p;
}
void PersonalData::setAge(int age)
{
    {
        if (age < 0)
            this->age = 0;
        else
            this->age = age;
    }
}
