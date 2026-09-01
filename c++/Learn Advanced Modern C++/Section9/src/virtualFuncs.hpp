#ifndef VIRTUAL_FUNCS_H
#define VIRTUAL_FUNCS_H

#include <iostream>
using namespace std;

namespace virtualFuncs {

class shape {
   public:
    virtual void draw() const { cout << "drawing a generic shape ... \n"; }
    virtual ~shape() {}
};

class circle : public shape {
   public:
    void draw() const { cout << "drawing a circle ... \n"; }
};

class triangle : public shape {
   public:
    void draw() const { cout << "drawing a triangle ... \n"; }
};

void draw_shape(const shape& s) {     // argument is a reference to a shape
    s.draw();                         // calls draw member function of circle etc
}

int main() {
    circle c;       // derived class
    triangle t;     // derived class

    draw_shape(c);     // draw_shape
    draw_shape(t);     // draw_shape

    return 0;
}
}     // namespace virtualFuncs
#endif     // VIRTUAL_FUNCS_H