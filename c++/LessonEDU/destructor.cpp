#include <iostream>
#include <cmath>
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

class Line {
	Point *point1; // note, deleting a Line object will not delete
	Point *point2; // point1 or point2. We have to handle this!!!
	
	public:
		Line(int startX, int startY, int endX, int endY);
		float length();
		
		//this is a "destructor." it will be called when an object
		//of class Line is deleted.
		~Line(){delete point1, delete point2;}; //note: inline 
}; // dont forget semi colan

Line::Line(int startX, int startY, int endX, int endY){
	point1 = new Point(startX, startY);
	point2 = new Point(endX, endY);
}

float Line::length(){
	float dx = (float)(point1->getX()) - (float)(point2->getX());
	float dy = (float)(point1->getY()) - (float)(point2->getY());
	float len = sqrt(dx*dx + dy*dy);
	return len;
}

int main(void) {
	
	Line *line = new Line(5, 3, -4, 2);
	cout << "the length of the line is " << line->length() << "\n";
	
	//calls Line's destructor:
	delete line; 
	return 0;
}
