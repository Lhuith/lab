#include <iostream>
using namespace std;

class Point {
	int x, y;
	
	public:
		Point(int x, int y);    //constructor
		Point();			    //no-arg constructor
		int getX() { return x;} //define the getters here...
		int getY() { return y;} 
};		

//no definitions for constructors exist inside the class,
//we must define them here by RESOLVING to the class scope:
Point::Point(int x, int y){
	this->x = x; 
	this->y = y;
}

Point::Point(){
	x = 0;
	y = 0;
}

int main(void) {
	
	//dynamically allocate a Point:
	Point *point = new Point(78, 62);
	
	//Stack allocated Point:
	Point point2(66, 89);
	
	cout << "Heap Var: (" << point->getX() << ", " << point->getY() <<")\n";
	cout << "Stack Var : (" << point2.getX() << ", " << point2.getY() <<")\n";
		
	//when done with a heap variable, free it with delete:
	delete point;
	
	return 0;
}
