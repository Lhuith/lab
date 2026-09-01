#ifndef FILEMODES_H
#define FILEMODES_H

#include <iostream>
#include <fstream>

using namespace std;

namespace fileModes
{
	int main()
	{
		ofstream ofile;
		ofile.open("../data/important.txt", fstream::app);

		if (!ofile)
		{
			cout << "couldn't open file\n";
			return -1;
		}

		ofile << "some more data";
		ofile.close();

		return 0;
	}
}
#endif // FILEMODES_H