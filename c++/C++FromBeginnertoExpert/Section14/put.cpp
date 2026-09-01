#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    /*
        put(characters into on stream)
    */

    string txt = "thistextisconnected";

    // for (int i = 0; i < txt.length(); i++)
    // {
    //     cout.put(txt[i]).put(' ');
    // }
    fstream file;
    file.open("text/test2.txt", ios::out | ios::binary);

    if (file.is_open())
    {
        char c;
        do
        {
            c = cin.get();
            file.put(c);
        } while (c != '.');
    }
    else
        cout << "cannot read file" << endl;
    return 0;
}