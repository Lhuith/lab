#ifndef LAMBDA_XPRES_CAPTURE_CONT_H
#define LAMBDA_XPRES_CAPTURE_CONT_H

#include <iostream>
using namespace std;

namespace lambdaXpresCaptureCont {

class Test {
    int time{10};     // data member
   public:
    void countdown() {          // member function which calls lambda expression
        [*this]() mutable {     // capture class object by reference
            if (time > 0)
                cout << time << endl;
            else if (time == 0)
                cout << "liftoff!" << endl;
            --time;
        }();     // call the lambda expression
    }
};

int main() {
    Test test;
    for (int i = 0; i < 12; ++i)
        test.countdown();

    return 0;
}
}     // namespace lambdaXpresCaptureCont
#endif     // LAMBDA_XPRES_CAPTURE_CONT_H