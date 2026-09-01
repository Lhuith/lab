#ifndef STRING_NUMBERS_H
#define STRING_NUMBERS_H

#include <iostream>
#include <string>

using namespace std;

namespace stringNumbers
{
	void stringConversion2()
	{
		string pi{"3.14159"};
		cout << "pi: " << pi << "\n\n";

		size_t n_processed;
		cout << "stoi:\n";
		cout << stoi(pi, &n_processed) << endl;
		cout << n_processed << " characters processed\n\n";
		cout << "stod:\n";
		cout << stod(pi, &n_processed) << endl;
		cout << n_processed << " characters processed";
	}
	void stringConversion()
	{
		cout << stoi("42") << endl; // displays 42

		string str{"  314 159"}; // leading whitespaces is ignored
		size_t n_processed;

		auto i = stoi(str, &n_processed);
		if (n_processed < str.size())
		{
			cout << "non numeric characters at index " << n_processed << endl;
		}
		cout << "result of conversion: " << i << endl; // displays 314
		// stoi("abcdef"s);							   // cannot be converted - throw's exception
		auto x = stoi("2a", nullptr, 16);
		cout << "result of conversion: " << x << endl; // displays 42
	}

	int main()
	{
		// string hello{"Hello, "};

		// string pi{to_string(3.14159)};

		// hello += pi;
		// cout << hello << endl;
		// stringConversion();
		stringConversion2();
		return 0;
	}
}
#endif // STRING_NUMBERS_H