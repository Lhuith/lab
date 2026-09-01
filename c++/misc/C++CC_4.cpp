#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{

	cout <<"Examples of Strings part 1,"<< endl;

	//example using strings!
	//diffrences in string array to char array

	//C String ---
	//used an array of char's, which is what a string is but damn son
	//C is wierd and had to define a string using array with a \0 to 
	// signify an end
	char happyArray[6] = { 'H', 'a', 'p', 'p', 'y' , '\0'};

	//C++ string
	//so clean and easy
	string birthdayString = "Birthday";
	string Spoos = " ";

	//Combineing Char array with String
	//not to hard i guess
	cout << happyArray + Spoos + birthdayString << endl;

	//Always define your variables before you use them

	//User Input using strings

	string yourName;
	cout << "What is your name :";
	cout << "\n";
	//user input writes string into the yourName variable

	getline(cin, yourName);

	//User writes there name into YourName
	//and the program prints out hello "name" my AnusFarm
	cout << "Sup ";
	cout << yourName + ',';
	cout << " you AnusFarm " << endl;


	//Examples using doubles
	//Same procedure as before
	//input is read and converted 
	//from a double to a string
	//and read in a Do while loop
	
	double eulersConstant = .57721;
	string eulerGuess;
	double eulerGuessDouble;

	cout << "Now ";
	cout << yourName + ',';
	cout << " Guess What Eulers CONSTANT is " << endl;

	getline(cin, eulerGuess);


	eulerGuessDouble = stod(eulerGuess);


	if (eulerGuessDouble == eulersConstant)
	{
		cout << "Niiice your Right " << endl;
	}
	else 
	{
		cout << "You Fucked Up! " << endl;
	}

	//dont forget the semi colon


	//Getting the Size of a string 
	cout << "Size of String :" << eulerGuess.size() << endl;

	//Checking if its empty
	cout << "Is string empty? " << eulerGuess.empty() << endl;

	//Add strings together using append
	cout << eulerGuess.append(" was your guess") << endl;
	return 0;
}