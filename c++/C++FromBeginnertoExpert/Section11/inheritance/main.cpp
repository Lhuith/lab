#include <iostream>
#include "point.hpp"

using namespace std;
// inheritance

void operationOnPoint();

int main()
{
    operationOnPoint();
    return 0;
}

void operationOnPoint()
{
    Point2D p2(10, 42);
    // p2.setXY(100, 50);

    p2.Point::setX(10);

    cout << p2.getX() << ", " << p2.getY() << endl;
}