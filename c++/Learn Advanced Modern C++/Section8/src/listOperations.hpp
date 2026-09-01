#ifndef LIST_OPERATIONS_H
#define LIST_OPERATIONS_H

#include <algorithm>     // for std::sort
#include <forward_list>
#include <iostream>
#include <list>

using namespace std;

namespace listOperations {

void listSpliceForward() {
    forward_list<int> list1{1, 12, 6, 24};
    forward_list<int> list2{9, 3, 14};

    cout << "elements in list1" << endl;
    for (auto el : list1)
        cout << el << ", ";
    cout << endl;

    cout << "elements in list2" << endl;
    for (auto el : list2)
        cout << el << ", ";
    cout << endl;

    auto p = begin(list1);            // p is an iterator to the first element of list1 (with value 1)
    list1.splice_after(p, list2);     // insert elements of list2 after p

    cout << "elements in list 1 after splice" << endl;
    for (auto el : list1)
        cout << el << ", ";
    cout << endl;

    cout << "elements in list 2 after splice" << endl;
    for (auto el : list2)
        cout << el << ", ";
    cout << endl;
}

void listSplice() {
    list<int> list1{1, 12, 6, 24};
    list<int> list2{9, 3, 14};

    cout << "elements in list 1" << endl;
    for (auto el : list1)
        cout << el << ", ";
    cout << endl;

    cout << "elements in list 2" << endl;
    for (auto el : list2)
        cout << el << ", ";
    cout << endl;

    auto p = begin(list1);
    advance(p, 1);              // p is an iterator
    list1.splice(p, list2);     // insert elements elements of list2 before p

    cout << "elements in list1 after splice" << endl;
    for (auto el : list1)
        cout << el << ", ";
    cout << endl;

    cout << "elements in list2 after splice" << endl;
    for (auto el : list2)
        cout << el << ", ";
    cout << endl;
}

void listSort() {
    list<int> list1{1, 12, 6, 24};
    list<int> list2{9, 3, 14};

    cout << "elements in list 1" << endl;
    for (auto el : list1)
        cout << el << ", ";
    cout << endl;

    cout << "elements in list 2" << endl;
    for (auto el : list2)
        cout << el << ", ";
    cout << endl;

    list1.sort();     // make sure lists are sorted
    list2.sort();
    list1.merge(list2);     // list1 now contains 1, 3, 6, 9, 12, 14, 24 and list2 is empty

    cout << "elements in list 1 after splice" << endl;
    for (auto el : list1)
        cout << el << ", ";
    cout << endl;

    cout << "elements in list 2 after splice" << endl;
    for (auto el : list2)
        cout << el << ", ";
    cout << endl;
}

int main() {
    // list<int> l{4, 3, 1};     // create a list object

    // cout << "initial elements in the list" << endl;
    // for (auto el : l)     // use a range-for loop to display all the elements
    //     cout << el << ", ";
    // cout << endl;

    // // sort(begin(l), end(l));     // does not compile
    // l.sort();     // sort the list

    // cout << "elements in the last after sorting" << endl;
    // for (auto el : l)
    //     cout << el << ", ";
    // cout << endl;

    // l.remove(3);     // remove element with value 3

    // cout << "elements in the list after removing 3" << endl;
    // for (auto el : l)
    //     cout << el << ", ";
    // cout << endl;

    // listSort();
    // listSplice();
    listSpliceForward();

    return 0;
}
}     // namespace listOperations
#endif     // LIST_OPERATIONS_H