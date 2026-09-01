#include <iostream>
#include <string>
using namespace std;

int main()
{

    /*
        in:  James
        out: semaJ
    */

    string word = "lhuith"; // 5 characters

    // cout << word[4] << endl;
    // cout << word[3] << endl;
    // cout << word[2] << endl;
    // cout << word[1] << endl;
    // cout << word[0] << endl;

    for (int i = word.length() - 1; i >= 0; i--)
        cout << word[i];

    cout << endl;
}