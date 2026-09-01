#include <iostream>

using namespace std;

int main()
{
    /*
        Exercise
        1 check if number is odd
        2 write as many odd numbers one after another as user requests
            user input 7
            output 1, 3, 5, 7, 9, 11, 13
        3 number odd numbers
        1 - 1
        2 - 3
        3 - 5
        4 - 7
        5 - 9
        6 - 11
        7 - 13

        %

        1 % 2 == 1
        2 % 2 == 0
        3 % 2 == 1
        4 % 2 == 0
        5 % 2 == 1
    */

    int howManyOddNumbers;
    int oddCount = 1;

    cout << "how many odd numbers?" << endl;
    cin >> howManyOddNumbers;

    cout << "\033[93m"
         << "* -------------------------------- *" << endl;
    // for (int i = 0; i < howManyOddNumbers * 2; i++)
    // {
    //     if (i % 2 == 1)
    //     {
    //         cout.width(3);
    //         cout << "\033[95m" << oddCount++ << " - " << i << endl;
    //     }
    // }
    for (int i = 1; i < howManyOddNumbers * 2; i += 2)
    {
        cout.width(4);
        cout << "\033[95m" << oddCount++ << " - " << i << endl;
    }
    cout << "\033[93m"
         << "* -------------------------------- *"
         << endl;

    return 0;
}