#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    /*
        write
    */

    fstream file;
    file.open("text/sample4.txt", ios::out | ios::binary);

    if (file.is_open())
    {
        char sample[] = "sample text";
        cout << sizeof(sample) << endl;
        file.write(sample, sizeof(sample) - 1);
    }
    else
        cout << "couldn't open the file" << endl;

    return 0;
}