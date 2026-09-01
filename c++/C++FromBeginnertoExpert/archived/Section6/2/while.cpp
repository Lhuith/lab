#include <iostream>

using namespace std;

main(){
    const int SIZEOFARRAY = 10;
    int i = 0;
    int array[SIZEOFARRAY];

    /* check before
    // using the fact that 0 = false, we can do inferned countdowns
    while(i < SIZEOFARRAY){
        array[i] = 10 * i;
        cout << array[i++] << endl;
    }
    */

    do { // check after
        cout << "lala" << endl;
    } while(i);
}
