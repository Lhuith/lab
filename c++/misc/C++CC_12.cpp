#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


class Animal 
{
public:
	void GetFamily() {cout << "We Are Animals" << endl;}

	//virtual methods are used if subclasses are able to overite a certain method

	virtual void getClass() { cout << "I'm an Animal" << endl; }
};

class Dog : public Animal
{
public:
	void getClass() { cout << "I'm a Dog" << endl; }
};

class GermanShepard : public Dog
{
public:
	void getClass() { cout << "I'm a German Shepard"; }
	void getDerived() { cout << " I'm an Animal and a Dog"; }
};

//should expect to get the same results

void whatClassAreYou(Animal *animal)
{
	//Polymorphism basically means 
	//Getting the right method to call

	animal->getClass();
}

int main()
{

	cout << "Virtual Methods and PolyMorphism" << endl;

	Animal *animal = new Animal;
	Dog *dog = new Dog;

	animal->getClass();
	dog->getClass();

	//Both passes create "im an animal"

	whatClassAreYou(animal);
	whatClassAreYou(dog);

	Dog spot;
	GermanShepard max;

	//the base class can also call derived class methods 
	//aslong as they exist in the base class

	//Examples of Polymorphism

	Animal* ptrDog = &spot;
	Animal* ptrGShepard = &max;

	ptrDog->GetFamily();

	ptrDog->getClass();

	//calling the super class
	//since everything is inhertied

	ptrGShepard->GetFamily();
	ptrGShepard->getClass();
		return 0;
}