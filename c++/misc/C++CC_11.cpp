#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


//with OOP we think about what makes an object an object
//in the case of the animal it has things such as
//height/wieght, attributes as such
//and that is the basses for OOP and class's
//creating that object and definign it within a class

//some examples of what a class such as animaal would hold
//Attributes: height weight //veriables
//Capabilties : Run Eat		//functions/methods

//Pro Tip : Functions and methods are the same thing lol

class Animal 
{
	//setting private, prevents changing of values outside of this class
	//ie change by functions inside the class
	//this is called incapsulation, so data isnt changed outside of the class

private :

	int height;
	int weight;
	string name;

	//Static means this variables value is going to be shared
	//by every type object animal that is ever created
	//static variables also normally are attributes
	//that the class object would not have

	//tied to the class, not the object created from animal class
	static int numOfAnimals;

	public:
		//public vairables that acccess the private variables
		//in order to get info on values within the class
		//so getHeight, will return the value of the animals height
		//without it being changed 

		int getHeight() { return height; }
		int getWeight() { return weight; }
		string getName() { return name; }

		//with encapsulation, we want to protect the values that are stored
		//we can also place a check inside this functions to make sure things 
		//stay consistant and make sense
		void setHeight(int cm) { height = cm; }
		void setWeight(int kg) { weight = kg; }
		void setName(string animalName) { name = animalName; }

		//createing a protype of function that we will add here in a second
		
		//Declaring a prototype
		//that we Declare and Define later on
		void setAll(int, int, string);


		//Constructor
		//Starts with the Class's name

		//this will be the function that is called whenever an object is created
		//passing in the hieght, wieght and name and setting that to the object

		Animal(int, int, string);

		//Destructor
		//same as Connstructor but with ~infront it 

		~Animal();

		//Contructor that doesnt recieve anything
		//Example of Overloading
		//Again with Overloading, the name is the same, 
		//but the attributes need to be diffrent

		Animal(); 


		//Protected example
		//Avible to the class, and subclass but thats all


		//Static Method
		//Attached to the Class and not the instance of the object
		//so, if a girrafe is made, that static method isnt part of the girrafe
		//same with the static int numofAnimals
		//can can only acccess static variables like numofanimals

		static int getNumOfAnimals() { return numOfAnimals; }

		//Prints the information of the class info
		void toString();

};

//You declare shit outside the main method you fucktard

//Declaring the Class
//refering to static variables using :: infront of the variable name
//Example of Refering to Static Variable
//tied to the class, not the objects created
int Animal::numOfAnimals = 0;

//Defining the protype method for setAll
//have to define whats in the protoype method
//eg int int string
//basically does what the constructor does

void Animal::setAll(int height, int weight, string name)
{
	//if you want to refer to an objects specific height
	//and not a generic height, you use the this namespace
	//example of refering to objects spefic value
	//reason we have to do this is because
	//whenever the class is created, there are no
	//animal objects created yet

	//so using this, we refer to the specific animal objects
	//value or in this case height 

	//we could have also used the SetMethods within the class
	//using this we can get around that aswell

	//just a way to refer to value, so code knows what your refrencing and setting

	this->height = height;
	this->weight = weight;
	this->name = name;


	//Changeing the static variable after animal is created

	Animal::numOfAnimals++;
}

//Creating the instance of Animal using the Class constructor
//instead of the protype method

//just demonstrating that regular functions and contstructors
//within a class basically the same thing

Animal::Animal(int height, int weight, string name)
{
	this->height = height;
	this->weight = weight;
	this->name = name;

	Animal::numOfAnimals++;
}

//Example of Deconstructor use

Animal::~Animal()
{
	cout << "Animal " << this->name << " destroyed" << endl;
}

//in object oritentated programming
//what were trying to do is model
//Real world objects, like an animal in code


//Example of the Overloaded Constructor
//when no attributes are passed in, bassically just a dummy animal class

Animal::Animal()
{
	Animal::numOfAnimals++;
}


void Animal::toString()
{
	cout << this->name << " is " << this->height << "cms tall and " << this->weight << "kgs in weight" << endl;
}

//Example using inheritence, where we ineherent from the Animal object class
//Used to Create seperate Subclass's of a Class, in this example we use Dog as a 
//subclass of animal
// : Animal, makes it inherit from the animal class

class Dog : public Animal
{
private :
	string sound = "Woof";

public:
	void GetSound() { cout << sound << endl; }

	//Defing a new constructor for the dog class
	//Protype Method

	Dog(int, int, string, string);

	//Defualt Constructor
	//Calling the Defualt Super Class method

	Dog() : Animal() {};

	void toString();

};

//Constuctor for the Dog Class
//And Refrencing the Animal class, to handle the first 3 values
//that were declared prevoisly, but with bark added to it

Dog::Dog(int height, int weight, string name, string bark) :
	Animal(height, weight, name) 
{
	this->sound = bark;
}

void Dog::toString()
{
	cout << this->getName() << " is " << this->getHeight() << " cms tall and " << this->getWeight()
		<< "kgs in weight and says " << sound << endl;
}

int main()
{

	cout << "Class's / Objects" << endl;

	//and here we create the Animal object
	//this is so kewl shit!
	//here we use the contructor that doesnt get atturbutes
	Animal hugeBalls;

	hugeBalls.setHeight(33);
	hugeBalls.setWeight(120);
	hugeBalls.setName("hugeBalls");

	//Getting the Vales and information of hugeballs the magical animal
	cout << hugeBalls.getName() << " is " << hugeBalls.getHeight() << "cms tall and " << hugeBalls.getWeight() << "kgs in weight" << endl;

	//and here we create the Animal object
	//this is so kewl shit!
	//here we use the contructor that does get atturbutes

	//Basically cleaner i guesse 
	Animal anusLord(36, 67, "AnusLord");

	cout << anusLord.getName() << " is " << anusLord.getHeight() << "cms tall and " << anusLord.getWeight() << "kgs in weight" << endl;


	//Example of Clas creation, using inheritence
	
	Dog fuckLord(35, 56, "FuckLord", "Raaaaaghtghtgt");

	//Calling a Static Method
	cout << "Number Of Animals : " << Animal::getNumOfAnimals() << endl;

	//:: is called the scope operator

	fuckLord.GetSound();
	//Calling the to string methods to list value information from class and inhertied class

	hugeBalls.toString();
	fuckLord.toString();

	//Calling the super class version of method

	fuckLord.Animal::toString();

		return 0;
}