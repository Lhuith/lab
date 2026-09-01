#include "point.hpp"
#include <iostream>

using namespace std;

Point::Point(int x)
{
    this->x = x;
    cout << "the constructor from 1D class" << endl;
}

Point::~Point()
{
    cout << "the destructor from 1D class" << endl;
}

void Point::setX(int x)
{
    this->x = x;
    cout << "I am from point1D" << endl;
}

Point2D::Point2D(int x, int y) : Point(x)
{
    this->y = y;
    cout << "the constructor from 2D class" << endl;
}

Point2D::~Point2D()
{
    cout << "the destructor from 2D class" << endl;
}

void Point2D::setY(int y)
{
    this->y = y;
}

void Point2D::setXY(int x, int y)
{
    this->setX(x);
    this->setY(y);
}

void Point2D::setX(int x)
{
    this->x = x;
    cout << "I am from point2D" << endl;
}