#include <iostream>

using namespace std;

int main()
{
    char x = 'd';
    /*
        4.123123123123123123123123123
        4.123123123112312312512314512
    */

    switch (x)
    {
    case 'd':
        cout << "this is for d" << endl;
        break;
    case 'a':
        cout << "this is for a" << endl;
        break;
    case 25:
        cout << "this is for 25" << endl;
        break;
    case 50:
        cout << "this is for 50" << endl;
        break;
    default:
        cout << "this is for everything else" << endl;
    }

    return 0;
}