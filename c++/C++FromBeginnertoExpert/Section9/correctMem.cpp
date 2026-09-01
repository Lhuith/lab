#include <iostream>

using namespace std;

int main()
{
    char *const inscription = new char[20]; // always make the array pointer constant
    inscription[0] = 'a';
    inscription[1] = 'b';
    inscription[2] = 'c';
    inscription[3] = '\0';

    char *reader = inscription;
    while (*reader)
        cout << reader++ << endl; // moving the pointer by doing ++

    delete[] inscription;
    return 0;
}