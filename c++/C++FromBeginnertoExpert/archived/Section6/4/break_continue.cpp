#include <iostream>

using namespace std;

main() {
    /*
        1 2 3 4 5  6  7  8  9  10
        2 4 6 8 10 12 14 16 18 20
        3 6 9 12 15
        4 ...
        5 ...

    for (int i = 1; i <= 10; i++){ // rows, length of column
        if (i == 5) continue; // if true, ignore below

        for(int j = 1; j <= 10; j++) { // column, length of row
            cout.width(4);
            cout << i * j;
        }

        cout << endl;
    }
    */

    for(int i = 1, j = 1; i <= 10; i++) {
        cout.width(4);
        cout << i * j;

        if (i == 10) {
            j++;
            i = 0;
            cout << endl;
        }

        if (j == 10 + 1)
            break;
    }
}
