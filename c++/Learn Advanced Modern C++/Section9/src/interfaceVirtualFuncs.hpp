#ifndef INTERFACE_VIRTUAL_FUNCS_H
#define INTERFACE_VIRTUAL_FUNCS_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

namespace interfaceVirtualFuncs {

class shape {     // abstract class now, due to pure virtual function
   public:
    virtual void draw() const = 0;     // pure virtual function
    // virtual void draw() const { cout << "shape::draw()\n"; }
};

class circle : public shape {
   public:
    void draw() const override { cout << "circle::draw()\n"; }
};

// class triangle : public shape {
//    public:
// void draw() const override { cout << "drawing triangle ... \n"; }
// };

// function taking base class by value
void draw_shape(const shape& s) {
    s.draw();     // always calls shape draw()
    (&s)->draw();
}

int main() {
    // shape s;     // does not compile! - cannot create variable of abstract type
    // triangle t;

    circle c;
    draw_shape(c);

    return 0;
}
}     // namespace interfaceVirtualFuncs
#endif     // INTERFACE_VIRTUAL_FUNCS_H