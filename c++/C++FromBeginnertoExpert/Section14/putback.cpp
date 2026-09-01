#include <iostream>

using namespace std;
// putback

int main()
{
    char c = cin.get();
    cin.putback(c);
    if (c > '0' && c < '9')
    {
        int number;
        cin >> number;

        cout << "Number is: " << number << endl;
    }
    else
    {
        string txt;
        cin >> txt;

        cout << "Text is: " << txt << endl;
    }
    return 0;
}