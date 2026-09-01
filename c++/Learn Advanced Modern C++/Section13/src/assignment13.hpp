#ifndef ASSIGNMENT13_H
#define ASSIGNMENT13_H

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

extern "C" {
#include "assignment13.h"
}

using namespace std;

namespace assignment13 {

int main() {
    set<int> s{1, 2, 3, 4, 1, 4, 2, 11, 4};
    vector<int> vec;
    copy(cbegin(s), cend(s), back_inserter(vec));

    display_int_array(vec.data(), vec.size());

    vector<int> values;
    vector<string> keys;
    map<string, int> m{
        make_pair("1", 1),
        make_pair("2", 2),
        make_pair("3", 3),
        make_pair("4", 4),
        make_pair("5", 5)};

    for (auto [key, value] : m) {
        keys.push_back(key);
        values.push_back(value);
    }

    // https://stackoverflow.com/questions/19082701/how-to-convert-a-string-array-to-a-char-array-c
    // thanks Dietmar Kühl
    vector<char*> keys_c;
    std::transform(std::begin(keys), std::end(keys),
                   std::back_inserter(keys_c),
                   [](std::string& s) {s.push_back(0); return &s[0]; });

    display_char_array(keys_c.data(), keys_c.size());
    display_int_array(values.data(), values.size());

    return c_main();
}
}     // namespace assignment13
#endif     // ASSIGNMENT13_H