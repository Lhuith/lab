#ifndef BASED_AND_DERIVED_H
#define BASED_AND_DERIVED_H

#include <iostream>
using namespace std;

namespace basedAndDerived {

class vehicle {     // this will be the base class
    int max_speed;

   public:
    vehicle(int max_speed) : max_speed(max_speed) {     // initialize max_speed
        cout << "vehicle constructor\n";
    }
    // ... member functions
};

class aeroplane : public vehicle {     // this will be the derived class
    int max_height;

   public:
    // initialize the vehicle part of the instance, then initialize max_height
    aeroplane(int max_speed, int max_height) : vehicle(max_speed), max_height(max_height) {
        cout << "aeroplane constructor\n";
    }
    // ... member functions
};

class fighterplane : public aeroplane {     // more specialized aeroplane
    // ... member functions
}

int
main() {
    cout << "creating vehicle object\n";
    vehicle veh(10);
    cout << "creating aeroplane object\n";
    aeroplane aero(40000, 500);

    return 0;
}
}     // namespace basedAndDerived
#endif     // BASED_AND_DERIVED_H