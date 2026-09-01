#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> wholeNumbers{1, 25, -45, 350};

    // ITERATOR repetition

    // for (int i = 0; i < 10; i++)
    // {
    //     // code here

    //     cout << "iterator (repetition) " << (i + 1) << endl;
    // }

    /*
    while (vi != wholeNumbers.end())
    {
        cout << *vi << endl;
        vi++;
    }
    */

    for (vector<int>::iterator vi = wholeNumbers.begin(); vi != wholeNumbers.end(); vi++)
    {
        if (*vi == wholeNumbers.at(3))
        {
            continue;
        }
        cout << *vi << endl;
    }

    return 0;
}