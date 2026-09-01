#ifndef ITERATOR_ARITH_H
#define ITERATOR_ARITH_H

#include <iostream>
using namespace std;

namespace iteratorArith
{

    void iteratorFuncs()
    {
        string str{"12345"};

        cout << "str: " << str << endl;
        cout << "number of elements: " << distance(begin(str), end(str)) << endl;

        auto second = next(begin(str)); // returns iterator to second element

        if (second != end(str))
            cout << "second element is: " << *second << endl;

        auto last = prev(end(str)); // returns iterator to last element

        if (last != end(str))
            cout << "last element is: " << *last << endl;

        // end() - begin() gives number of elements
        auto mid = begin(str);
        advance(mid, distance(begin(str), end(str)) / 2); // return iterator to middle element

        if (mid != end(str))
        {
            cout << "middle element is: " << *mid;
            cout << " with index " << distance(str.begin(), mid) << endl;
        }
    }

    int main()
    {
        // string str{"12345"};

        // cout << "str: " << str << endl;
        // cout << "number of elements: " << str.end() - str.begin() << endl;

        // auto second = begin(str) + 1; // iterator to second element
        // cout << "second element is: " << *second << endl;

        // auto last = end(str) - 1; // iterator to last element
        // cout << "last element is: " << *last << endl;

        // // end() - begin() gives number of elements
        // auto mid = begin(str) + (end(str) - begin(str)) / 2;
        // cout << "middle element is: " << *mid << endl;

        iteratorFuncs();
        return 0;
    }
}

#endif // ITERATOR_ARITH_H