#include <iostream>
#include "position.hpp"

using namespace std;

void setX(Position &, int);
int main()
{
    Position dog(10, 15);

    dog.getPosition();

    setX(dog, 1500);

    dog.getPosition();

    const Position house(100, 200);
    house.getPosition();
    // house.setPosition(150, 1100);
    // house.getPosition();
    return 0;
}

void setX(Position &o, int x)
{
    o.x = x;
}