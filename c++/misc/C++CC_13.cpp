#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


class Animal 
{
public:
	virtual void MakeSound() { cout << "The Animal Says Grr" << endl; }
};

class Dog : public Animal
{
public:
	void MakeSound() { cout << "The Dog Says Woof" << endl; }
};

class Cat : public Animal
{
public:
	void MakeSound() { cout << "The Cat Says Moew" << endl; }
};

//example of Abstract Data type
class Car
{
	public:
		virtual int getNumWheels() = 0;
		virtual int getNumDoors() = 0;
};

class StationWagon : public Car
{
public:
	int getNumWheels() { cout << "Station wagon has 4 Wheels" << endl; }
	int getNumDoors() { cout << "Station wagon has 4 Doors" << endl; }

	StationWagon() {}
	~StationWagon();
};
int main()
{
	cout << "PolyMorphism Part 2" << endl;

	Animal* pCat = new Cat;
	Animal* pDog = new Dog;

	pCat->MakeSound();
	pDog->MakeSound();

	Car* stationWagon = new StationWagon();

	stationWagon->getNumWheels();


		return 0;
}