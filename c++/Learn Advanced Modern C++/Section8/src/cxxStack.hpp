#ifndef CXX_STACK_H
#define CXX_STACK_H

#include <iostream>
#include <stack>

using namespace std;

namespace cxxStack {
void print(const stack<int>& s) {
    cout << "the stack contains " << s.size() << " elements\n";
    cout << "the top element is " << s.top() << endl;
    cout << "the stack is empty? " << boolalpha << s.empty() << "\n";
    cout << noboolalpha << endl;     // boy scout coder
}
int main() {
    stack<int> s;     // creat a stack object
    s.push(1);
    s.push(2);
    s.push(5);
    print(s);

    // adding a new element to teh stack
    cout << "\nadding element with value 3\n";
    s.push(3);
    print(s);

    // remove the top element
    cout << "\nremoving the top element\n";
    s.pop();
    print(s);

    return 0;
}
}     // namespace cxxStack
#endif     // CXX_STACK_H