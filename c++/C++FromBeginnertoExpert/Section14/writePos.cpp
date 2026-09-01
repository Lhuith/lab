#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    /*
        tellp - tell put - tell where is the putting pointer
        seekp - seek put - sets writing (putting) pointer at specified position

        seekp(how_many_bytes_from_the_flag_place, flag);

        possible flags
        ios::beg - (begin) set from begin (Default)
        ios::end - set from the end
        ios::cur - (current) set from current place
    */

    fstream file;
    file.open("text/sample1.txt", ios::out | ios::binary);

    if (file.is_open())
    {
        string tmp = "this is text about nothing";
        file << tmp;
        cout << file.tellp() << endl;

        file.seekp(0, ios::beg);
        file << "T";
    }
    else
        cout << "The file couldn't be opened" << endl;

    return 0;
}