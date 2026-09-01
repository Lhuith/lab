#ifndef TUPLES_CXX17_H
#define TUPLES_CXX17_H

#include <iostream>
#include <string>
#include <tuple>

using namespace std;

namespace tuplesCxx17 {

struct Test {
    int i;
    double d;
    string s;
    Test(int i, double d, string s) : i(i), d(d), s(s) {}
    void print() {
        cout << "i = " << i << ", d = " << d << ", s = " << s << endl;
    }
};

tuple<double, int, string> func() {
    // tuple<double, int, string> tup{1, 2.0, "three"s}; //c++11/14
    // tuple tup = {1, 2.0, "three"s};     // c++17 with CTAD;
    // return tup;
    // or
    return {1, 2.0, "three"s};     // return the tuple from the function
}

void func2(int i, double d, string s) {
    cout << "i = " << i << ", d = " << d << ", s = " << s << endl;
}

int main() {
    // // use c++17 structured binding
    auto [d, i, str] = func();
    cout << "the elements of the returned tuple are: " << d << ", " << i << R"(, ")" << str << R"(")" << endl;
    apply(func2, tuple(1, 2.0, "three"s));     // call func(1, 2.0, "three"s);

    auto test = make_from_tuple<Test>(tuple(1, 2.0, "three"s));     // call Test(1, 2.0, "three"s);
    test.print();

    return 0;
}
}     // namespace tuplesCxx17
#endif     // TUPLES_CXX17_H