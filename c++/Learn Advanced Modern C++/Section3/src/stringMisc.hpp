#ifndef STRING_MISC_H
#define STRING_MISC_H

#include <iostream>
#include <vector>
using namespace std;

namespace stringMisc
{
	void stringSwap()
	{
		string s1{"Hello"};
		string s2{"Goodbye"};

		cout << "s1: " << s1 << ", s2: " << s2 << "\n\n";

		// member swap function
		cout << "calling member function swap()\n";
		s1.swap(s2);
		cout << "s1: " << s1 << ", s2: " << s2 << "\n\n";

		// non-member swap function
		cout << "calling non member function swap()\n";
		swap(s1, s2);
		cout << "s1: " << s1 << ", s2: " << s2 << "\n\n";
	}
	void print(int *arr, size_t size)
	{
		for (size_t i = 0; i < size; ++i)
		{
			cout << arr[i] << ", ";
		}
	}
	int main()
	{
		vector<int> numbers{1, 2, 3, 4, 5};
		print(numbers.data(), numbers.size());
		cout << "\n";
		stringSwap();
		return 0;
	}
}
#endif // STRING_MISC_H