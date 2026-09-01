#ifndef POINT_REF_INHERITANCE_H
#define POINT_REF_INHERITANCE_H

#include <iostream>
#include <vector>

using namespace std;

namespace pointRefInheritance {

class shape {
   public:
    void draw() const { cout << "drawing a generic shape...\n"; }
};
class circle : public shape {
   public:
    void draw() const { cout << "drawing a circle ... \n"; }
    // void area() { cout << "calculating area of circle ...\n"; }
};

void draw_shape(const shape& s) {
    s.draw();     // calls draw member function of shape
}

void draw_shape(const circle& c) {
    c.draw();     // calls draw member function of circle
}

/*
        void draw_shape(const Triangle& t) {
                t.draw();				// calls draw member function of triangle
        }
*/

int main() {
    // circle c;               // derived class object
    // shape* pshape = &c;     // pointer to base class, points to a circle object
    // // cout << pshape << endl;
    // pshape->draw();     // calls shape's version of draw()
    // // pshape->area();     // error! not of a member of shape

    // // shape s;                  // base class object
    // // circle* pcircle = &s;     // ERROR!
    // // cout << pcircle << endl;

    // circle c;
    // shape& rshape = c;

    // draw_shape(c);
    // draw_shape(rshape);

    vector<shape*> shapes;     // vector of pointers to shape instances

    // create a pointer to a child class of shape and append it to the vector
    shapes.push_back(new circle);

    for (auto s : shapes)
        static_cast<circle*>(s)->draw();     // calls shape::draw();

    for (auto s : shapes)     // release allocated memory
        delete s;

    return 0;
}
}     // namespace pointRefInheritance
#endif     // POINT_REF_INHERITANCE_H