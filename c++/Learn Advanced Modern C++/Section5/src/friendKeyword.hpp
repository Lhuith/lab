#ifndef FRIEND_KEYWORD_H
#define FRIEND_KEYWORD_H

#include <iostream>
using namespace std;

namespace friendKeyword {

class Test {
    int i{42};
    string s{"hello"};

   public:
    // friend class Example;
    void print() const {
        cout << "i = " << i << ", s = " << s << endl;
    }
};

// class Example {
//    public:
//     void print(const Test& test) {
//         cout << "i = " << test.i << ", s = " << test.s << endl;
//     }
// };

void print(const Test& test) {
    test.print();
}

int main() {
    Test test;
    print(test);
    // Example ex;
    // ex.print(test);

    return 0;
}
}     // namespace friendKeyword
#endif     // FRIEND_KEYWORD_H