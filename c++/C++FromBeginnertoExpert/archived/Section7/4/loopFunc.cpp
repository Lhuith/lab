#include <iostream>
#define PI 3.14

using namespace std;

void initMenu();
void menuDecision(int);
double areaCircle(double);
double areaSquare(double);
double areaRectangle(double, double);
double areaTriangle(double, double);

int main() {
    int choice;
    char cont;
    do {
        system("cls"); // clear screen
        initMenu();
        cin >> choice;

        menuDecision(choice);
        do {
            cout << "continue? (y/n)" << endl;
            cin >> cont;
        } while(cont != 'y' && cont != 'Y' && cont != 'N' && cont != 'n');

    } while(cont == 'y' || cont == 'Y');

    return 0;
}

void initMenu() {
    cout << "Enter option:" << endl;
    cout << "1. Circle" << endl;
    cout << "2. Squre" << endl;
    cout << "3. Rectangle" << endl;
    cout << "4. Triangle" << endl;
}

void menuDecision(int choice) {

    double r, a, b, h;
    switch(choice) {
    case 1:
        cout << "Enter the radius of circle: " << endl;
        cin >> r;
        areaCircle(r);
        break;
    case 2:
        cout << "Enter the side of square: " << endl;
        cin >> a;
        areaSquare(a);
        break;
    case 3:
        cout << "Enter the width and height of rectangle : " << endl;
        cin >> a >> b;
        areaRectangle(a, b);
        break;
    case 4:
        cout << "Enter the base and height of triangle: " << endl;
        cin >> a >> h;
        areaTriangle(a, h);
        break;
    default:
        cout << "option doesn't exist!" << endl;
    }
}

double areaCircle(double r) {
    double result = PI * r * r;
    cout << "area of circle = " << result << ", with radius: " << r << endl;
}

double areaSquare(double a) {
    double result = a * a;
    cout << "area of square = " << result << ", with side: " << a << endl;
}

double areaRectangle(double a, double b) {
    double result = a * b;
    cout << "area of rectangle = " << result << ", with width: " << a << " and height: " << b << endl;
}

double areaTriangle(double a, double h) {
    double result = (1/2.0) * a * h;
    cout << "area of triangle = " << result << ", with base: " << a << " and height: " << h << endl;
}

