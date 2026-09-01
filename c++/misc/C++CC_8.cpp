#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


int main()
{
	cout << "Writing and Reading Data 0_0!" << endl;
	cout << "\n" << endl;
	//Create File streams
	string eugeneQuote = " 'dont touch my fucking eggs, you smelly banana whore. ' ";
	

	//example of an output file stream
	//Create a textfile to read and write from
	ofstream writer("eugeneQuote.txt");

	//if the file hasnt been written or found
	//output this message

	if (!writer)
	{
		cout << "CANT FIND THAT SHIT!" << endl;
		//terminates the main function by returning -1, instead of 0
		return - 1;
	}
	else
	{
		writer << eugeneQuote << endl;
		writer.close();
	}

	//writing to the txtfile

	//Open a stream to append to whats there with ios::app, 
	//basically write shit after whats already written in there

	//ios::binary : Treat the file as Binary
	//ios::in : Open a file to read input
	//ios::trunc : Defualt
	//ios::out : Open a file to write output


	ofstream writer2("eugeneQuote.txt", ios::app);

	if (!writer2)
	{
		cout << "CANT FIND THAT SHIT!" << endl;
		//terminates the main function by returning -1, instead of 0
		return -1;
	}
	else
	{
		//\n creates a space, adding new line to newly opened stream
		writer2 << "\n -Eugene Martens" << endl;
		writer2.close();
	}

	//going to hold each indivudal character
	//that were gana read from our file
	char letter;

	//input file stream is used to read these characters
	//going to read from the eugeneQuote.txt
	ifstream reader("eugeneQuote.txt");

	//makes sure the stream is open
	if (!reader)
	{
		cout << "CANT FIND THAT SHIT!" << endl;
		//terminates the main function by returning -1, instead of 0
		return -1;
	}
	else
	{
		//using a for loop to read each charater until we get to the end of the line
		//while the reader is not at the end of a file, thats what !raeder.eof() means

		for (int i = 0; !reader.eof(); i++)
		{
			reader.get(letter);
			//reads each character and outputs them to cout
			cout << letter;
		}


		cout << endl;
		reader.close();
	}

	return 0;
}