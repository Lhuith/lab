#ifndef MULTI_SETMAP_H
#define MULTI_SETMAP_H

#include <iostream>
#include <map>
#include <set>

using namespace std;

namespace multiSetmap {
int main() {
    multiset<int> s;     // create empty std::multiset
    s.insert(6);         // add some elements to it
    s.insert(7);
    s.insert(4);
    s.insert(6);
    s.insert(6);     // add duplicate

    for (auto el : s)
        cout << el << ", ";
    cout << endl;

    multimap<string, int> scores;       // create an empty std::multimap;
    scores.insert({"Graham"s, 78});     // add some elements to it
    scores.insert({"Grace"s, 66});
    scores.insert({"Graham", 66});     // add duplicates
    scores.insert({"Graham", 72});
    scores.insert({"Hareesh"s, 77});

    // scores.erase("Graham");     // erase all elements with the key "Graham"

    // for (auto s : scores)
    //     cout << s.first << " has score of " << s.second << endl;

    auto res = scores.find("Graham");     // find first element with key "Graham"

    if (res != end(scores)) {                        // do we have any results?
        auto n_matches = scores.count("Graham");     // find number of match elements

        // loop over the matching elements
        for (size_t i = 0; i < n_matches; ++i) {
            bool lookFor = false;
            // search for particular value per sub-set
            lookFor = res->second == 66;
            cout << "key = " << res->first << ", value = " << res->second << ((lookFor) ? ", and who we were looking for!" : "") << endl;
            ++res;
        }
    }

    return 0;
}
}     // namespace multiSetmap
#endif     // MULTI_SETMAP_H