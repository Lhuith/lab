#include <iostream>

using namespace std;
// enum / enumerator / counting 1 2 3 4 5

enum dayOfWeek
{
    MO = 1,
    TU,
    WE,
    TH,
    FR,
    SA,
    SU
};

string getDay(dayOfWeek);

int main()
{
    // dayOfWeek d = SU;

    // cout << getDay(d) << endl;

    // cout << dayOfWeek(TU) << endl;

    cout << "Enter the day of a week " << endl;
    cout << "1 - Monday" << endl;
    cout << "2 - Tuesday" << endl;
    cout << "3 - Wednesday" << endl;
    cout << "4 - Thursday" << endl;
    cout << "5 - Friday" << endl;
    cout << "6 - Saturday" << endl;
    cout << "7 - Sunday" << endl;
    cout << "? - Voidsday" << endl;
    int i;
    cin >> i;
    cout << getDay(dayOfWeek(i)) << endl;

    return 0;
}

string getDay(dayOfWeek d)
{
    switch (d)
    {
    case MO:
        return "Monday";
    case TU:
        return "Tuesday";
    case WE:
        return "Wednesday";
    case TH:
        return "Thursday";
    case FR:
        return "Friday";
    case SA:
        return "Saturday";
    case SU:
        return "Sunday";
    default:
        return "Voidsday";
    }
}