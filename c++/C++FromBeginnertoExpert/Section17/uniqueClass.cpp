#include <iostream>
#include <memory>

using namespace std;

class Circle
{
public:
    double radius;
    Circle(int r) : radius(r)
    {
        cout << "circle CREATED" << endl;
    };
    ~Circle() { cout << "circle DESTROYED" << endl; }
    void display()
    {
        cout << "circle with radius: " << radius << endl;
    }
};

class Canvas
{
    unique_ptr<Circle> circle;

public:
    void addCircle(int r)
    {
        circle = make_unique<Circle>(r); // auto creat and manage circle
    };
    void displayCircle() const
    {
        if (circle)
        {
            circle->display();
        }
        else
        {
            cout << "no circle on canvas" << endl;
        }
    }
    // note : destructor for canvas not explicitly defined because unique_ptr auto deletes the Circle
};

int main()
{
    { // inner scope for organizing
        Canvas canvas;
        canvas.addCircle(100);  // add circle with 100 to the canvas
        canvas.displayCircle(); // display detail s about circle
    }                           // canvas goes out of scope here, and unique_ptr auto deletes the circle

    cout << "canvas has gone out of scope, circle auto destroyed" << endl;

    return 0;
}