#ifndef LAMBDA_C14_H
#define LAMBDA_C14_H

#include <iostream>
#include <string>

using namespace std;

namespace lambdaC14 {
int main() {
    // string str1{"Hello, "};
    // string str2{"World!"};

    // auto func = [](auto x, auto y) { return x + y; };

    // cout << "calling func(2, 5) gives " << func(2, 5) << endl;
    // cout << "calling func(3, 4) gives " << func(3, 4) << endl;
    // cout << R"(calling func (str1, str2) gives ")" << func(str1, str2) << R"(")" << endl;

    // cout << "helo from lambdaC14\n";

    int z = 1;
    auto add_two = [y = z + 1](int x) { return x + y; };

    cout << "calling add_two(2) gives " << add_two(2) << endl;
    cout << "calling add_two(5) gives " << add_two(5) << endl;

    return 0;
}
}     // namespace lambdaC14
#endif     // LAMBDA_C14_H