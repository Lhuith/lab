#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include <forward_list>
#include <iostream>

using namespace std;

namespace forwardList {
int main() {
    forward_list<int> l{4, 3, 1};     // create a list object

    cout << "initial element in list" << endl;
    for (auto el : l)     // use a range-for loop to display all the elements
        cout << el << ", ";
    cout << endl;

    auto second = l.begin();
    advance(second, 1);            // i is an iterator to the second element
    l.insert_after(second, 2);     // insert a new element after the first element

    cout << "elements in the list after inserting 2" << endl;
    for (auto el : l)
        cout << el << ", ";
    cout << endl;

    l.erase_after(second);     // remove this element
    cout << "elements in list after erasing 2" << endl;
    for (auto node : l)
        cout << node << ", ";
    cout << endl;

    return 0;
}
}     // namespace forwardList
#endif     // FORWARD_LIST_H