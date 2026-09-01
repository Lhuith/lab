#ifndef FARM_H_INCLUDED
#define FARM_H_INCLUDED
#include <iostream>

using namespace std;

class Animal
{

protected:
    string voice;

public:
    Animal();
    virtual ~Animal();             // always create virtual destructors
    virtual string getVoice() = 0; // let compiler know this will change
    // = 0 creates an abstraction, meaning the class cannot be created
};

class Dog : public Animal
{
    string sign;

public:
    Dog();
    ~Dog();
    string getVoice() { return voice + " " + sign; };
};

class Cat : public Animal
{
    string sign;

public:
    Cat();
    ~Cat();
    string getVoice() { return voice + " " + sign; };
};

class Cow : public Animal
{
    string sign;

public:
    Cow();
    ~Cow();
    string getVoice() { return voice + " " + sign; };
};

#endif