#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


//Function using pointer example
//needs to be int*, as thats a pointer type
//quick note, void = dont need to return shit, yay
void makeMeYoung(int* age)
{
	//be sure to put a star on that bitch
	//or ull be refrences the adress, not the data

	cout << " I used to be : " << *age << endl;

	//and we can change the data, at the adress
	*age = *age - 5;
}

//int& <--- refrences!!
void actYourAge(int& age)
{
	age = age + 5;
}

int main()
{
	cout << "Pointers" << endl;
	
	//When data is stored its stored in a box
	//Based on its data type
	int myAge = 39;
	char myGrade = 'A';

	//Size of is used to show the size of bytes that data type uses

	cout << "Size of an Int : " << sizeof(myAge) << endl;
	cout << "Size of Char : " << sizeof(myGrade) << endl;

	//You can also refrence this box/memory address
	//using a refrence operator &, refrencing the data addree

	//example of adress refrencing
	//used to grab the memory adreess, sexc shit

	cout << "myAge is located at : " << &myAge << endl;

	//when we dont use pointers or refrences operators
	//and change a value of a veriable within a regular function
	//that change of value does not carry on, it is lost

	//Reason why is, is when we use regular function
	//what were in essence doing, is passing a value into that function

	//Quick example of this 
	//when we pass the value sum into the function
	
	//if we change the value of sum
	//and we do not pass it back, 
	//sum is still going to be equal to 5

	//becuase we are passing a value, in these case 5, 
	//no the actaull data

	//in essense were passing a 5, not a "sum" so 
	//sum stays the same if not passed back

	int sum = 5;

	//addThese(sum); //Fake function


	//Examples of refrence operators
	//instead of pass by value, pass by refrence instead
	//so any change made to sum will change sum itself

	//pointer example
	//using the * nexto the value
	//pointers are used to store a memery address

	//examples of pointers and refrence opertorators in use

	int myAge2 = 39;

	//definging a pointer, using the same datatype, followed by a star
	//so this is the pointer to myAge the veraiable
	//and using the refrence operator pass in the address of MyAge
	
	//pointer and refrence defination
	int* agePtr2 = &myAge;

	//Accessing myAge Adress, using the pointer data instead

	cout << "Address of Pointer : " << agePtr2 << endl;

	//we can also derefrence to get the data, instead of the adresss
	//so this will get the data that agePtr is pointing towards

	//using * on a pointer will defrence and show the data at that point instead

	cout << "Data at Memory Address : " << *agePtr2 << endl;

	//Same can be done for Arrays, which in some sense is what data adress are, fancy indexed shit

	int BadNums[5] = { 4, 13, 14, 24, 34 };

	//Ptr for Array, EZ PZ

	int* numArrayPtr = BadNums;

	//Using pointers we can incriment through our array using ++ and --

	//example of this in ACtion
	//to get the actualy value we need to like pervoisly 
	//back back at the data at specfic array value address's
	//*numArrayPtr, is getting the data
	//int* numArrayPtr, points to the adress where the data is

	//atm this will get the first value in the array
	cout << "Address : " << numArrayPtr << " Value " << *numArrayPtr << endl;

	//grabbing the next index of the array we increment 
	//the pointer to grab the data at index 2(index -1)since 0
	
	//example of grabbing the next value in our array
	numArrayPtr++;

	//also note in the address, the size of the bytes being used is also shown

	cout << "Address 2: " << numArrayPtr << " Value 2 : " << *numArrayPtr << endl;

	//note : an array name is just a pointer to the array, just like the name of a variable is just apointer
	//to the data that it holds or reprasents

	//using the same example but instead using just the actaully array name
	//instead of the pointer
	//using the Pointer operator to point to the data at that current address

	cout << "Address using Array name: " << BadNums << " Value : " << *BadNums << endl;

	//Passing pointers throught to a function
	//using pointers your actually passing a refrence, not a value
	//example : penis = 19, 19 is the value, penis is the refrence, with that certain data
	//*penis, will pass the actaully refrence through and change the data at that refrence adress
	//where as, passing penis alone, will just pass in 19, and that value then will be lost if not passed back


	//to pass a refrence, use the &name
	//beating a dead horse but its important asshole

	//passings the adress, a pointer attribute is used to 
	//point to this refrence, that refrence then displays
	//and changes the data at the refrence we just passed
	//magic
	 
	makeMeYoung(&myAge);

	cout << " I'm " << myAge << " years old now" <<  endl;

	//so basically globally changes that shit yo!

	//Examples using refrence's, you will be using refrences more then pointers
	//int& sets a refrence type
	//int* sets a pointer type
	
	//gets a refrence to the myAge value;
	
	int& ageRef = myAge;

	cout << "My Age : " << myAge << endl;

	//we can also increment the refrence to change the value of the refrences data
	//another way to globally change values 
	ageRef++;

	cout << "My Age : " << myAge << endl;

	//shows the diffrences with passing pointers and passing refrences
	//passing the refrence 

	//still changes the data at the address point, globally
	actYourAge(ageRef);

	cout << "My Age : " << myAge << endl;


	//so basically, since both do the same thing
	//when should you use either?

	//Use pointers if you dont want to have to intilaize at decliration
	//which basically means, with refrence you intilize at the begining
	//and with pointers you dont need to immeiditally initialize

	//and with pointers you can assighn another veriable to it
	//where refrences are refrencing the 1 value, but with pointers, such as in with functions
	//that basically act, as the name suggest as pointers for multiple pass's
	//and not as a personally address book

	//IronClad Rule : If you dont need to be able to change 
	//whatever your going to be pointing at use a refrence


	return 0;
}