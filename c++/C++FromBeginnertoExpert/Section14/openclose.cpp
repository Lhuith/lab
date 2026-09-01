#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream myFileHandler;
    myFileHandler.open("test.txt");

    if (myFileHandler.is_open())
    {
        myFileHandler << "this is sample text 1 \n";
        myFileHandler << "this is sample text 2 \n";
        myFileHandler.close();
    }

    return 0;
}