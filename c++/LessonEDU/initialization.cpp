#include <string>
#include <iostream>

using namespace std;

int main(void){

	//in C++, variables are strongly typed, and must be
	//initialized before they are used.
	
	//There are three methods of initializing a variable.
	
	//1. C-like initialization
	int x = 4;
	
	//2. Contructor initialization
	int y (4);
	
	//3. Uniform initialization (added in the C++ revision of 2011)
	// See "Buildstrings.png" to enable support...
	int z {4};
	
	//all three have the same result in C++, and can be used to
	//initialize any variable.
	
	cout<<"x is "<< x << endl;
	cout<<"y is "<< y << endl;
	cout<<"z is "<< z << endl;
	
	//The string class is a wrapper of char* that adds functionality
	string str1 = "Hello";
	string str2 ("HEY There! ");
	string str3 {"This Constructor is Wierd. "};
	
	//::size() returns the length of the string
	cout << "str1 is \"" << str1 << "\" and is "
	<< str1.size() <<" chars long." << endl;
	
	//::find("string") returns the position of its argument
	//  in the string as an int
	cout << "str2 is \"" << str2 
	<< "\" and the word \"There\" is found at index "
	<< str2.find("There") << endl;
	
	//The addition operator (and all comparisions operators)
	//are overloaded for strings
	cout << "str2 + str3 = " << str2 + str3 << endl;
	
	if(str1 == "Hello"){
		cout<<"str1 is hello"<<endl;
	} else {
		cout<<"str1 is not hello"<< endl;
	}
	
	//swapping two strings:
	cout << "Swapping str2 and str3:" << endl;
	str2.swap(str3);
	cout<< "str2: " << str2 << endl;
	cout<< "str3: " << str3 << endl;
	
	//we can also "index" into a string as if it were a char array
	for(int i = 0; i < str2.size(); i++) {
		cout<<"[" << str2[i] << "] ";
	}
	cout << endl;
	
	//for the contents of <string>, see
	// http://www.cplusplus.com/refrence/string/string/
	return 0;
}
