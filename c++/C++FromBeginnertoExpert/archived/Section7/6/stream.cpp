#include <iostream>
#include <limits>

using namespace std;

int main() {

    string name;
    cout << "enter name: " << endl;
    cin >> name;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int age;
    cout << "enter age: " << endl;
    if (cin >> age) {
        cout << "you are " << age << ", years old." << endl;
    } else {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "age should be a numerical value!" << endl;
        cin >> age;
    }


    return 0;
}
