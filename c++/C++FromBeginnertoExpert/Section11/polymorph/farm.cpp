#include "farm.hpp"

Animal::Animal()
{
}
Animal::~Animal()
{
    cout << "I am from the base" << endl;
}

Dog::Dog()
{
    sign = "Do";
    voice = "woof woof";
}

Dog::~Dog()
{
    cout << "I am from the dog" << endl;
}

Cat::Cat()
{
    sign = "Ca";
    voice = "moew moew";
}

Cat::~Cat()
{
    cout << "I am from the cat" << endl;
}

Cow::Cow()
{
    sign = "Co";
    voice = "moo moo";
}

Cow::~Cow()
{
    cout << "I am from the cow" << endl;
}