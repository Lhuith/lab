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

int main()
{
    int choice;
    char ch;
    do
    {
        system("clear");
        initMenu();

        while (!(cin >> choice))
        {
            cout << "state before: " << cin.rdstate() << endl;
            cin.clear();
            cout << "state after: " << cin.rdstate() << endl;

            system("clear");
            initMenu();
            cout << "wrong input given, please use numbers" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        menuDecision(choice);

        do
        {
            cout << "continue? (y/n)" << endl;
            cin >> ch;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        } while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N');

    } while (ch == 'y' || ch == 'Y');

    return 0;
}

void initMenu()
{
    cout << "Enter option: " << endl;
    cout << "1. Circle" << endl;
    cout << "2. Square" << endl;
    cout << "3. Rectangle" << endl;
    cout << "4. Triangle" << endl;
}

void menuDecision(int choice)
{
    double r, a, b, h;
    switch (choice)
    {
    case 1:
        do
        {
            cout << "Enter the radius :" << endl;
            cin >> r;
        } while (!isValid());

        areaCircle(r);
        break;
    case 2:
        cout << "Enter the side of square :" << endl;
        do
        {
            cin >> a;
        } while (!isValid("the side is wrong"));

        areaSquare(a);
        break;
    case 3:
        cout << "Enter the width and height of rectangle :" << endl;
        do
        {
            cin >> a >> b;
        } while (!isValid("the width and height are wrong"));

        areaRectangle(a, b);
        break;
    case 4:
        cout << "Enter the base and height of a triangle :" << endl;
        do
        {
            cin >> a >> h;
        } while (!isValid("the base and height are wrong"));
        areaTriangle(a, h);
        break;
    default:
        cout << "no option choosen" << endl;
    }
}

double areaCircle(double r)
{
    double result = PI * r * r;
    cout << "area of circle with radius " << r << " = " << result << endl;
    return result;
}

double areaSquare(double a)
{
    double result = a * a;
    cout << "area of square with side " << a << " = " << result << endl;
    return result;
}

double areaRectangle(double a, double b)
{
    double result = a * b;
    cout << "area of rectangle with sides " << a << "," << b << " = " << result << endl;
    return result;
}

double areaTriangle(double a, double h)
{
    double result = (1 / 2.0) * a * h;
    cout << "area of triangle with base " << a << " and height " << h << " = " << result << endl;
    return result;
}

bool isValid(string error_msg)
{
    if (cin.rdstate()) // state is wrong when it is not empty / 0
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("clear");
        initMenu();
        cout << error_msg << endl;
        return false;
    }
    return true;
}

bool isValid()
{
    if (cin.rdstate())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("clear");
        initMenu();
        return false;
    }
    return true;
}