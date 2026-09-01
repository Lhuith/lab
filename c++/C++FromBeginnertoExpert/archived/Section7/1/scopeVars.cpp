#include <iostream>

using namespace std;

int globalVariable; //defualted // inited

main() {
    int localVariable; // ?? not defualted // not initted
 /*
    cout << "value of global var: " << globalVariable << endl;
    cout << "value of local var: " << localVariable << endl;
*/
    int a = 10;

    /*
    if(a == 10) {
        int result = a * 10;
    }
     cout << result << endl;
     */

     int nr, i = 0, result = 0; // need to init locals!

     for(; i < 3; i++) {
        cout << "enter " << (i + 1) << " number" << endl;
        cin >> nr;
        result += nr;
     }
    cout << result << endl;
    cout << "we added " << i << " numbers" << endl;
}
