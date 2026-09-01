#ifndef TWO_D_ARRAY_H
#define TWO_D_ARRAY_H

#include <iostream>
using namespace std;

namespace twoD
{

    void twoD()
    {
        string names[2][4] = {
            {"Fred", "Wilma", "Pebbles", "Dino"},
            {"Barney", "Betty", "Bamm-Bamm", "Hoppy"},
        };

        cout << "names[1][2] = " << names[1][2] << endl;

        cout << "element names are:\n";
        for (int row = 0; row < 2; ++row)
        {
            for (int col = 0; col < 4; ++col)
            {
                cout << names[row][col] << ", ";
            }
            cout << "\n";
        }
    }

    void oneD() // pointer deref vs math multiplication optimization
    {
        string names[] = {
            "Fred",
            "Wilma",
            "Pebbles",
            "Dino",
            "Barney",
            "Betty",
            "Bamm-Bamm",
            "Hoppy"};
        cout << "names[1][2] = " << names[1 * 4 + 2] << endl;

        cout << "element names are:\n";
        for (int row = 0; row < 2; ++row)
        {
            for (int col = 0; col < 4; ++col)
            {
                cout << names[row * 4 + col] << ", ";
            }
            cout << "\n";
        }
    }

    int main()
    {
        twoD();
        cout << "\n";
        oneD();
        return 0;
    }
}

#endif // TWO_D_ARRAY_H