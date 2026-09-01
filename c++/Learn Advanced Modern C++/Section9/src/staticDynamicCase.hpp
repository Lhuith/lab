#ifndef STATIC_DYNAMIC_CASE_H
#define STATIC_DYNAMIC_CASE_H

#include <iostream>
#include <vector>
using namespace std;

namespace staticDynamicCase {

class shape {
   public:
    virtual void draw() { cout << "drawing a generic shape ... \n"; }
    virtual ~shape() { cout << "forced to add this :("; }
};

class circle : public shape {
   public:
    void draw() { cout << "drawing a circle .. \n"; }
};

int main() {
    vector<shape*> shapes;     // vector of pointers to shape objects

    // create a pointer to a child class of shape and append to the vector
    shapes.push_back(new circle());

    for (auto shape : shapes)
        shape->draw();     // calls circle::draw()

    for (auto shape : shapes)     // release memory
        delete shape;

    cout << endl;

    return 0;
}
}     // namespace staticDynamicCase
#endif     // STATIC_DYNAMIC_CASE_H