#ifndef SYNTH_MEMBERS_H
#define SYNTH_MEMBERS_H

#include <iostream>
using namespace std;

namespace synthMembers
{
	class Test
	{
		int i;
		string str;

	public:
		Test(int i, const string &str) : i(i), str(str) {}
		// Test () {}
		// Test (const Test& other) : i(other.i), str(other.str){}
		// Test& operator =(const Test& other) { i = other.i, str = other.str;}
		// ~Test(){}
		void print() { cout << "i = " << i << ", str = " << str << endl; }
	};

	int main()
	{
		Test test{5, "hello"s};
		cout << "test after default constructor: ";
		test.print();
		Test test2{7, "Goodbye"s};
		cout << "test2 after default constructor: ";
		test2.print();
		Test test3 = test;
		cout << "test3 after copy constructor: ";
		test3.print();
		test = test2;
		cout << "test after assignment operator: ";
		test.print();
		return 0;
	}
}
#endif // SYNTH_MEMBERS_H