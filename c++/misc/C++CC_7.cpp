#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

//Addnumbers function
//returns an int...obvoisly
//set attributes within the function
//these attributes are used within the function and are used
//when a function is called and values was the same data type are 
//pasesed into these attributes

//if an attribute has a defualt value
//then passing a value say from main wont need to be made
//just make sure your defualt values come last
//also known as a function protype

int AddNumbers(int FirstNum, int SecondNum = 0)
{
	int CombinedValue = FirstNum + SecondNum;


	//this has to be callled when a function isnt void
	return CombinedValue;
}

//Example of Function OverLoad
//using the same function but with ////diffrent attributes////
//thats all...pretty sexc and EZ EZ

//Overload function example
//so in this case we have a third attribute but the same values we can pass in
//cuasing you to to be to call the function twice, with diffrent attributes
//and create diffrent resulsts using the same values

int AddNumbers(int FirstNum, int SecondNum, int thirdNum)
{
	return  FirstNum + SecondNum + thirdNum;
}

//Example of a Recursive Function
//Recursive Funtions are Functions that call themselves
//sexc sexc sexc shit!

int getFactorial(int number)
{

	//here were grabbing a number and going number!
	//or sum = 1x2x3.....x number
	//number is just how many times to go down the factorial sequance from 1x2 --> to x n

	int sum;
	if (number == 1) sum = 1;
	else sum = getFactorial(number - 1) * number;
	return sum;
}
//Main Function
int main()
{
	cout << "Funtions!" << endl;
	//functions can have a return time, ie, int MyintFuction, 
	//needs to return an int using return int;

	//void functions, or Void myIntFunction , 
	//doesnt not need a return namespace and can be void

	//example of calling a function
	cout <<"Add Numbers :" << AddNumbers(1) << endl;

	//example of calling a overload function
	//Overloading is some sexc ass shit
	cout << "Add Numbers Overloaded:" << AddNumbers(1, 5, 6) << endl;


	//example of calling a overload function
	//Overloading is some sexc ass shit

	int factorialN = 6;
	cout << "The Factorial of ";
	cout << factorialN;
	cout << " is : ";
	cout << getFactorial(factorialN) << endl;
	return 0;
}