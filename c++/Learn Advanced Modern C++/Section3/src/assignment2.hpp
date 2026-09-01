#ifndef ASSIGNMENT2_H
#define ASSIGNMENT2_H

#include <iostream>
using namespace std;

namespace assignment2
{
	string exclaim(string &s)
	{
		auto i = s.begin();

		while (i != end(s))
		{
			if (ispunct(*i))
			{
				*i = '!';
			}
			++i;
		}

		return s;
	}

	int main()
	{
		string test{"To be, or not to be, that is the question:"};
		string test2{"having a bad day ???????"};
		cout << exclaim(test) << "\n";
		cout << exclaim(test2) << "\n";
		return 0;
	}
}
#endif // ASSIGNMENT2_H