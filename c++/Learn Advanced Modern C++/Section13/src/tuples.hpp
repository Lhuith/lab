#ifndef TUPLES_H
#define TUPLES_H

#include <iostream>
#include <tuple>
using namespace std;

namespace tuples {

tuple<double, int, string> func() {
    return {1.0, 2, "Three"s};     // return the tuple from the function
}

int main() {
    // // we can create a tuple instance explicitly
    // tuple<double, int, string> numbers(1.0, 2, "Three"s);

    // // or use make_tuple() to create a tuple instance
    // // auto numbers{make_tuple(1.0, 2, "Three"s)};

    // auto x = get<0>(numbers);     // store first element in x
    // cout << "first element is " << x << endl;

    // cout << "setting second element to 3" << endl;
    // get<1>(numbers) = 3;     // set second element to 3

    // // c++14 allows us to use the type as the parameter, if unique
    // auto i = get<int>(numbers);     // store int element in i
    // cout << "value of int element is " << i << endl;

    // tuple<double, int, string> numbers(1.0, 2, "Three"s);

    // double d;
    // int i;
    // string str;

    // tie(d, i, str) = numbers;     // store all elements variables
    // cout << "tuple elements are: " << d << ", " << i << R"(, ")" << str << R"(")" << endl;

    double d;
    int i;
    string str;
    tie(d, i, str) = func();     // unpack the tuple in the caller
    tuple<double, int, string> t = func();

    cout << "elements of returned tuple are: " << d << ", " << i << R"(, ")" << str << R"(")" << endl;
    cout << "elements of returned tuple are: " << get<0>(t) << ", " << get<1>(t) << R"(, ")" << get<2>(t) << R"(")" << endl;
    return 0;
}
}     // namespace tuples
#endif     // TUPLES_H