#ifndef COPY_CONSTRUCTOR_H
#define COPY_CONSTRUCTOR_H

#include <iostream>
#include <string>

using namespace std;

namespace copyConstructor
{
	class strung
	{
		string s;

	public:
		// constructors
		strung() : s("") {}
		strung(const string &s) : s(s) {}

		// copy constructor
		strung(const strung &arg) : s(arg.s) {}

		// assignment operator
		strung &operator=(const strung &arg)
		{
			s = arg.s;
			return *this;
		}

		void print() { cout << s << endl; }
	};

	int main()
	{
		strung w{"world"s}; // call constructor
		strung bang{""};	// call copy constructor
		strung bang2;
		bang = w; // call copy constructor
		bang2 = w;

		cout << "w = ";
		w.print();
		cout << "bang = ";
		bang.print();
		cout << "bang2 = ";
		bang2.print();
		return 0;
	}
}
#endif // COPY_CONSTRUCTOR_H