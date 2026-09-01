#ifndef MULTIPLE_INHERITANCE_H
#define MULTIPLE_INHERITANCE_H

#include <iostream>
using namespace std;

namespace multipleInheritance {

struct Params {};

// hardware class
class HardwareDevice {
   public:
    HardwareDevice() { cout << "calling HardwareDevice constructor\n"; }
    ~HardwareDevice() { cout << "calling HardwareDevice destructor\n"; }
    bool initialize(Params&) {
        cout << "calling HardwareDevice::initialize()\n";
        return true;
    }
    void get_data() {
        cout << "calling HardwareDevice::get_data()\n";
    }
};

// User interaction class
class TouchResponder {
   public:
    TouchResponder() { cout << "calling TouchResponder constructor\n"; }
    ~TouchResponder() { cout << "calling TouchResponder destructor\n"; }
    void initialize() {
        cout << "calling TouchResponder::initialize()\n";
    }
    bool touch_down() {
        cout << "calling TouchResponder::touch_down()\n";
        return true;
    }
};

// Classes with inherit from both HardwareDevice and TouchResponder
class Mouse : public HardwareDevice, TouchResponder {
   public:
    Mouse() { cout << "calling Mouse constructor\n"; }
    ~Mouse() { cout << "calling mouse destructor\n"; }
    bool initialize(Params& params) {
        cout << "calling Mouse::initialize()\n";
        HardwareDevice::initialize(params);
        TouchResponder::initialize();
        return true;
    }
    void process() {          // member function in mouse class
        if (touch_down())     // mouse inherits touch_down() from TouchResponder
            get_data();       // mouse inherits get_data() from HardwareDevice
    }
};
class Keyboard : public HardwareDevice, TouchResponder { /* ... */
};
class TouchScreen : public HardwareDevice, TouchResponder { /* ... */
};

int main() {
    Mouse mouse;
    Params params;
    // mouse.process();
    mouse.initialize(params);
    return 0;
}
}     // namespace multipleInheritance
#endif     // MULTIPLE_INHERITANCE_H