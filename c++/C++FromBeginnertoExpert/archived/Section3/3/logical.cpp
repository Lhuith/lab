#include <iostream>

using namespace std;

main() {
    /*
        AND conjuction &&

        // logical sentance
        7 > 5 (&&)<-conjuction 5 != 10 : expressions (1) if both are true ONLY

        exrp1 expr2 result
          0     0     0
          0     1     0
          1     0     0
          1     1     1

        OR || disjunction/alternative

        disjuction is false only when both are false
         exrp1 expr2 result
          0     0     0
          0     1     1
          1     0     1
          1     1     1

        ! (exclemation negation) / NOT / FLIP
    */

    cout << !(5 > 7 || 5 == 10) << endl;
}
