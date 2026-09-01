#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void){
	
	//this form delcares and opens an input file stream:
	ifstream inFile("test.txt");
	
	//this form seperates declration and opening:
	ofstream outFile;
	outFile.open("out.txt");
	
	//copy the inFile to the outFile:
	string line;
	while(getline(inFile, line)){
		outFile << line << endl;
	}
	
	cout << "test.txt copied to out.text." << endl;
	
	//always close files when done:
	inFile.close();
	outFile.close();
	
	return 0;
}
