#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{

	cout << "Condition,Ternery and Switch Case Example" << endl;
	cout << "Condition Example" << endl;
	//If/else and else if Statement Examples

	//Comparitive operators
	// == : Equal to
	// != : Not Equal to
	// > : Greater Then
	// < : Less then
	// >= : Greater or Equal to
	// <= : Less than or Equal to

	//Logical Operators
	// && : And
	// || : Or
	// !  : NOT

	//Some If Examples 

	int Age = 70;
	int ageAtLasExam = 16;
	bool isNotIntoxicated = true;

	
	// If the age is or equal to one
	//And is less then 16

	//Pro Tip1 : IF statemnts in C++ are Generally 
	//written in seperate brackets like the example
	//below
	if ((Age >= 1) && (Age < 16)) 
	{
		cout << "You Can't Drive " << endl;
	}
	//if they are intoxicated
	else if(!isNotIntoxicated)
	{
		cout << "You Can't Drive " << endl;
	}
	//if above 100, they wont be alowed to drive
	//if they are going to over the age of 80
	//then they will be required to take an exame every 5 years to verify

	//note all the seperaters 
	else if (Age >= 80 && ((Age > 100) || ((Age - ageAtLasExam) > 5)))
	{
		cout << "You Can't Drive " << endl;
	}
	else 
	{
		//else the person is above 16 and below 100, they win the if game
		cout << "You Can Drive :) " << endl;
	}

	//Pro Tip2 : although if statements
	//still function the same if but together
	//but to avoid wierd shit, seperating
	//the logic would be prefered like the example above

	if (Age >= 1 && Age < 16)
	{
		cout << "You Can't Drive 2 " << endl;
	}


	//Quick Example of the Ternary operator
	//REMEMBER THIS SHIT
	cout << "Ternary Operator" << endl;
	cout << "!REMEMBER THIS SHIT!" << endl;


	//variable = (condition) ? true : false
	//sets the veriable, and tests the condition with a question mark after it
	//true = if statement is true then set it to that
	//else/false then set it to that
	//Psuedo code for it : variable = (variables penis huge) ? nice : haha bee dick

	//Real Code Example

	int LargestNum = (5 > 2) ? 5 : 2;
	cout << "(5 > 2) ? 5 : 2 = " << LargestNum << endl;

	cout << "Switch Statement Examples!" << endl;
	//Examples Using Swich statements....duuh
	//Switch statements are used to give 
	//diffrent outcomes depending on a condition
	//Psuedo code being
	//if (playerawsome)
	// switch 1: Greet Person
	//else "player is an asshole"
	// switch 2: Kill Person...

	int greetingOption = 1;

	//if greating option is 1 then : do shit
	//if 2: do other shit, and so on

	switch (greetingOption)
	{
		//sets up first condion when greetingsOption is 1
	case 1:
		//does whatever is in this case option
		cout << "bonjour" << endl;
		//breaks out of the statement case
		//if no break then it will move down the list 
		//to compare the value with other cases
		break;
		//if greetingOption = 2
	case 2:
		cout << "Hallo" << endl;
		break;
		//if greetingOption didnt match any cases it will defualt to ...defualt
		//defualt needs no break sir
	default:
		cout << "Sup" << endl;
	}

	return 0;
}