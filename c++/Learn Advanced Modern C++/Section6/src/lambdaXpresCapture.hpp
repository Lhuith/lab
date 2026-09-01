#ifndef LAMBDA_XPRES_CAPTURE_H
#define LAMBDA_XPRES_CAPTURE_H

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// int global{99};     // non-local variable

namespace lambdaXpresCapture {

int main() {     // scope containing the lambda expression

    // what this lambda will generator from compiler
    // [n, &idx](const string& str) { return str.size() > (size_t)n; }
    class ge_n {
       private:
        const int n;
        int& idx;

       public:
        ge_n(const int n, int& idx) : n(n), idx(idx) {}

        bool operator()(const string& str) const {
            ++idx;
            return str.size() > (size_t)n;
        }
    };

    // static int answer{42};     // static variable in containing scope
    // const int one{1};          // local variable in containing scope
    // // const int& r_one{one};     // local variable in containing scope

    // []() {                          // start of lambda body
    //     cout << global << endl;     // lambda body can access non-local variables
    //     cout << answer << endl;     // lambda body can access static variables
    //     // does not compile with v-c++
    //     cout << one << endl;     // lambda body can read local variables, provided ...
    //     // does not compile with v-c++, gcc or clang
    //     // cout << r_one << endl;     // lambda body can read local variables, provided ...
    // };     // end of lambda body

    vector<string>
        words{"a", "collection", "of", "words", "with", "varying", "lengths"};

    // int n{3};
    // // find the first element with more than 5 characters
    // auto res = find_if(cbegin(words), cend(words),
    //                    [n](const string& str) { return str.size() > (size_t)n; });     // lambda captures local variable n

    // // display it
    // if (res != cend(words)) {
    //     cout << R"(the first word which is more than 5 letters long is ")";
    //     cout << *res << R"(")" << endl;
    // }

    // int max{5}, idx{-1};     // add another variable for the index of the match
    // auto res = find_if(cbegin(words), cend(words),
    //                    [max, &idx](const string& str) {++idx; return str.size() > (size_t)max; });

    int max{5}, idx{-1};     // add another variable for the index of the match
    auto res = find_if(cbegin(words), cend(words), ge_n(max, idx));

    // display it
    if (res != cend(words)) {
        cout << R"(the first word which is more than ")";
        cout << *res << R"(")" << endl;
        cout << "the index is: " << idx << endl;
    }

    return 0;
}     // end of scope containing lambda expression
}     // namespace lambdaXpresCapture
#endif     // LAMBDA_XPRES_CAPTURE_H