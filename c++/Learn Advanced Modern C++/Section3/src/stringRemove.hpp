#ifndef STRING_REMOVE_H
#define STRING_REMOVE_H

#include <iostream>
using namespace std;

namespace stringRemove
{
	void stringAssign()
	{
		string str{"Hello"};
		cout << "str = " << str << endl;

		str.assign("Goodbye");
		cout << "str = " << str << endl;
	}
	void stringReplace()
	{
		string str{"Say Hello"};
		cout << "str = " << str << endl;

		if (auto gdx = str.find('H'); gdx != string::npos)
			str.replace(gdx, 5, "Goodbye");

		cout << "str = " << str << endl;

		string str2{"Say Goodbye"};
		cout << "str2 = " << str2 << endl;

		str2.replace(begin(str2), begin(str2) + 3, "Wave");
		cout << "str2 = " << str2 << endl;
	}

	void stringRangeErase()
	{
		string hello{"hello"};

		auto first = begin(hello); // get iterator to first character
		hello.erase(first);		   // erase it
		cout << "hello = " << hello << endl;

		hello.erase(begin(hello) + 1, end(hello) - 1); // erase all characters except first and last
		cout << "hello = " << hello << endl;
	}

	int main()
	{
		// string hello{"Hello"};
		// cout << "hello = " << hello << endl;

		// hello.erase(3, 1); // erase fourth character
		// cout << "hello = " << hello << endl;

		// if (auto opos = hello.find('e'); opos != string::npos) // first occurrence of 'e'
		// 	hello.erase(opos, 2);							   // erase two elements start with the first ??

		// cout << "hello = " << hello << endl;

		stringRangeErase();
		stringReplace();
		stringAssign();

		return 0;
	}
}
#endif // STRING_REMOVE_H