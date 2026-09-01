#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


int main()
{
	cout << "Exception Handling and" << endl;
	

	//Exception handling helps avoid potetiol problems
	//Example of exception handling
	//using a divide by zero error

	int number = 1;
	int number1 = 5;
	//if you think something will crash or blow up
	//soround it within a try block to catch an error
	//sorta like a tiger pit or some shit 

	try 
	{
		if (number != 0)
		{
			cout << number1 / number << endl;
		}
		//throw looks for a catch
		//used when a error has occured
		//sorta like the error highlighting else statement 
		//that points at whos shitting in the pool
		else throw(number);
	}

	//cathces a value being passed in
	//doesnt need an attribute by it helps
	//and outputs whatever is placed inside it
	catch (int _num)
	{
		cout << " cant divide by zero ass stain!" << endl;
	}


	return 0;
}