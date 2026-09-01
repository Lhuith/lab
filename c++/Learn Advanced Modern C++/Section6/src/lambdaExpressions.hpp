#ifndef LAMBDA_EXPRESSIONS_H
#define LAMBDA_EXPRESSIONS_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace lambdaExpressions {

// class is_odd {
//    public:
//     bool operator()(const int n) const { return (n % 2 == 1); }
// };

int main() {
    vector<int> vec{3, 1, 4, 1, 5, 9};

    // pass a functor object
    auto odd_it = find_if(cbegin(vec), cend(vec), [](int n) { return (n % 2 == 1); });

    // odd_it will be an iterator to the first odd element (if there is one)
    if (odd_it != cend(vec))
        cout << "first odd element is: " << [](int n) -> string { return to_string(n); }(*odd_it) << endl;

    return 0;
}
}     // namespace lambdaExpressions
#endif     // LAMBDA_EXPRESSIONS_H