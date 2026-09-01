#ifndef CHARACTER_FUNCTIONS_H
#define CHARACTER_FUNCTIONS_H

#include <iostream>
#include <cctype>
using namespace std;

namespace characterFunctions
{

	// case insesensetive string equality. returns true if lhs and rhs are equal, otherwise false
	bool equal_strings(const string &lhs, const string &rhs)
	{
		// first we compare the lengths of the two strings.
		// if the two strings have difference lengths they cannot be =
		if (lhs.size() != rhs.size())
			return false;

		// we now know that the strings have the same lengths

		// get iterators to the first element in each string
		auto lit = cbegin(lhs);
		auto rit = cbegin(rhs);

		// we iterate over the two strings, comparing the current character from each string
		// if either iterator is equal to cend(), we know we have seen all the characters
		// and the loop terminates
		// on each iteration. we look for mismatch. if character has a difference value in the two
		// strings, then we know the strings are different and we can terminate the loop.
		while (lit != cend(lhs) && rit != cend(rhs))
		{
			// we use toupper to compare the upper-case version of the two characters
			if (toupper(*lit) != toupper(*rit))
				return false; // mismatch return false
			// no mismatch found - we move to the next character in each string
			++lit;
			++rit;
		}

		// if we got here, we looked at all the characters in the string and not found
		// any mismatches. the strings must be equal
		return true;
	}

	bool yes_or_no(const string &input)
	{
		char c = input[0];
		if (toupper(c) == 'Y')
			return true;
		return false;
	}
	void characterInput()
	{
		string input;
		cout << "do you want to enter a string which starts with Y or y?\n";
		cin >> input;

		if (yes_or_no(input))
			cout << "evidently you do!\n";
		else
			cout << R"(I will take that as a "no"!)" << endl;
	}

	int main()
	{
		// string hello{"Hello, World!"};

		// for (auto c : hello)
		// {
		// 	if (isupper(c))
		// 		cout << c << " is a upper-case letter\n";
		// 	if (islower(c))
		// 		cout << c << " is a lower-case letter\n";
		// 	if (ispunct(c))
		// 		cout << c << " is a punctuation character\n";
		// 	if (isspace(c))
		// 		cout << "\'" << c << "\'" << " is a whitespace character\n";
		// }

		// characterInput();

		string a{"one"}, b{"two"}, c{"ONe"};
		cout << "using library == operator\n";

		cout << a << " and " << b << " are " << ((a == b) ? "" : "not ") << "equal\n";
		cout << b << " and " << c << " are " << ((b == c) ? "" : "not ") << "equal\n";
		cout << a << " and " << c << " are " << ((a == c) ? "" : "not ") << "equal\n";
		cout << "\n\nUsing equal_strings()\n";
		cout << a << " and " << b << " are " << (equal_strings(a, b) ? "" : "not ") << "equal\n";
		cout << b << " and " << c << " are " << (equal_strings(b, c) ? "" : "not ") << "equal\n";
		cout << a << " and " << c << " are " << (equal_strings(a, c) ? "" : "not ") << "equal\n";
		return 0;
	}
}
#endif // CHARACTER_FUNCTIONS_H