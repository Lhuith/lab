#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    /*
        Absolute value

        -5 = 5
        +5 = 5
        +0 = 0
    */

    int x;
    cout << "Enter the number: " << endl;

    cin >> x;

    // if (x < 0)
    //     x = x * (-1);

    cout << "abs value is: " << abs(x) << endl;

    return 0;
}