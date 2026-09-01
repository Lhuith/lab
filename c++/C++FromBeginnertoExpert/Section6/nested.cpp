#include <iostream>

using namespace std;
// nested loops

int main()
{
    int nr = 123456; // 4 digits
    int digits = 1;

    // cout << 1234 / 10 << endl;
    // cout << 123 / 10 << endl;
    // cout << 12 / 10 << endl;
    // cout << 1 / 10 << endl;

    int tmp = nr;
    while (tmp /= 10)
        digits++;

    // cout << "the number " << nr << " has " << digits << " digits" << endl;

    /*
        1 2 3 4  5  6  7  8  9 10
        2 4 6 8 10 12 14 16 18 20
        3 6 9 12 15 ...
        4 ...
        5 ..
        ...
        ..
    */
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            cout.width(4);
            cout << i * j;
        }

        cout << endl;
    }

    return 0;
}