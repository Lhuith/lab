#ifndef RANDOM_ACCESS_STREAMS_H
#define RANDOM_ACCESS_STREAMS_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace randomAccessStreams
{
	int main()
	{
		ostringstream output; // open an output stringstream

		string data{"it is time to say "};
		output << data; // write some data to the stream

		auto marker = output.tellp(); // save current file position marker
		cout << data.size() << " characters written to stream\n";
		cout << "stream marker is " << marker << " bytes into the stream \n";

		output << "hello"; // write some more data to the stream
		cout << "stream marker is now " << output.tellp() << " bytes into the stream\n";

		cout << output.str() << endl;

		if (marker != -1) // we have chang?
			output.seekp(marker);

		output << "goodnight";
		cout << output.str() << endl;

		return 0;
	}
}
#endif // RANDOM_ACCESS_STREAMS_H