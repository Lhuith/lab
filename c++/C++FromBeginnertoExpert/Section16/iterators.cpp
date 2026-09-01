#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> wholeNumbers{1, 25, -45, 350};

    /*
        ITERATOR - objects indicating specific element inside a container

        how to create ITERATOR
        containerType::iterator iteratorName;
    */

    // ITERATOR repetition

    // for (int i = 0; i < 10; i++)
    // {
    //     // code here

    //     cout << "iterator (repetition) " << (i + 1) << endl;
    // }

    vector<int>::iterator vi = wholeNumbers.begin(); // point to the start
    for (int i = 0; i < wholeNumbers.size(); i++, vi++)
    {
        cout << *vi << endl;
    }

    // cout << *vi << endl;

    // vi++;

    // cout << *vi << endl;

    // vi += 2;

    // cout << *vi << endl;

    // vi--;

    // cout << *vi << endl;

    return 0;
}