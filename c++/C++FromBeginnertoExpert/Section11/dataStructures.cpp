#include <iostream>

using namespace std;
// data structures

struct personalData
{
    string name;
    string surname;
    string telephoneNumber;
    short age;
} a, b;

void test(personalData *);

int main()
{
    personalData person[5];

    a.age = 50;
    // cout << a.age << endl;

    person[0].name = "Eugene";
    person[1].name = "Bob";
    person[0].surname = "Martens";
    person[0].telephoneNumber = "12312312";
    person[0].age = 33;

    // cout << person[0].name << endl;
    // cout << person[0].surname << endl;
    // cout << person[0].telephoneNumber << endl;
    // cout << person[0].age << endl;

    // cout << (*person).name << endl;
    // cout << (*&person[0]).name << endl;
    // cout << (person + 1)->name << endl;

    personalData *p = person;
    cout << p->name << endl;

    test(p); // test(person);

    cout << p->name << endl;
    return 0;
}

void test(personalData *person)
{
    person->name = "Agnes";
}