#ifndef RUN_TIME_TYPE_INFO_H
#define RUN_TIME_TYPE_INFO_H

#include <iostream>
#include <typeinfo>

using namespace std;

namespace runTimeTypeInfo {

class Shape {
   public:
    virtual ~Shape() {}
};

class Circle : public Shape {
   public:
    void func() { cout << "calling circle's func()\n"; }
};

class Triangle : public Shape {};

int main() {
    Circle circle;
    Triangle triangle;
    Shape& pShape = circle;
    // Shape* pShape = &triangle;
    // Shape& pShape = triangle;
    // // Do *pShape and circle have the same dynamic type?
    // if (typeid(*pShape) == typeid(circle))
    //     cout << "pShape points to a Circle object" << endl;
    // else
    //     cout << "pShape does not point to a Circle object" << endl;

    // const type_info& tShape = typeid(*pShape);
    // const type_info& tCircle = typeid(circle);

    // // cout << "dynamic type of pShape is " << tShape.name() << endl;
    // // cout << "dynamic type of circle is " << tCircle.name() << endl;

    // cout << "hash code of pShape is " << tShape.hash_code() << endl;
    // cout << "hash code of circle is " << tCircle.hash_code() << endl;

    // if (tShape.hash_code() == tCircle.hash_code())
    //     cout << "pShape points to a circle object" << endl;
    // else
    //     cout << "pShape does not point to a circle object" << endl;

    // Circle *pCircle = dynamic_cast<Circle *>(pShape);

    // // pCircle may be a nullptr
    // if (pCircle)
    //     pCircle->func();
    // else
    //     cout << "cout not cast pShake to circle" << endl;

    // pShape.func();

    try {
        // throws std::bad_cast on error
        Circle& pCircle = dynamic_cast<Circle&>(pShape);
        pCircle.func();
    } catch (std::exception& e) {
        cout << "caught exception: " << e.what() << endl;
    }

    return 0;
}
}     // namespace runTimeTypeInfo
#endif     // RUN_TIME_TYPE_INFO_H