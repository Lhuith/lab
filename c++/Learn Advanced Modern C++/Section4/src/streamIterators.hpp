#ifndef STREAM_ITERATORS_H
#define STREAM_ITERATORS_H

#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

namespace streamIterators {
void inputStream2() {
    istream_iterator<string> iis(cin);     // iterator to read strings
    istream_iterator<string> eof;          // empty iterator

    vector<string> vs;     // vector to store input;

    while (iis != eof)            // do we have anu input to read?
        vs.push_back(*iis++);     // yes - store in the vector, 	// ++iis, move to next input
                                  // cout << "you typed: " << *iis << "\n";

    for (auto v : vs)
        cout << v << endl;
}
void inputStream() {
    cout << "please enter a number: " << endl;

    // iterator that will read ints from cin
    istream_iterator<int> ii(cin);

    // read an int from the stream
    int x = *ii;     // this will read a number from cin into the variable x
    cout << "you entered " << x << endl;
}
int main() {
    // write the numers 0, ... , 9 to the display followed by a newline
    // ostream_iterator<int> oi(cout, "\n"); // create the output stream iterator

    // for (int i = 0; i < 10; ++i)
    // {
    // 	*oi = i; // prints the number followed by "\n"
    // 	++oi;	 // move to next element in the sequence;
    // }

    inputStream2();

    return 0;
}
}     // namespace streamIterators
#endif     // STREAM_ITERATORS_H