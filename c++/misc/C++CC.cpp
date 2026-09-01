//This is single a Comment in C++ (hey @<o_o>@)

/*
multi Line
comments
are annoying to Type
in C++
*/

#include <iostream> // Outside Libries(with functions and shit) to be included (seems pretty stright forward)
#include <vector>
#include <string>
#include <fstream> //File I/O (input and output baby yea)

using namespace std;

//main Function where most code will be
int main()
{
	//Calling C-out
	//Can be called using std::cout but for
	//this std is called from the top to save 
	//having to type it every time
	
	//cout <<, outputs text and endl >> is the CR/Caridge return
	//Used for output shit
	cout << "Hello World" << endl;

	const double PI = 3.1415926535; //Const = Non Changeable, Double is the data type, in this case a float

	char myGrade = 'A'; //containts just 1 character and souranded by single quotes, takes 1 byte (sexc)
	
	bool isHappy = false; //just the standard true or false shit

	int myAge = 25; //just standard - to + number range shit

	float FavNum = 2.34576; //Same as Double except counts upto 6 decimal places shit

	double otherFavNum = 2.359238758295; //Same as float but with 15 decimal places poop butt ass

	cout << "Quick Call Example" << endl;
	cout << "Favorite Number : " << FavNum << endl; //Calls the favNum var with "Favorite Number" infront of it....yay :D

	//Other Types include
	//Short Int : At least 16 bits
	//Long Int : At least 32 bits
	//long long Int : At least 64 bits
	//unsigned int : Same Size as signed version
	//long double : not less then double
	cout << "Bit Size Examples" << endl;
	//Outputs the size in bits of a variable
	cout << "Size of int : " << sizeof(myAge)
		<< endl;
	cout << "Size of char : " << sizeof(myGrade)
		<< endl;
	cout << "Size of Bool : " << sizeof(isHappy)
		<< endl;
	cout << "Size of float : " << sizeof(FavNum)
		<< endl;
	cout << "Size of double : " << sizeof(otherFavNum)
		<< endl;

	cout << "Examples of numbers going beyond there bounds" << endl;
	//demonstrating how large a number can get
	//and what happens when you gotoutside there bounds

	//Largest Size an int can be
	int LargestInt1 = 2147483647;

	//1 over the Largest Size an int can be
	int LargestInt2 = 2147483648;

	cout << "Largest Int 1 : " << LargestInt1
		<< endl;
	cout << "Largest Int 2 : " << LargestInt2
		<< endl;
	//Basic Arithmatic
	// + : adds, - : subtracts, * : Multiplys, / : Divides

	cout << "Basic Arithmatic" << endl;
	//Quick Demo of the Basic Arithmatic Functions<--
	// + : adds
	cout << "5 + 2 : " << 5+2
		<< endl;
	// - : subtracts
	cout << "5 - 2 : " << 5-2
		<< endl;
	// * : Multiplys
	cout << "5 * 2 : " << 5*2
		<< endl;
	// / : Divides
	cout << "5 / 2 : " << 5/2
		<< endl;

	// % : RETURNS REMIANDER,
	//fucking remmember this asshole
	cout << "5 % 2 : " << 5%2
		<< endl;

	//shorthands examples
	//++ : incramental, -- : decramnetal
	cout << "Shorthands Examples " << endl;
	int five = 5;

	//increment and dicrement by 1, showing the diffrent between show the value then performing the 
	//inc/dec and then showing the inc/dec first and then showing the value
	//--------------------------------------------------------------------------------------//
	//so Pro tip : dont show value until calculations are done or wierd shit will happen!!!
	//--------------------------------------------------------------------------------------//

		//Increment happens first before displaying the increment
	cout << "5++ : " << five++ << endl; //so this is going to be 6 but displayed as 5 first
	
	// - : subtracts
	cout << "++5 : " << ++five << endl; //so 5 is now 6, from prevois increment but will 
										  //show as 7 since a new incrment was made and is properly displayed

	//-- : decramnetal
	cout << "5-- : " << five-- << endl; //the increment will remove 1 and will be 6 again
								   //but like the first increment, will only show 7 but really is 6 now
									//but the display happens first
	
	// - : subtracts
	cout << "--5 : " << --five << endl; //decrements first then shows value, value is now going from 6 back to 5

	cout << "Other Shorthands Examples " << endl;

	//Other examples of incrementals and decraments
	int num1 = 5;
	int num2 = 5;
	//increments num by 5 and the right side shows the same type of 
	//incrementing

	//pro tip : you can have mutliple statements on the same line as semicolins sepereate and 
	//defines a statment has ended them ;)
	num1 += 5; num2 = num2 + 5;
	//EZ PZ
	cout << "num1 += 5 : " << num1 << endl;
	cout << "num2 + 5 : " << num2 << endl;

	cout << "OofO and why Bracers are needed" << endl;
	//Order of Operations states * and / is performed before + and - sp bracers rules OofO!
	//why is it important in C++?
	
	cout << "BAD : 1 + 2 - 3 * 2 : " << 1 + 2 - 3 * 2 << endl;
	//thats why, it will perform the * before adding things together
	//which creates CHAOS

	//Pro Tip : use Bracers it will save hassle and perform equations without wierd shit
	cout << "GOOD : (1 + 2 - 3) * 2 : " << (1 + 2 - 3) * 2 << endl;
	//Magic

	cout << "Casting example" << endl;
	//Casting example (float)2, changes the int to a float
	//used to display or use value results in diffrent data forms int/double/float

	//this will output genrally as an int
	cout << "4 / 5 = " << 4 / 5  << endl;

	//this will output as a float since the veriable types use decimals
	cout << "4 / 5 = " << 4.22 / 5.22 << endl;

	//this will output as a float aswell
	//using the cast method to convert the variable type
	cout << "4 / 5 = " << (float)4 / 5 << endl;

	//this will output as char
	cout << "4 / 5 = " << (char)4 / 5 << endl;
	return 0;
}