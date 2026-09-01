#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    /*
        getline(where to store extractions, how many characters, deliminator) - extracts delim and deletes

        get(where to store extractions, how many characters, deliminator) - doesn't extract delim and deletes

        ignore(how_many_to_extract and ignore, deliminator) - extracts characters

        get();
    */

    fstream file;

    file.open("text/sample2.txt", ios::in | ios::binary);

    if (file.is_open())
    {
        char first, last;
        char buffer[50];

        cin.getline(buffer, 50);
        cout << buffer << endl;
        do
        {
            file.getline(buffer, 50, ' ');

            last = file.get();
            file.ignore(40, '\n');

            cout << buffer << " " << last << "." << endl;
        } while (!(file.eof()));
    }
    else
        cout << "the file couldn't be opened" << endl;

    return 0;
}