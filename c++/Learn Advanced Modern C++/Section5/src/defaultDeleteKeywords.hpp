#ifndef DEFAULT_DELETE_KEYWORDS_H
#define DEFAULT_DELETE_KEYWORDS_H

#include <iostream>
using namespace std;

namespace defaultDeleteKeywords {

class Test {
    //    private:
    //     Test(const Test&);                // copy constructor is private
    //     Test& operator=(const Test&);     // assignment operator is private

   public:
    Test(const Test&) = delete;                // deleted copy constructor
    Test& operator=(const Test&) = delete;     // deleted assignment operator
    // Test() {}
    Test() = default;     // tell compiler to synthesize
    // Test(const Test& other) { cout << "copying\n"; }     // copy constructor side effects
    operator int() const { return 1; }
};

// function returning a temporary object
// Test func() {
//     return Test();
// }

int main() {
    // cout << "calling func()" << endl;
    // Test test = func();     // compiler complains about unused, which is good :(
    // cout << test << endl;
    // cout << "returned from func()" << endl;

    Test t1, t2;     // use default constructor
    // Test t3(t1);     // error: copy constructor is private/deleted
    // t2 = t1;         // error: assignment operator is private/deleted

    cout << t1 << endl;
    cout << t2 << endl;
    // cout << t3 << endl;

    return 0;
}

}     // namespace defaultDeleteKeywords
#endif     // DEFAULT_DELETE_KEYWORDS_H