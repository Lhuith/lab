#include <iostream>
#include <string>

using namespace std;

int addi(int a, int b) {
	return a + b;
}

float addf(float a, float b){
	return a + b;
}

string adds(string a, string b) {
	return a + b;
}

int main(void){
	
	string str1("abcde");
	string str2("fghijk");
	cout << adds(str1, str2) << endl;
	cout << addf(4.3, 2.57) << "\n";
	cout << addi(5 , 9) << "\n";
	
	return 0;
}
