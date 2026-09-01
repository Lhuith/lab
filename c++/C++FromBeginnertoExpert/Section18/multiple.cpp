#include <iostream>
#include <string>

using namespace std;

int main()
{

    /*
        multiples of 5: 0 5 10 15 ...

        %


    */

    int numberToFindMultOf = 1;
    int nrProvided = 50;

    for (int i = 0; i <= nrProvided; i++)
    {
        if (i % numberToFindMultOf == 0)
            cout << i << " is multiple of " << numberToFindMultOf << endl;
    }

    return 0;
}