#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <array>
using namespace std;

int main()
{

	cout << "Arrays, ForLoops, Whileloops and DoWhile loops with user Input " << endl;

	//Arrayc Examples dicks[2] <--- means theres a list of dicks 3 in size
	//why 3? arrays start at 0 dumbass
	//think of them either as boxes, or just a list of shit with a name
	//

	//Example of an array
	//start with array type, chars/strings/doubles/floats/ints/assholes/panties/coke/drpepper...whatever

	//empty array
	int MyFavNums[5];
	//array with predined values inside, remmber them curlies asshole
	int badNums[5] = { 4,13,14,24,34 };

	//accessing an array : arrayname[arrayindex], where index is the positioin inside an array from 0...->
	//indexers are always ints

	//using index to call a certain array value, in this case its the first one

	cout << "Bad Number 1: " << badNums[0] << endl;

	//heres where shit gets serois
	//Multi dimenstional arrays SON!

	//same as your avrage run of the mill array accept : arrayname[arraysize][arraysize]
	//thats right its will have 2 values within the array SON

	//MultiDimensional array Example
	char myExampleMDArray[5][5];

	//MultiDimensional array Example with predined values
	//again Curly brackets man, also 2 of them now too!

	//ProTip : 
	//char : 'c'
	//string :"cock"
	//note the little characers around them diffrences, char is '' and string is ""

	//double curlies, 1 to contain the entire value, and seperated curlies
	//to define seperate values within the array
	//also you cannot define more characters then the actual size, ie if array size = 2, 
	//you cant list more then 2 chars/ints/dicks unless you change the array size

	char myName[6][6] = { {'E', 'u', 'g', 'e','n', 'e'}, 
						{'M', 'a', 'r', 't', 'e', 'n'} };

	//accessing multi dimensional array data
	//the first [1] is the index of which array were selecting
	// and the second [1] the index within the selected array
	//so indexing multi arrays = arraymultName[whichArrayIndex][Selected array Index

	//in this examle im selecting array 2(remmmeber that 0) and grabbing the 6th char
	cout << "2nd Letter in 2nd Array :" << myName[0][2] << endl;

	//using index selecting you can also change the array value
	//changeing the first arrays, 3rd character to 'e', which was 'g'

	myName[0][2] = 'e';

	cout << "2nd Letter in 2nd Array :" << myName[0][2] << endl;


	cout << "For Loops Examples" << endl;

	//used to exucute code until a condition is met
	//quick example : for(int i = 0; i < bigPenis; i++) {then KeepTrucking()};
	//a temp named int i is made, and compared to the large penis
	//while the i is smaller then siad large penis, the function keeptrucking will happen each time
	//i++ just means i will keep incrementing untill i is larger then bigpenis
	//note : i can also be i +=2, so i will add 2 to itself, i *=2, i doubles and so on
	//in this example i will keep trucking aslong as my penis is big

	//For Example 
	//prints the templ variable i, 11 times since it starts at 0
	for (int i = 0; i <= 10; i++)
	{
		cout << i << endl;
	}

	//For Example using the multi dimenstional array
	//Using Nested for loops to unroll the Multi Dim info
	//first loop is for the 2 arrays, the second loop 
	//is for the size of arrays and there values
	//soo the first array grabs the 2 arrays, and the second goes threw 6 times [array size]
	//and prints them out
	for (int j = 0; j < 2; j++)
	{
		for (int k = 0; k < 6; k++)
		{
			cout << myName[j][k];
		}
	}
		cout << endl;


	//While Loops example
	//While loops are used 
	//when you do not know when your loops are going to end
		//eg, when you dont know the size of a dynamic array 

	//Genereates a random number
	//from 0-99, +1 to get the 100 aswell


		int RandNum = (rand() % 100) + 1;
		//prints numbers until a number is 100

		while (RandNum != 100)
		{
			cout << RandNum << ",";

			RandNum = (rand() % 100) + 1;
		}

		cout << endl;
	//Pro Tip : Check your fucking brackets openings and closing


	//Simulating a for loop using a while loop
	//The 2 are closely related in terms of operation

		int index = 1;

	//just goes threw the loops aslong as index is lessorEqual to 10
	//same as a for loop when you see i++

		while (index <= 10)
		{
			cout << index << endl;
			index++;
		}
	//DoWhile loop example and User Input
	//used whenever you want to DO something will inside a loop
	// at the very least 1 time

		//like a super char
		string numberGuessed;
		int intNumberGuessed;

		//dont forget the semicolon after the while!!!
		//will carry on excuteing the do until "number guessed is 4


		//getline grabs the integer input from user
		//stoi converts the input(in strings) back into an int
		//stod() : converts a String to a double, note the i and d at the end of them

		//do will continue to cycle until the enter the number 4
		//saying outloud helps it, do {this shit} while {this shit aint true}

		do
		{
			cout << "Guess between 1 and 10 : ";

			getline(cin, numberGuessed);

			//converts from string to int
			intNumberGuessed = stoi(numberGuessed);

			cout << intNumberGuessed << endl;
		} 
		while (intNumberGuessed != 4);

		//while will terminate the do, when 4 is pressed

		cout << "You Win" << endl;
	return 0;
}