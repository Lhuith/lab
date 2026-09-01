#ifndef STATEMENTS_SWITCHES_H
#define STATEMENTS_SWITCHES_H

#include <iostream>
#include <vector>
using namespace std;

namespace statementsSwitches
{
    void switchStatements()
    {
        int ws_count{0};

        const char *arr = "how much whitespace in\t here?";
        cout << "the text to process is \"" << arr << "\"" << endl;

        for (int i = 0; arr[i]; ++i)
        {
            switch (const char c = arr[i]; c)
            {
            case ' ': // c is space character
                [[fallthrough]];
            case '\t': // c is tab character
                [[fallthrough]];
            case '\n': // c is newline character
                ++ws_count;
                break;
            default: // c is not a whitespace character
                break;
            }
        }

        cout << "the text contains " << ws_count << " white spaces" << "\n";
    }

    int main()
    {
        // vector<int> vec = {1, 2, 3};

        // // older c++
        // auto iter = begin(vec);
        // if (iter != end(vec))
        // {
        //     // safe to use the iterator here
        //     cout << "first element of vec is: " << *iter << endl;
        // }

        // // c++ 17
        // if (auto iter = begin(vec); iter != end(vec))
        // {
        //     // safe to use iterator here
        //     cout << "first element of vec is: " << *iter << endl;
        // }
        switchStatements();

        return 0;
    }
}

#endif // STATEMENTS_SWITCHES_H