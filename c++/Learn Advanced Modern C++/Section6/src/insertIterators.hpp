#ifndef INSERT_ITERATORS_H
#define INSERT_ITERATORS_H

#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

namespace insertIterators {

void insertStream() {
    cout << "enter some words: " << endl;

    istream_iterator<string> iis(cin);     // iterator to read strings
    istream_iterator<string> eof;          // empty iterator

    vector<string> vec;     // vector to store input
    auto it = back_inserter(vec);

    while (iis != eof) {     // do we have any input to read?
        it = *iis;           // yes - store it in the vector
        ++iis;               // move to next input
    }

    cout << "you entered " << vec.size() << " words: ";
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;
}

int main() {
    // vector<int> vec;     // create an empty vector

    // cout << "calling back_inserter()\n";
    // auto it = back_inserter(vec);     // get an insert iterator for vec

    // // assign to this iterator
    // cout << "assigning to inserter iterator\n";
    // // *it = 99;     // calls vec.push_back(99);
    // // *it = 88;     // calls vec.push_back(88);

    // // // vector elements are now {99, 88}
    // // cout << "vector has: " << vec.size() << " elements: ";
    // // for (auto v : vec)
    // //     cout << v << ", ";
    // // cout << endl;

    // vector<int> vec = {1, 2, 3};     // create elements

    // // print out vector elements
    // cout << "vector: ";
    // for (auto v : vec)
    //     cout << v << ", ";
    // cout << endl;

    // auto el2 = next(begin(vec));      // get an iterator to the second element
    // auto it = inserter(vec, el2);     // get insert iterator for vec

    // // assign to this iterator
    // *it = 99;     // calls vec.insert(el2, 99);

    // // vec now contains {1, 99, 2, 3}
    // cout << "vector after insert: ";
    // for (auto v : vec)
    //     cout << v << ", ";
    // cout << endl;

    // cout << "data at el2: ";
    // cout << *el2 << endl;
    insertStream();

    return 0;
}
}     // namespace insertIterators
#endif     // INSERT_ITERATORS_H