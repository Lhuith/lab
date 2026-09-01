#ifndef PALINDROME_CHECKER_H
#define PALINDROME_CHECKER_H

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

namespace palindromeChecker {

// return a copt of the argument string
// with non-alphabetical characters removed and converted to lower case
string normalize(const string& s) {
    string retval{""};

    copy_if(cbegin(s), cend(s), back_inserter(retval),
            [](char c) { return isalpha(c); });
    transform(begin(retval), end(retval), begin(retval),
              [](char c) { return tolower(c); });

    return retval;
}

int main() {
    string s{""};
    cout << "please enter your palindrome: ";
    getline(cin, s);

    // input string with punctuation and spaces removed
    string pal{normalize(s)};

    // call mismatch to compare the string to its reverse
    // use reverse iterator
    auto p = mismatch(cbegin(pal), cend(pal), crbegin(pal));

    // the return value from mismatch() is a pair of iterators
    // these point to the first mismatched element in each range
    if (p.first == cend(pal) && p.second == crend(pal)) {
        // no mismatch found - the string is the same in both directions
        cout << "\"" << s << "\" is a palindrome\n";
    } else {
        // there is a mismatch
        // the character at p.first does not match the character at p.second
        cout << "\"" << s << "\"" << " is not a palindrome\n";

        // make a copy of the string, up to the mismatch in the reversed string
        string outstr;
        copy(cbegin(pal), p.second.base(), back_inserter(outstr));
        cout << "\'" << *(p.first) << "\'" << " does not match " << "\'" << *(p.second) << "\'";
        cout << " at \"" << outstr << "\"" << endl;
    }

    return 0;
}
}     // namespace palindromeChecker
#endif     // PALINDROME_CHECKER_H