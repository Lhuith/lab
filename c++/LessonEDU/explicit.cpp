#include <iostream>
#include <string>
#include "multiply.hpp"

using namespace std;

int main(void){
	
	//Explicit
	cout<<"3 * 2 = " << mult(3, 2) << "\n";
	cout<<"3.2 * 7.68 = " << mult(3.2, 7.68) << "\n";
	
	//Implicit
	cout<<"true * false = " << mult(true, false) << "\n";
}
