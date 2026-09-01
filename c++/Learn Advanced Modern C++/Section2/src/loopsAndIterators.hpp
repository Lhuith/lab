#ifndef LOOPS_ITERATORS_H
#define LOOPS_ITERATORS_H

#include <iostream>
using namespace std;

namespace loopsIterate
{

    void rangedForLoops()
    {
        vector<int> vec = {1, 2, 3, 4};

        cout << "vector elements: " << endl;
        for (auto el : vec)
            cout << el << ", ";

        cout << endl
             << "adding 2 to each element" << endl;
        for (auto &el : vec)
            el += 2;

        cout << endl
             << "vector elements by const ref (no copy)" << endl;
        for (const auto &el : vec)
            cout << el << ", ";

        cout << endl
             << "modified vector elements: " << endl;
        for (auto el : vec)
            cout << el << ", ";
        cout << endl;
    }

    void arrayIterator()
    {
        int arr[] = {1, 2, 3, 4, 5};

        cout << "Iterator: ";
        for (auto it = begin(arr); it != end(arr); ++it)
            cout << *it << ", ";

        cout << endl
             << "const iterator: ";
        for (auto it = cbegin(arr); it != cend(arr); ++it)
            cout << *it << ", ";

        cout << endl
             << "Reverse iterator: ";
        for (auto it = rbegin(arr); it != rend(arr); ++it)
            cout << *it << ", ";

        cout << endl
             << "const reverse iterator: ";
        for (auto it = crbegin(arr); it != crend(arr); ++it)
            cout << *it << ", ";
    }

    int main()
    {
        // string str{"Hello"};

        // cout << "Iterator: ";
        // for (auto it = str.begin(); it != str.end(); ++it)
        //     cout << *it << ", ";

        // cout << endl
        //      << "const iterator: ";
        // for (auto it = str.cbegin(); it != str.cend(); ++it)
        //     cout << *it << ", ";

        // cout << endl
        //      << "Reverse iterator: ";
        // for (auto it = str.rbegin(); it != str.rend(); ++it)
        //     cout << *it << ", ";

        // cout << endl
        //      << "const reverse iterator: ";
        // for (auto it = str.crbegin(); it != str.crend(); ++it)
        //     cout << *it << ", ";

        // cout << "\n";

        // arrayIterator();

        rangedForLoops();
        cout << "\n";
        return 0;
    }
}

#endif