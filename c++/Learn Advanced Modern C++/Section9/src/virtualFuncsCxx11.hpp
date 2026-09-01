#ifndef VIRTUAL_FUNCS_CXX11_H
#define VIRTUAL_FUNCS_CXX11_H

#include <iostream>
using namespace std;

namespace virtualFuncsCxx11 {

class shape {
   public:
    virtual void draw() const;
};

class circle : public shape {
   public:
    // using shape::draw;
    // void draw() const override { cout << "drawing a circle ... \n"; }     // ok - overrides shape::draw()
    void draw() const override final;     // error! does not override
};

class deluxeCircle : public circle {     // error! override final function
   public:
    // void draw() const override;
};

int main() {
    // circle c;
    // c.draw();

    return 0;
}
}     // namespace virtualFuncsCxx11
#endif     // VIRTUAL_FUNCS_CXX11_H