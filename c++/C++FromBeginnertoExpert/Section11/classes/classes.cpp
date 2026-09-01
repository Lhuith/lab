#include <iostream>
#include "people.hpp"

using namespace std;
// classes

void test()
{
    PersonalData *pointer = new PersonalData[5];

    delete[] pointer;
}

int main()
{
    PersonalData person(10); // instance of class
    PersonalData person2(50);

    // person.setAge(50);
    // person2.setAge(25);

    // person.age = 50;
    // person2.age = 25;

    cout << person.getAge() << endl;
    cout << person2.getAge() << endl;

    // test();
    return 0;
}