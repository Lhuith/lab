#include <iostream>

using namespace std;
// scope / range of variables

int globalVar;

int main()
{
    int localVariable;

    // cout << "global " << globalVar << endl;
    // cout << "local " << localVariable << endl;

    // int a = 10;

    // if (a == 10)
    //     int result = a * 10;

    // cout << result << endl; scope is good

    int nr, result = 0;
    int i = 0;
    for (; i < 3; i++)
    {
        cout << "Enter " << (i + 1) << " number " << endl;
        cin >> nr;
        result += nr;
    }
    cout << result << endl;
    cout << "we added " << i << " numbers" << endl;

    return 0;
}