#ifndef LIST_CONTAINER_H
#define LIST_CONTAINER_H

#include <iostream>
#include <list>
using namespace std;

namespace listContainer {
int main() {
    list<int> l{4, 3, 1};     // create a list object

    cout << "initial elements in list" << endl;
    for (auto el : l)     // use a range-for loop to display all the elements
        cout << el << ", ";
    cout << endl;

    auto last = end(l);
    advance(last, -1);                // i is an iterator to the last element
    auto two = l.insert(last, 2);     // insert a new element before the last element

    cout << "elements in the list after inserting 2" << endl;
    for (auto el : l)
        cout << el << ", ";
    cout << endl;

    l.erase(two);     // remove this element

    cout << "elements in the list after erasing 2" << endl;
    for (auto node : l)
        cout << node << ", ";
    cout << endl;

    return 0;
}
}     // namespace listContainer
#endif     // LIST_CONTAINER_H