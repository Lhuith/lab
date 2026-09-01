#include <iostream>

using namespace std;

int main()
{
    /*
        AND conjunction &&
            7 > 5 && 5 != 10 - must be wholly true

        exp 1 | exp 2 | res
         0       0       0
         0       1       0
         1       0       0
         1       1       1

        OR disjunction/alterantive ||

        exp 1 | exp 2 | res
         0       0       0 <-- false
         0       1       1
         1       0       1
         1       1       1

        NOT/FLIP ! exclamation mark
        ! (0) = 1
        ! (1) = 0
    */

    cout << (7 > 5 && 5 != 10) << endl;
    cout << (7 < 5 || 5 == 10) << endl;
    return 0;
}