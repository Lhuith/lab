#include <iostream>
#include <string>

using namespace std;

int getDigits(int);

int main()
{

    /*
        in :  5245
        out : 5
    */
    cout << "no. of digits: " << getDigits(1000000) << endl;
    return 0;
}

int getDigits(int n) // COPY, not & or *
{
    int digits = 1;
    while (n /= 10)
        digits++;

    return digits;
}