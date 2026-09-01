#ifndef UNIQ_POINTER_POLY_H
#define UNIQ_POINTER_POLY_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

namespace uniqPointerPoly {

class shape {
   public:
    virtual void draw() const = 0;
    virtual ~shape() = default;
};

class circle : public shape {
   public:
    void draw() const { cout << "drawing a circle ... \n"; }
};

class triangle : public shape {
   public:
    void draw() const { cout << "drawing a triangle ... \n"; }
};

class square : public shape {
   public:
    void draw() const { cout << "drawing a square ... \n"; }
};

// factory function with pointer
shape* create_shapeA(int sides) {
    // the returned pointer will be copied into the function's return space
    if (sides == 1)
        return new circle;     // create 1-sided shape
    else if (sides == 3)
        return new triangle;     // create 3-sided shape
    else if (sides == 4)
        return new square;     // create 4-sided shape
    else {
        cout << "cannot create a shape with " << sides << " sides\n";
        return nullptr;
    }
}

// factory function with unique_ptr
unique_ptr<shape> create_shapeB(int sides) {
    // the returned unique_ptr will be moved into the functions return space
    if (sides == 1)
        return make_unique<circle>();     // create 1-sided shape
    else if (sides == 3)
        return make_unique<triangle>();     // create 3-sided shape
    else if (sides == 4)
        return make_unique<square>();     // create 4-sided shape
    else {
        cout << "cannot create a shape with " << sides << " sides\n";
        return nullptr;
    }
}

void factory_pointer() {
    // the returned point will be copied into a variable in the caller
    shape* pshape = create_shapeA(3);

    if (pshape)
        pshape->draw();

    delete pshape;     // memory leak if the pointer is not deleted

    auto pshape2{create_shapeB(3)};

    if (pshape2)
        pshape2->draw();
    // memory allocation is automatically released at end of scope
}

int main() {
    // vector<shape*> shapes;

    // shapes.push_back(new circle);
    // shapes.push_back(new triangle);
    // shapes.push_back(new square);

    // for (auto& it : shapes)
    //     it->draw();

    // for (auto& it : shapes)     // memory leak iof pointed are not deleted
    //     delete it;

    // cout << endl;

    // vector<unique_ptr<shape>> shapes2;

    // shapes2.push_back(make_unique<circle>());
    // shapes2.push_back(make_unique<triangle>());
    // shapes2.push_back(make_unique<square>());

    // for (auto& it : shapes2)
    //     it->draw();

    factory_pointer();

    return 0;
}
}     // namespace uniqPointerPoly
#endif     // UNIQ_POINTER_POLY_H