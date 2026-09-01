#ifndef SEARCHING_MULTIMAPS_H
#define SEARCHING_MULTIMAPS_H

#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

namespace searchingMultimaps {

void print(const pair<string, int>& score) {
    cout << "(\"" << score.first << "\", " << score.second << "), ";
}

int main() {
    multimap<string, int> scores;     // create an instance of std::multimap
    scores.insert({"Graham", 78});
    scores.insert({"Grace", 66});
    scores.insert({"Graham", 66});
    scores.insert({"Hareesh", 77});
    scores.insert({"Graham", 66});

    cout << "multimap elements: " << endl;
    for (auto score : scores)
        print(score);
    cout << endl;

    // // elements are in the order "Grace", |> "Graham", "Graham", "Graham", |> "Hareesh"
    // auto gra_first = scores.lower_bound("Graham");     // returns an iterator to "Graham"
    // auto gra_last = scores.upper_bound("Graham");      // returns an iterator to "Hareesh"

    // cout << endl
    //      << "scores for Graham: " << endl;
    // for (auto it = gra_first; it != gra_last; ++it) {
    //     print(*it);
    //     if (it->second == 66) {
    //         cout << "<-- looking for, ";
    //     }
    // }

    // auto gord_first = scores.lower_bound("Gordon");     // returns an iterator to "Grace"
    // auto gord_last = scores.upper_bound("Gordon");      // returns an iterator to "Grace"

    // cout << endl
    //      << endl
    //      << "lower_bound(\"Gordon\") returned ";
    // print(*gord_first);
    // cout << endl;

    // cout << endl
    //      << "Scores for Gordon: " << endl;
    // for (auto it = gord_first; it != gord_last; ++it)
    //     print(*it);

    // auto gra_keys = scores.equal_range("Graham");
    // cout << endl
    //      << "results for Graham: " << endl;

    // for (auto it = gra_keys.first; it != gra_keys.second; ++it)
    //     print(*it);
    // cout << endl;

    // C++17
    /*
        auto[start, finish] = scores.equal_range("Graham");

        cout << endl << "results from Graham: " << endl;
        for(auto it = start; it != finish; ++it)
          print(*it);
    */

    // auto gra_keys = scores.equal_range("Graham");     // find elements with key "Graham"
    // auto start = gra_keys.first;
    // auto finish = gra_keys.second;

    // // call find_if() with a lambda expression to search for an element with value 66
    // auto result = find_if(start, finish,
    //                       [](pair<string, int> p) { return p.second == 66; });
    // if (result != finish)
    //     cout << "found an element with key Graham and value 66!" << endl;

    vector<pair<string, int>> results;     // vector to store search results

    auto gra_keys = scores.equal_range("Graham");     // find elements with key "Graham"
    // auto start = gra_keys.first;
    // auto finish = gra_keys.second;

    // auto res = find_if(start, finish, [](pair<string, int> p) { return p.second == 66; });

    // while (res != finish) {          // did we find it?
    //     results.push_back(*res);     // add it to vector

    //     ++res;     // move to next element and start another search
    //     res = find_if(res, finish, [](pair<string, int> p) { return p.second == 66; });
    // }

    copy_if(gra_keys.first, gra_keys.second, back_inserter(results),
            [](pair<string, int> p) { return p.second == 66; });

    for (auto result : results)
        print(result);
    cout << endl;

    return 0;
}
}     // namespace searchingMultimaps
#endif     // SEARCHING_MULTIMAPS_H