#ifndef VIRTUAL_DESTRO_H
#define VIRTUAL_DESTRO_H

#include <iostream>
#include <vector>

using namespace std;

namespace virtualDestro {

class shape {
   public:
    virtual void draw() const { cout << "drawing a generic shape ...\n"; };
    virtual ~shape() { cout << "goodbye from shape object!\n"; };
};

class circle : public shape {
   public:
    void draw() const override { cout << "drawing a circle ... \n"; };     // always declare override!
    ~circle() { cout << "goodbye from circle object!\n"; }
};

int main() {
    vector<shape*> shapes;     // vector of pointers to drawable

    shapes.push_back(new circle);     // store a circle in vector

    for (auto shape : shapes)
        shape->draw();

    for (auto shape : shapes)     // release allocated memory
        delete shape;

    return 0;
}
}     // namespace virtualDestro
#endif     // VIRTUAL_DESTRO_H