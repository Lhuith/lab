#ifndef UNBUFFERED_INPUT_OUTPUT_H
#define UNBUFFERED_INPUT_OUTPUT_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace unbufferedInputOutput
{
	void readWriteFile()
	{
		const int filesize{10}; // the size of the memory buffer
		char filebuf[filesize]; // the memory buffer

		string filename{"../data/input.txt"};

		ifstream ifile(filename);

		if (!ifile)
		{
			cout << "couldn't open " << filename << endl;
			return;
		}

		ifile.read(filebuf, filesize); // fetch data from file into the memory buffer
		auto nread = ifile.gcount();   // how many bytes did we receive?
		ifile.close();

		cout << "read " << nread << " bytes from " << filename << endl;
		cout << "file data: ";
		cout.write(filebuf, filesize); // send the data from memory buffer to output
		cout << endl;
	}

	int main()
	{
		// cout << "enter some text:" << endl;
		// char c;
		// while (cin.get(c))
		// 	cout.put(c);
		readWriteFile();

		return 0;
	}
}
#endif // UNBUFFERED_INPUT_OUTPUT_H