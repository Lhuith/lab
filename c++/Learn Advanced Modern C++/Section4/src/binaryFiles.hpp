#ifndef BINARY_FILES_H
#define BINARY_FILES_H

#include <iostream>
#include <fstream>

using namespace std;

namespace binaryFiles
{
	// #pragma pack(push, 4)
	struct point
	{
		char c;
		int32_t x; // fixed integer size to make it compatible across sytems
		int32_t y;
	};
	// #pragma pack(pop)

	int main()
	{
		point p{'a', 1, 2};
		ofstream ofile("../data/file.bin", fstream::binary);

		if (ofile.is_open())
		{
			ofile.write(reinterpret_cast<char *>(&p), sizeof(point));
			ofile.close();
		}

		ifstream ifile("../data/file.bin", fstream::binary);
		point p2;

		if (ifile.is_open())
		{
			ifile.read(reinterpret_cast<char *>(&p2), sizeof(point));
			ifile.close();
			cout << "read " << ifile.gcount() << " bytes\n";
			cout << "read x = " << p2.x << ", y = " << p2.y << endl;
		}

		return 0;
	}
}
#endif // BINARY_FILES_H