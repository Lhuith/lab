#ifndef CXX_SETS_H
#define CXX_SETS_H

#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

namespace cxxSets {
void print(const set<int>& s) {
    cout << "elements of set: ";

    for (auto el : s)     // use a range-for loop to display all the elements
        cout << el << ", ";
    cout << endl
         << endl;
}

int main() {
    set<int> s;      // create an empty std::set
    s.insert(6);     // add some elements to it
    s.insert(7);     // the argument to insert is the key ofd the element
    s.insert(4);
    s.insert(5);
    s.insert(3);
    print(s);

    // auto ret = s.insert(3);
    // if (ret.second)
    //     cout << "added element with key 3 to set\n";
    // else
    //     cout << "set already contains element with key " << *(ret.first) << endl;

    // print(s);

    // cout << "removing element with key 3\n";
    // s.erase(3);
    // print(s);

    // auto ret2 = s.insert(3);
    // if (ret2.second)
    //     cout << "added element with key 3 to set\n";
    // else
    //     cout << "set already contains element with key " << *(ret2.first) << endl;

    // print(s);

    // cout << "calling find(7)\n";
    // auto it = s.find(7);

    // if (it != s.end())
    //     cout << "the set has an element with the key " << *it << endl;
    // else
    //     cout << "the set has not element with the key 7\n";

    // // cout << "changing the element's value to 11\n";
    // // *it = 11;

    // cout << "\ncalling count(7)\n";
    // auto n = s.count(7);

    // if (n == 1)
    //     cout << "the set has 1 element with key 7\n";
    // else
    //     cout << "the set has 0 elements with key 7\n";

    cout << "calling find(7)\n";
    auto it = find_if(cbegin(s), cend(s), [](int n) { return n == 7; });

    if (it != s.end())
        cout << "the set has an element with key " << *it << endl;
    else
        cout << "the set has no element with key 7\n";

    cout << "\ncalling count(7)\n";
    auto n = count_if(cbegin(s), cend(s), [](int n) { return n == 7; });

    if (n == 1)
        cout << "the set has 1 element with key 7\n";
    else
        cout << "the set has 0 elements with key 7\n";

    return 0;
}
}     // namespace cxxSets
#endif     // CXX_SETS_H