#ifndef MEMBER_NONMEMBER_H
#define MEMBER_NONMEMBER_H

#include <iostream>
using namespace std;

namespace memberNonmember {

class strung {
    string s;

   public:
    // constructors
    strung(const char* str) : s(str) {}
    strung(const string& s) : s(s) {}

    // strung operator+(const strung& arg) {
    //     return s + arg.s;
    // }

    strung& operator+=(const strung& rhs) {
        s += rhs.s;
        return *this;
    }

    void print() { cout << s << endl; }
};

// non member function using member function internally, preserving scope/data
strung operator+(const strung& lhs, const strung& rhs) {
    strung temp{lhs};
    temp += rhs;
    return temp;
}

int main() {
    strung w{"world"}, bang{"!"};
    strung wbang = w + bang;      // calls w.operator +(bang); OK
    strung hi = "hello " + w;     // cannot call "hello.operator + (w); compile error!"
    cout << "wbang: ";
    wbang.print();
    cout << "hi: ";
    hi.print();

    return 0;
}
}     // namespace memberNonmember
#endif     // MEMBER_NONMEMBER_H