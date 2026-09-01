#include <iostream>
#include "conioLin.hpp"
#include <fstream>

#define sec_break cout << "-----------------------------" << endl;
#define emptyDataBaseCheck                   \
    if (peopleIndex == 0)                    \
    {                                        \
        cout << "database is empty" << endl; \
        return;                              \
    }

using namespace std;

struct Person
{
    string name;
    string surname;
    short age;
    string phone;
};
Person people[20];
short peopleIndex;

void requireEnter();
void addPerson();
void showPeople();
void savePeopleToFile();
void loadPeopleFromFile();
void searchDataBase();
void removePersonFromDataBase();
int main()
{
    char test;
    loadPeopleFromFile();

    do
    {
        cout << "people in database : " << peopleIndex << endl;
        cout << "menu: " << endl;
        cout << "1. add person" << endl;
        cout << "2. show all people" << endl;
        cout << "3. save people to file" << endl;
        cout << "4. load people to file" << endl;
        cout << "5. search for person" << endl;
        cout << "6. remove person" << endl;
        cout << endl;

        test = getch_(0);

        switch (test)
        {
        case '1':
            addPerson();
            break;
        case '2':
            showPeople();
            break;
        case '3':
            savePeopleToFile();
            break;
        case '4':
            loadPeopleFromFile();
            break;
        case '5':
            searchDataBase();
            break;
        case '6':
            removePersonFromDataBase();
            break;
        default:
            if (test != 27)
            {
                cout << "not valid option for " << test << endl;
            }
        }
        cout << endl;
        if (test != 27)
        {
            requireEnter();
        }

        system("clear");
    } while (test != 27);

    return 0;
}

void requireEnter()
{
    cout << "click enter to continue..." << endl;
    while (getch_(0) != '\n')
    {
    }
}

void addPerson()
{
    cout << "name: ";
    cin >> people[peopleIndex].name;

    cout << "surname: ";
    cin >> people[peopleIndex].surname;

    cout << "age: ";
    cin >> people[peopleIndex].age;

    cout << "phone: ";
    cin >> people[peopleIndex].phone;

    peopleIndex++;
}

void showPeople()
{
    emptyDataBaseCheck;

    for (int i = 0; i < peopleIndex; i++)
    {
        sec_break;
        cout << "peep-index: " << (i + 1) << endl;
        cout << "name: " << people[i].name << endl;
        cout << "surname: " << people[i].surname << endl;
        cout << "age: " << people[i].age << endl;
        cout << "phone: " << people[i].phone << endl
             << endl;
        sec_break;
    }
}

void savePeopleToFile()
{
    emptyDataBaseCheck;

    ofstream file("database.txt");

    if (file.is_open())
    {
        file << peopleIndex << endl;

        for (int i = 0; i < peopleIndex; i++)
        {
            file << people[i].name << endl;
            file << people[i].surname << endl;
            file << people[i].age << endl;
            file << people[i].phone << endl;
        }
        cout << "people were saved" << endl;
        file.close();
    }
    else
        cout << "couldn't save to database" << endl;
}

void loadPeopleFromFile()
{
    ifstream file("database.txt");

    if (file.is_open())
    {
        file >> peopleIndex;

        emptyDataBaseCheck;

        int i = 0;
        do
        {
            file >> people[i].name;
            file >> people[i].surname;
            file >> people[i].age;
            file >> people[i].phone;
            i++;
        } while (!(file.eof()));

        // for (int i = 0; i < peopleIndex; i++)
        // {
        //     file >> people[i].name;
        //     file >> people[i].surname;
        //     file >> people[i].age;
        //     file >> people[i].phone;
        // }

        cout << "people were loaded" << endl;

        file.close();
    }
    else
        cout << "file database.txt doesn't exist" << endl;
}

void searchDataBase()
{
    emptyDataBaseCheck;

    string name;
    cout << "name of person: ";
    cin >> name;

    for (int i = 0; i < peopleIndex; i++)
    {
        if (name == people[i].name)
        {
            sec_break;
            cout << "peep-index: " << (i + 1) << endl;
            cout << "name: " << people[i].name << endl;
            cout << "surname: " << people[i].surname << endl;
            cout << "age: " << people[i].age << endl;
            cout << "phone: " << people[i].phone << endl
                 << endl;
            sec_break;
        }
    }
    while (getch_(0) != '\n')
    {
    }
}

void removePersonFromDataBase()
{
    emptyDataBaseCheck;

    short index;
    cout << "person index: " << endl;
    cin >> index;

    if (peopleIndex >= index && index != 0)
    {
        for (short k = index; k < peopleIndex; k++)
        {
            people[k - 1].name = people[k].name;
            people[k - 1].surname = people[k].surname;
            people[k - 1].age = people[k].age;
            people[k - 1].phone = people[k].phone;
        }
        peopleIndex--;
        savePeopleToFile();
    }
    else
    {
        cout << "no person at that index!" << endl;
    }
    while (getch_(0) != '\n')
    {
    }
}