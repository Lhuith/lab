#include <iostream>

using namespace std;
// functions / methods
// parameters
void welcome(); // declaration
bool isNumber(string);
void enterName();
double add(double a, double b) { return a + b; }
void changeValueTo(int x)
{
    x = 10;
    cout << x << endl;
};

int main()
{
    welcome();
    // enterName();
    // enterName();
    // enterName();
    // cout << add(1, 2) << endl;

    char ch;
    cout << "end program?" << endl;
    cin >> ch;

    if (ch == 'y' || ch == 'Y')
        return 1;

    int a = 5;
    changeValueTo(a);
    cout << a << endl;
    return 0;
}

void welcome()
{
    cout << "Helo" << endl;
}

bool isNumber(string chk)
{
    if (chk[0] == '0')
        return false;

    for (int i = 0; i < chk.length(); i++)
    {
        if (!(chk[i] >= 48 && chk[i] <= 57))
        {
            return false;
            break;
        }
    }

    return true;
}

void enterName()
{
    string tmp;

    cout << "Enter the number: " << endl;
    cin >> tmp;

    if (isNumber(tmp))
        cout << "Number entered properly" << endl;
    else
        cout << "Invalid number" << endl;
}