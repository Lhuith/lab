#include "position.hpp"
#include <iostream>

using namespace std;

Position::Position(int x, int y)
{
    this->setPosition(x, y);
}
Position ::~Position()
{
}

void Position::getPosition() const
{
    cout << "x: " << this->x << endl;
    cout << "y: " << this->y << endl;
}

void Position::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}