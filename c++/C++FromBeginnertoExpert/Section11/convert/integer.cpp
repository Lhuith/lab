#include "integer.hpp"
#include <iostream>

using namespace std;

Integer::Integer(int nr)
{
    this->nr = nr;
}

Integer::~Integer()
{
}

Integer::operator int()
{
    return this->nr;
}

int Integer::operator+=(Integer i)
{
    this->nr = i.getNr() + this->nr;
    return this->nr;
}