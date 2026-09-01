#include <iostream>

using namespace std;
// exceptions

class DivisionByZeroException
{
public:
    void getErrorMessage() { cout << "Error: can't divide by zero" << endl; }
};

double
division(double a, double b) throw(DivisionByZeroException)
{

    if (b == 0)
        throw DivisionByZeroException();

    return a / b;
}

int main()
{
    double result;

    try
    {
        result = division(5, 0);
        cout << "result = " << result << endl;
    }
    catch (DivisionByZeroException e)
    {
        e.getErrorMessage();
    }
    catch (...)
    {
        cout << "this <whatever> sucks" << endl;
    }
    cout << "other other instructions" << endl;

    return 0;
}