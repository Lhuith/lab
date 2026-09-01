#ifndef LAMBDA_EXPRESSIONS_PRAC_H
#define LAMBDA_EXPRESSIONS_PRAC_H

#include <iostream>
using namespace std;

namespace lambdaExpressionsPrac {

// case-insensitive string equality. returns true if lhs and rhs are equal, otherwise false
bool equal_strings(const string& lhs, const string& rhs) {
    // if the two strings have different lengths
    if (lhs.size() != rhs.size())
        return false;

    // if the two strings have the same lengths..
    auto lit = cbegin(lhs);
    auto rit = cbegin(rhs);

    while (lit != cend(lhs) && rit != cend(rhs)) {     // iterate over both strings
        if (toupper(*lit) != toupper(*rit))            // convert to upper case and compare
            return false;                              // characters are different
        ++lit;
        ++rit;
    }
    return true;     // no differences found
}

void test1(const string& str1, const string& str2) {
    cout << str1 << " and " << str2 << " are" << (equal_strings(str1, str2) ? "" : " not")
         << " equal" << endl;
}

bool equal_strings_algo(const string& lhs, const string& rhs) {
    // call equal() algo function using a lambda expression
    return equal(cbegin(lhs), cend(lhs), cbegin(rhs), cend(rhs),
                 [](char lc, char rc) { return toupper(lc) == toupper(rc); });
}

void test2(const string& str1, const string& str2) {
    cout << str1 << " and " << str2 << " are" << (equal_strings_algo(str1, str2) ? "" : " not")
         << " equal" << endl;
}

int main() {
    test1("lambda", "Lambda");
    test1("lambda", "lambada");
    cout << endl;
    test2("lambda", "Lambda");
    test2("lambda", "lambada");

    return 0;
}
}     // namespace lambdaExpressionsPrac
#endif     // LAMBDA_EXPRESSIONS_PRAC_H