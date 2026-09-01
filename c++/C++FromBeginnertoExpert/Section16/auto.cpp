#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> wholeNumbers{1, 25, -45, 350};

    /*
        auto - automatically infers the type of variable to be assigned
    */

    int nrOfPeople = 20.5;

    cout << nrOfPeople << endl;

    for (auto vi = wholeNumbers.begin(); vi != wholeNumbers.end(); vi++)
    {
        cout << *vi << endl;
    }

    return 0;
}