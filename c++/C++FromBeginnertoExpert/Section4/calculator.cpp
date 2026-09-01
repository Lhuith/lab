#include <iostream>

using namespace std;

int main()
{
    double v1, v2;

beginning:

    cout << "Enter first number: ";
    cin >> v1;

    cout << "Enter Second number: ";
    cin >> v2;

    cout << "what you wanna do?" << endl;
    cout << "+" << endl;
    cout << "-" << endl;
    cout << "*" << endl;
    cout << "/" << endl;

    char decision;
    cin >> decision;

    system("printf \"\\033c \""); // printf "\033c" for ubuntu, cls for windows

    switch (decision)
    {
    case '+':
        cout << v1 << "+" << v2 << " = " << (v1 + v2) << endl;
        break;
    case '-':
        cout << v1 << "-" << v2 << " = " << (v1 - v2) << endl;
        break;
    case '*':
        cout << v1 << "*" << v2 << " = " << (v1 * v2) << endl;
        break;
    case '/':
        if (v2) // false when v2 is 0, super hot
            cout << v1 << "/" << v2 << " = " << (v1 / v2) << endl;
        else
            cout << "can't divide by 0!" << endl;

        break;
    default:
        cout << "action not available" << endl;
    }

    cout << "continue ? (y/n): ";
    char decision2;
    cin >> decision2;

    if (decision2 == 'y' || decision2 == 'Y')
        goto beginning;

    return 0;
}