#include <iostream>
#include <string>
using namespace std;

/*
 * This is a "function template". the typename keyword marks
 * an alias (that can be used in the declaration and body of the
 * function) for any type at all.
 * 
 * Here, we declare a single function to add two values
 * on which the '+' operator is defined, and return value
 * of the same type :
 */

template <typename T>
T add(T a, T b){
	return a + b;
}

//Templates must be instantiated, either explicitly or implicitly,
//in order for the actual types to be bound to the type aliases in the
//template definition.

//if the template is not explicitly instantiated, it will be instantiated
//when the function based on the template is called. This is called
// Implicit Instantiation

int main(void){
	//Call diffrent types using implicit instantiation.
	
	//add two ints
	cout << "1 + 5 = " << add(1, 5) << endl;
	
	//add two floats
	cout << "5.6 + 8.1 = " << add(5.6, 8.1) << endl;
	
	//add two bools;
	cout << "true + false = " << add(true, false) << endl;
	
	//add two strings
	string greeting1 ("WabbaLabba");
	string greeting2 ("DubDub Rick");
	cout << "\"" << greeting1 << "\" + \"" << greeting2 << "\" = " <<
	add(greeting1, greeting2) << endl;
}


