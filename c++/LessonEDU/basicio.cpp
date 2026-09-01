#include <iostream>
using namespace std;

/* C++ I/O uses "streams", which are just sequences of 
 * bytes. The header file iostream defines four of these
 * streams:
 * 
 * 			cout - the C OUTput stream, corresponding to the
 * 					screen by defualt.
 * 			cin  - the C INput stream, corresponding to the
 * 					keyboard by defualt.
 * 			cerr - the C ERRor stream, used for unbuffered error
 * 					output.
 * 			clog - the C LOG stream, used for buffered error output.
 * 
 * cout, cerr and clog are all instances of the ostream (output stream)
 * class.
 * 
 * cin is an instance of the istream class. (input stream)
 * 
 * the (overloaded) stream insertion operator (<<, >>) is used with 
 * streams. Remember that the operator "points" in the direction the
 * data is being sent! eg. cout <<, cin >>
 */

int main(void){
		
	//a char array to hold user's names:
	char name[20];
	
	//prompt for input:
	cout << endl << "Hi, what is your name? ";
	
	//get the input
	//cin >> name;
	cin.getline(name, 256);
	
	//greet the user by name
	
	cout << "Hey!, " << name << ", Whats happening?" << endl;
	
	//unbuffered output to cerr will always occur immediately. cerr
	//should be used for error messages.
	cerr << "this is an error..." << endl;
	
	//buffered output to clog might be displayed without flushing
	//the buffer first. clog should be used for logging messages(such
	//as logs during debbugging).
	clog << "The contents of the name variable: " << name << endl; 
	
	return 0;
}
