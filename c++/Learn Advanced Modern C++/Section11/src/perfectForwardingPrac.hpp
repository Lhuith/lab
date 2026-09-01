#ifndef PERFECT_FORWARDING_PRAC_H
#define PERFECT_FORWARDING_PRAC_H

#include <iostream>
using namespace std;

namespace perfectForwardingPrac {

class test {
    string m_str;

   public:
    test(const string& str) : m_str(str) {
        cout << "const string& constructor called\n";
    }
    test(string&& str) : m_str(std::move(str)) {
        cout << "string&& constructor called\n";
    }
    // // < a massive fat shit amount of crazy black magic
    // template <class T>
    // test(T&& x) {
    //     test(std::forward<T>(x));     // > a huge amount of crazy black magic
    // }
};

void g(string& x) {
    std::cout << "modifiable version of g called\n";
}

void g(string&& x) {
    std::cout << "move version of g called\n";
}

template <class T>
test make_test(T&& x) {
    g(std::forward<T>(x));
    return test(std::forward<T>(x));
}

int main() {
    string hello{"Hello"};

    cout << "calling make_test() with lvalue argument\n";
    test t1 = make_test(hello);

    cout << "\ncalling make_test() with rvalue argument\n";
    test t2 = make_test(std::move(hello));
    cout << endl;

    return 0;
}
}     // namespace perfectForwardingPrac
#endif     // PERFECT_FORWARDING_PRAC_H