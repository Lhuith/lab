#include <iostream>

using namespace std;

enum DAYOFWEEK {MO = 1, TU, WE, TH, FR, SA, SN}; // set. yum

string getDay(DAYOFWEEK);

int main() {

    DAYOFWEEK d = SN;

    /*
    cout << d << endl;
    cout << DAYOFWEEK(TU) << endl;
    */
    int i = 0;
    cout << "Enter the day of a week " << endl;
    cin >> i;
    cout << getDay(DAYOFWEEK(i)) << endl;

    return 0;
}

string getDay(DAYOFWEEK d) {
    switch(d) {
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
    case SN:
        return "Sunday";
    default:
        return "Voidsday";
        break;
    }

}
