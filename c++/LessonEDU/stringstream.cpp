#include <iostream>
#include <sstream>

using namespace std;

int main(void)
{
	stringstream stream;
	char name[10];
	cout<<"What is your name? ";
	cin >> name;
	stream<< "Hello, " << name << endl;
	//we can get the stream's string using .str();
	cout<<stream.str();
	
	//get 5 ints from the user into an array:
	int numArray[5];
	stringstream numStream;
	cout << "Enter five ints, separated by spaces ploos -> ";
	for(int i = 0; i < 5; i++) {
		cin >> numArray[i];
		numStream << numArray[i] << " ";
	}
	cout << "You entered " << numStream.str() << endl;
	
	/*
	 *	Declare a stringstream for input only using istringstream;
	 * 	Declare a stringstream for output only using ostringstream;
	 */ 
}
