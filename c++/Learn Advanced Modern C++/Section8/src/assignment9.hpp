#ifndef ASSIGNMENT9_H
#define ASSIGNMENT9_H

#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using namespace std;

namespace assignment9 {

void writeSome(const string& container) {
    cout << "write some strings for (" << container << "): " << endl;
}

void readDeque(bool reverse = false) {
    writeSome("deque"s + ((reverse) ? " reverse"s : ""s));

    istream_iterator<string> iis(cin);
    istream_iterator<string> eof;

    deque<string> dq;

    while (iis != eof)
        if (!reverse)
            dq.push_back(*iis++);
        else
            dq.push_front(*iis++);

    cout
        << "looks like you wrote: ";
    for (auto v : dq)
        cout << "\"" << v << "\"" << ", ";
    cout << endl;
}

void readList(bool reverse = false) {
    writeSome("list"s + ((reverse) ? " reverse"s : ""s));
    istream_iterator<string> iis(cin);
    istream_iterator<string> eof;

    list<string> lst;

    while (iis != eof)
        if (!reverse)
            lst.push_back(*iis++);
        else
            lst.push_front(*iis++);

    cout << "looks like you wrote: ";
    for (auto v : lst)
        cout << "\"" << v << "\"" << ", ";
    cout << endl;
}

void readVector() {
    writeSome("vector"s);

    istream_iterator<string> iis(cin);
    istream_iterator<string> eof;

    vector<string> vec;

    while (iis != eof) {
        vec.push_back(*iis++);
    }

    cout << "looks like you wrote: ";
    for (auto v : vec)
        cout << "\"" << v << "\"" << ", ";
    cout << endl;
}

int main(int argc, char* argv[]) {
    bool isReveres;

    switch (argc) {
        case 3:
            isReveres = argv[2] == "r"s;
        case 2:
            switch (*argv[1]) {
                case 'd':
                    readDeque(isReveres);
                    break;
                case 'l':
                    readList(isReveres);
                    break;
            }
            break;
        default:
            readVector();
    }
    return 0;
}
}     // namespace assignment9
#endif     // ASSIGNMENT9_H