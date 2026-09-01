#include <iostream>
#include <limits>
#define PI 3.14

using namespace std;

void initMenu();
void menuDecision(int);
double areaCircle(double);
double areaSquare(double);
double areaRectangle(double, double);
double areaTriangle(double, double);
bool isValid(string);
bool isValid();

int main() {
    int choice;
    char cont;
    do {
        system("cls"); // clear screen
        initMenu();

        while(!(cin >> choice)) {
            //cout << "state before: " << cin.rdstate() << endl;
            cin.clear();
            //cout << "state after: " << cin.rdstate() << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            system("cls");
            initMenu();
            cout << "invalid value given, please use numeric values!" << endl;
        }

        menuDecision(choice);
        do {
            cout << "continue? (y/n)" << endl;
            cin >> cont;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
        do { cout << "Enter the radius of circle: " << endl; cin >> r; } while(!isValid());
        areaCircle(r);
        break;
    case 2:
        cout << "Enter the side of square: " << endl;
        do { cin >> a;  } while(!isValid("area is not a numerical value."));
        areaSquare(a);
        break;
    case 3:
        cout << "Enter the width and height of rectangle : " << endl;
        do { cin >> a >> b;} while(!isValid("width/height is not a numerical value."));
        areaRectangle(a, b);
        break;
    case 4:
        cout << "Enter the base and height of triangle: " << endl;
        do { cin >> a >> h;  } while(!isValid("base/height is not a numerical value."));
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

bool isValid(string error_msg) {
    if(cin.rdstate()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("cls");
        initMenu();
        cout << error_msg << endl;
        return false;
    }
    return true;
}

bool isValid() {
    if(cin.rdstate()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("cls");
        initMenu();
        return false;
    }
    return true;
}
