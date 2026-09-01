#ifndef CONVERSION_OPS_H
#define CONVERSION_OPS_H

#include <iostream>
#include <string>

using namespace std;

namespace conversionOps {
class Test {
    int i{42};
    string str;

   public:
    explicit Test(int i) : i(i) {}
    explicit operator int() const { return i; }      // explicit conversion ops to int
    explicit operator bool() const { return i; }     // explicit conversion ops to bool, note: for conditionals, explicit casting isn't required i.e. if(test) instead of if(static_cast<bool>(test))
};

int main() {
    Test test = Test{4};
    // cout << test << endl;                    // error: no match for operator <<
    cout << static_cast<int>(test) << endl;

    if (test)
        cout << "this is allowed!" << endl;

    return 0;
}
}     // namespace conversionOps
#endif     // CONVERSION_OPS_H