#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	cout << "Examples of Strings part 2," << endl;
	cout << "YO" << endl;

	string yourName;
	cout << "What's your name :";
	cout << "\n";
	//user input writes string into the yourName variable

	getline(cin, yourName);

	cout << "Sup ";
	cout << yourName + ',';
	cout << " you Sack of Human Fece's " << endl;

	//Compare strings
	string dogString = "Dog";
	string catString = "Cat";

	//whenever a value is greater than it will return -1
	cout << dogString.compare(catString) << endl;
	//whenever a value is equal return value will be 0
	cout << dogString.compare(dogString) << endl;
	//whenever a value is less than it will return -1
	cout << catString.compare(dogString) << endl;


	//Assigning copies of a value
	string wholeName = yourName.assign(yourName);
	cout << wholeName.append(" you fucking shit ball") << endl;

	//Gettng Substrings

	//psuesdo code string = otherstring.assighn(otherstring, 
	//index i want to string from, how many charactes im pulling);

	//the last 2 indexs are from left to right
	//the starting string index, in this case the first one
	//and how many strings i wana yank outta there

	string firstName = wholeName.assign(wholeName, 0, 6);
	cout << wholeName.append(" what a fucking crap first name") << endl;

	//Performing seach on a string
	//pseudo, Find("the characters your looking for", where the index should start)

	//finds the index with the string being searched
	//in this case should be 7 for Eugene Martens, as M in martens starts at 7 
	int LastNameIndex = yourName.find("Martens", 0);

	cout << "Index for last name : " << LastNameIndex << endl;

	//Inserts a string at a given index
	//psuedo, insert(index to start from, "string")
	//inserts Jacobus inbetween the strings Eugene and Martens
	//eugene <-- being 6 strings, and is where we want to start the insert index
	//space at end and start from blank point, so "stringlengh" + 1
	yourName.insert(6, " Jacubus");
	cout << yourName << endl;
	//Remove or Erase strings starting with the lengh of string
	//and where the index should start

	yourName.erase(6, 8);
	cout << yourName << endl;

	//Replace Strings
	cout << "Heres a Better Name For your" << endl;
	//Puesdo code replace("Index", number of strings to replace, "String");
	//Example

	yourName.replace(0, 7, "FuckWad ");
	cout << yourName << endl;
	return 0;
}