#ifndef OVERLOADING_MEM_FUNCS_H
#define OVERLOADING_MEM_FUNCS_H

#include <iostream>
using namespace std;

namespace overloadingMemFuncs {

class vehicle {
   public:
    void accelerate() { cout << "increasing speed: "; }
};
class aeroplane : public vehicle {
   public:
    // void accelerate() { vehicle::accelerate(); };     // call parent version of accelerate
    using vehicle::accelerate;
    void accelerate(int height) {
        cout << "accelerating at a height of: " << height;
    }
};

int main() {
    aeroplane plane;
    plane.accelerate(1000);
    cout << endl;
    plane.accelerate();
    cout << endl;
    return 0;
}
}     // namespace overloadingMemFuncs
#endif     // OVERLOADING_MEM_FUNCS_H