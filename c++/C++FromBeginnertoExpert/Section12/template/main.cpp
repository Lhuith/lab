#include <iostream>
#include "point.hpp"

using namespace std;
// function template // generalization

void operationOnPoint();

template <typename T, typename T2>
T add(T v1, T2 v2)
{
    return v1 + v2;
}

// template <>
// Point2D add(Point2D v1, Point2D v2)
// {
//     Point2D tmp;

//     tmp.setX(v1.getX() + v2.getX());
//     tmp.setY(v1.getY() + v2.getY());

//     return tmp;
// }

typedef Point<int> IPoint;

int main()
{
    operationOnPoint();
    // cout << add<double, double>(2, 5.1) << endl;
    // cout << static_cast<int>(7.6) << endl; // really a function template
    return 0;
}

void operationOnPoint()
{
    // Point<char> t(10);

    // IPoint a(1);
    Point<double *> b(1.1);

    // Point2D<short>
    //     b(1.1, 1.001);

    // cout << b.getX() << endl;
    // cout << b.getX() << ", " << b.getY() << endl;
    // cout << t << endl;
}