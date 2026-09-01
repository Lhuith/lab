#include <iostream>

using namespace std;

void welcome(); // decleration of function
bool isNumber(string);
void enterName();
double add(double a, double b) {return a + b;} // inline
void changeValueTo(int x) {x = 10;}

int main() {
    //welcome();
    //cout << add(1.2, 2.1) << endl;
    //enterName();

    char ch;
    cout << "do you want to end?" << endl;
    cin >> ch;
    if(ch == 'y' || ch == 'Y') {
        return 0;
    }


    int a = 5;
    changeValueTo(a);
    cout << a << endl;

    return 0;
}

void welcome() {
    cout << "Hello, welcome, stay a while" << endl;
}

bool isNumber(string tmp){
    if(tmp.length() == 0 || tmp[0] == '0') return false;

    for(int i = 0; i < tmp.length(); i++) {
        if(!(tmp[i] >= 48 && tmp[i] <= 57)) {
             return false;
        }
    }
    return true;
}

void enterName() {
    string tmp;

    cout << "enter the number: " << endl;
    cin >> tmp;

    if(isNumber(tmp))
        cout << "is a number!" << endl;
    else
        cout << "not a number!" << endl;
}

