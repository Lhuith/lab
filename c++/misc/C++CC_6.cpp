#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	cout << "Vectors" << endl;

	//Example of Vectors
	//Vectors are basically lists in C++
	//vector <veriable type> varName (size of vector)
	//Vectors like lists are dynamically changable

	vector <int> lotteryNumVec(10);

	//Creating an array to insert into our Vector

	int lotteryNumArray[5] = { 4,13,14,24,35 };

	//inserts the array into the vector
	//pseudo : insert(index/whereto begin in vector, the array, and which values in that array)

	lotteryNumVec.insert(lotteryNumVec.begin(), lotteryNumArray, lotteryNumArray+3);

	//prints out the value at index 2 in the vector
	cout << "Lottery number at 2nd index is : " << lotteryNumVec.at(2) << endl;

	//adding value at an index into a vector
	//.begin is just short hand for the start of a vec
	//same as inserting from the array
	lotteryNumVec.insert(lotteryNumVec.begin() + 5, 44);
		
	cout << "Lottery number at 5th index is : " << lotteryNumVec.at(5) << endl;


	//Example of the use of Push Back
	//adds a value at the end of a vector
	//adds 64 at the end of a vector yay
	lotteryNumVec.push_back(64);

	//using .back to call the last index ofa vector
	cout << "Lottery number at last index is : " << lotteryNumVec.back() << endl;


	//Example of Pop Back
	//Used to remove the final value
	lotteryNumVec.pop_back();

	cout << "Lottery number at last index after pop is : " << lotteryNumVec.back() << endl;

	//example of grabbing the first value in a vector
	//Using Front....not begin
	cout << "Lottery number at 1st index is : " << lotteryNumVec.front() << endl;

	//example of checking if a vector is empty
	//if 0 then not emptly, and emplty returns 1
	//Pro Tip : 0 is false, 1 is true

	cout << "Is this Vector Empty? 0 is no, 1 is Yes : " << lotteryNumVec.empty() << endl;

	//example of checking the size of our vector
	//using .size..boring

	cout << "The Size of the Vector is : " << lotteryNumVec.size() << endl;

	//Using 2D vectors

	//they dont work the same as 2d arrays tho
	//its basically a vector of vectors of int...like a list of lists

	//declarig 2d vector in C++
	vector<vector<int>> numbers; //2D!!!!!!!!!! what!
	vector<int> TempVec; //tempory vector of ints

	TempVec.push_back(5); //adds a 5 to the last index, in this case only 0, its empty
	TempVec.push_back(10); //adds a 10 to the last index, in this case only 1;

	numbers.push_back(TempVec); //adds this vector list into the vector <vector list> lol to 0 since its empty
								//we now have 1 vector list in there 

	//calling the value from the vectorlist within the vector<vectorList>
	//that was pretty easy lol
	//so vectirlist 1 is called, and its calling the first value in that list
	//EZ PZ
	cout << "1st Vector Lists 1st Value is : " << numbers[0][0] << endl;
	cout << "1st Vector Lists 2nd Value is : " << numbers[0][1] << endl;

	//Clearing a Vector

	TempVec.clear(); //EZ PZ
	//clearing the templ doesnt effect the vector<vectorlist>
	//since doing a pushback clones the temp and adds it as a new vectorlist
	cout << "Value of the 1st Vector Lists 1st Value is : " << numbers[0][0] << endl;

	TempVec.push_back(1);
	TempVec.push_back(57);


	numbers.push_back(TempVec);
	//adds a new vector into the vector list using ttotaly new values
	//so the Vector<vectorList> now has 2 vectorlists
	//so the temp vec that was cleared, and the Temp vec within the Vector<vectorList> are
	//totaly diffrent, there clones now yo
	//but now we have a 2nd list we can call

	//using and clearing the templ vector alows for only 1 vector to be used
	//and the clones are added into the list to create whole new vectors lists with diffrent values
	cout << "2nd Vector Lists 1st Value is : " << numbers[1][0] << endl;
	cout << "2nd Vector Lists 2nd Value is : " << numbers[1][1] << endl;
	return 0;
}