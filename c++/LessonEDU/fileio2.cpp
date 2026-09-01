#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(void) {
	
	ifstream numberFile ("numbers.txt");

	float currentNumber;
	float average = 0;

	int count = 0;
	
	while(numberFile >> currentNumber) {
		count++;
		average += currentNumber;
	}
	
	average /= count;
	
	cout << "The average of the " << count << 
		" numbers in numbers.txt is " << average << endl;
		
	numberFile.close();
	return 0;
}
