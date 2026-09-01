#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    /*
        bad() - badbit (1) - returns true if error, like writing to file which was read only (ios::in)
        fail() - failbit (4) - returns true if we try to assign string to integer (& others) while reading or badbit
        eof() - eofbit (2) - true if the file opened to read reaches the end of file, duh


        1 - 001
        2 - 010
        4 - 100
            ---

        bitwise operators: & | ^

        ^
        110 - 6
        010 - 2
        100 - 4
        ^
        010
        010
        000

        rdstate() - reading state, duh
        good() - goodbit (0) if everything is fine, (or above flags are false)
        clear() - clear state
    */

    fstream file;
    file.open("text/sample.txt", ios::in);

    if (file.is_open())
    {
        string buffer;
        do
        {
            file >> buffer;
            cout << buffer << endl;

        } while (!file.eof());

        cout << (file.rdstate() ^ ifstream::eofbit) << endl;

        if ((file.rdstate() ^ ifstream::eofbit) == 0)
        {
            file.clear();
            // set indicator of place in file to some other place
            // some other operations on file
        }

        cout << file.rdstate() << endl;
    }
    else
        cout << "The file couldn't be opened" << endl;

    return 0;
}