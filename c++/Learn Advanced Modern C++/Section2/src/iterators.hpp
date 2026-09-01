#ifndef ITERATE_H
#define ITERATE_H

#include <iostream>
#include <vector>

using namespace std;

namespace iterate
{
    void vectorIterator()
    {
        vector<int> vec{3, 1, 4, 1, 5, 9};
        vector<int>::iterator it = vec.begin();

        while (it != vec.end())
        {
            cout << *it << ", ";
            ++it;
        }
        cout << "\n";
    }

    void stringIterator()
    {
        string str{"Helloooooo"};
        string::iterator it = str.begin(); // start of string

        while (it != str.end()) // gone past last element?
        {
            cout << *(it) << ", ";
            ++it;
        }
        cout << "\n";
        string str2{"helllloo"};
        for (string::iterator it = str2.begin(); it != str2.end(); ++it)
        {
            cout << *it << ", ";
        }
        cout << "\n";
    }

    int main()
    {
        // const char str[] = {'H', 'e', 'l', 'l', 'o'};

        // const char *pEnd = str + 5; // pointer to element after last element
        // const char *p = str;        // start of array

        // while (p != pEnd) // gone past last element?
        // {
        //     cout << *p << ", "; // increment to move to next element
        //     ++p;
        // }

        stringIterator();
        vectorIterator();

        return 0;
    }
}

#endif // ITERATE_H