#include <iostream>
#include <string>

using namespace std;

	
	/*
	 * 	Examples of C-like "pass-by-value" functions:
	 */
	
	//no parameters, no return value:
	void f(void){
		cout << "function f()" << endl;
}
	
	//parameters, no return value:
	void g(int i, int j){
		cout << "functions g(" << i << "," << j 
			<< "). Sum of parameters is " << i + j << endl; 
}
	
	//no parameters, a return value:
	float k(void){
		cout<<"function k()" << endl;
		return 42.42;
}
	
	//parameters, a return value:
	int l(float a){
		cout << "function l(" << a << ")" << endl;
		return (int) a; //truncs the float value, removing decimal points
}
	
	/*
	 *	refrence parameters -- not that this is not the same 
	 * 	syntax as "pass by refrence" in C... we pass in a
	 *  REFRENCE to the variable, but when we call the function
	 *  we're not calling with pointers!
	 */
	 
	 //to alter the value of the parameters:
	 //NOTE, not swap(int *a, int *b)
	 
	 void swap(int& a, int& b){
		int temp;
		temp = a;
		a = b;
		b = temp;
 }
	 
	 //Pass by value makes a COPY of the value into the parameter.
	 //Pass by refrence passes a reference to the variable.
	 //for primitive types, the copy operation is not to costly, but
	 //for more complex types, we might want to pass by refrence:
	 
	 string add(string& a, string& b) {
		return a + b;
 }
	 
	 //But in add (above), the values of the refrences passed into the
	 //function *could* be modified. To avoid this possibility, we
	 //can mark these as constant:
	 
	string first(const string& a, const string& b);
	 
	 int main(void) {
	//for the most part, functions in C++ are the same
	//as their C counterparts. There are some things
	//to think abou when passing parameters by refrence
	//however.
	
	f();	
	g(1, 5);
	cout << k() << endl;
	cout << l(4.2) << endl << endl;
	
	int i = 5, j = 9;
	cout << "Before Swap, i = " << i << ", j = " << j << endl;
	//NOTE!: not swap(&i, &j); no need more &
	swap(i, j);
	cout << "After Swap, i = " << i << ", j = " << j << endl;
	
	string one("this is the first string ");
	string two("and this is the second string.");
	cout << add(one, two) << endl << endl;
	
	cout << "First of (one, two) is |" << first(one, two) << "| "<< endl;
 }
	
		 
	 string first(const string& a, const string& b) {
			if(a > b) return b;
			else return a;
 }
