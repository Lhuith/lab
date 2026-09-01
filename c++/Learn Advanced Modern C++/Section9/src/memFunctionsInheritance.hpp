#ifndef MEM_FUNCTIONS_INHERITANCE_H
#define MEM_FUNCTIONS_INHERITANCE_H

#include <iostream>
using namespace std;

class vehicle {
   public:
    void start() { cout << "engine start: "; };

   protected:
    void kids_only();     // can only be called by this class and it's children
};

class aeroplane : public vehicle {
   public:
    // void start(); inherited from vehicle ///
    void do_something() { kids_only(); };     // child can call protected member function
    void start() {
        cout << "carrying out checks... ";
        vehicle::start();
        cout << "ready to take-off!";
    }
};

namespace memFunctionsInheritance {
int main() {
    // aeroplane plane;
    // plane.start();
    // cout << "\n";

    // vehicle car;
    // car.kids_only();     // cannot be called by "outsider" code

    return 0;
}
}     // namespace memFunctionsInheritance
#endif     // MEM_FUNCTIONS_INHERITANCE_H