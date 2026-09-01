#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

bool filesEqual(fstream *, fstream *);
int sizeOfFile(fstream *);

int main()
{

    /*
        read(where to read, how many bytes to read);
        memcmp - comparing memory
    */

    fstream file1, file2;

    file1.open("text/sample2.txt", ios::in | ios::binary | ios::ate);
    file2.open("text/sample3.txt", ios::in | ios::binary | ios::ate);

    if (file1.is_open() && file2.is_open())
    {
        if (filesEqual(&file1, &file2))
        {
            cout << "files are equal" << endl;
        }
        else
            cout << "files are not equal!" << endl;
    }
    else
        cout << "this file could'nt be opened" << endl;

    return 0;
}

bool filesEqual(fstream *a, fstream *b)
{
    int fileSize1 = sizeOfFile(a);
    int fileSize2 = sizeOfFile(b);

    if (!(fileSize1 == fileSize2))
    {
        cout << "size of file is not equal" << endl;
        return false;
    }

    int BUFFER_SIZE; // same size so far

    if (fileSize1 > 1024)
        BUFFER_SIZE = 1024;
    else
        BUFFER_SIZE = fileSize1;

    char *file1Buffer = new char[BUFFER_SIZE];
    char *file2Buffer = new char[BUFFER_SIZE];

    do
    {
        a->read(file1Buffer, BUFFER_SIZE);
        b->read(file2Buffer, BUFFER_SIZE);

        if (memcmp(file1Buffer, file2Buffer, BUFFER_SIZE) != 0)
        {
            cout << "characters don't match" << endl;
            delete[] file1Buffer;
            delete[] file2Buffer;
            return false;
        }

    } while (a->good() && b->good());

    delete[] file1Buffer;
    delete[] file2Buffer;

    return true;
}

int sizeOfFile(fstream *f)
{
    f->seekg(0, ios::end);
    int sizeOfFile = f->tellg();
    f->seekg(0, ios::beg);
    return sizeOfFile;
}