#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    fstream file; // file(("text/sample.txt", ios::out)) exists too
    file.open("text/sample.txt", ios::out | ios::app);

    /*
        ios::in - INPUT - Reading

        ios::out - OUTPUT - Write to file, if there is no file, create it, if there is file purge file unless it occurs in ios:in

        ios::trunc - truncate - cutting everything inside

        ios::ate - at the end - sets pointer to the end of file - pointer place can be changed, possble to r/w in this mode

        ios::app - append - content is added to end of file (not possible to remove content nor adding something in other place at the EOF)

        ios::binary - opens as binary file


     */

    /*
        Default mode (Flags)
        fstream - ios::out | ios::in
        ifstream - ios::in
        ofstream - ios::out
     */

    if (file.is_open())
    {
        file << "sample text \n";
        file << "sample text \n";

        file.close();
    }
    else
        cout << "the file isn't opened properly" << endl;

    return 0;
}