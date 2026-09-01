#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    /*
        gcount - getCharacter count - get count of extracted characters from last extract op
    */

    fstream file;
    file.open("text/sample5.txt", ios::in | ios::binary);

    if (file.is_open())
    {
        char buffer[250];
        do
        {
            file.getline(buffer, 250);
            cout << file.gcount() << " " << buffer << endl;
        } while (!(file.eof()));
    }
    else
        cout << "file couldn't be opened" << endl;

    return 0;
}