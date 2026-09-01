#ifndef CXX_MAPS_H
#define CXX_MAPS_H

#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

namespace cxxMaps {

void print(const map<string, int>& scores) {
    cout << "map elements:" << endl;

    for (auto it : scores)     // use a range-for loop to display all the elements
        cout << it.first << " has a score of " << it.second << endl;
    cout << endl;
}

int main() {
    map<string, int> scores;                        // create an empty std::map
    scores.insert(make_pair("Maybelline", 86));     // add some elements to it
    scores.insert({"Graham", 78});

    print(scores);

    // cout << "adding elements with key Graham\n";
    // auto ret = scores.insert({"Graham", 66});
    // if (ret.second)
    //     cout << "added element with key Graham to map\n";
    // else {
    //     auto it = ret.first;     // iterator to existing element
    //     cout << "map already contains an element with key " << it->first;
    //     cout << " which has the value " << it->second << endl;
    // }

    // print(scores);

    // cout << "removing element with key Graham\n";
    // scores.erase("Graham");

    // print(scores);

    // auto ret2 = scores.insert({"Graham", 66});
    // if (ret.second)
    //     cout << "added element with key Graham to map\n";
    // else {
    //     auto it = ret2.first;
    //     cout << "map already contains element with key " << it->first;
    //     cout << " which has the value " << it->second << endl;
    // }
    // print(scores);

    // cout << "Graham has a score of " << scores["Graham"] << endl;     // fetches the value with key "Graham"
    // print(scores);

    // cout << "setting Graham's score to 66" << endl;
    // scores["Graham"] = 66;     // change the value of the element with key "Graham"
    // print(scores);

    // cout << "adding Grace's score to 66" << endl;
    // scores["Grace"] = 66;     // creates a new element with key "Grace"
    // print(scores);

    cout << "calling find(\"Graham\")\n";
    // auto gra = scores.find("Graham");
    auto gra = find_if(begin(scores), end(scores), [](pair<string, int> p) { return p.first == "Graham"; });

    if (gra != scores.end()) {
        cout << "found an element with key: ";
        cout << gra->first << " which has a score of " << gra->second << endl;
        // cout << "changing Graham's name to Gra\n";
        // gra.first = "Gra"s;
        cout << "changing Graham's score to 67\n";
        gra->second = 67;
        print(scores);
    } else
        cout << "the map has no element with the key Graham\n";

    cout << "calling count (\"Graham\")\n";
    // auto n = scores.count("Graham");
    auto n = count_if(begin(scores), end(scores), [](pair<string, int> p) { return p.first == "Graham"; });

    if (n == 1)
        cout
            << "the map has 1 element with key \"Graham\"";
    else
        cout << "the map has 0 elements with key \"Graham\"";
    cout << endl;

    return 0;
}

}     // namespace cxxMaps
#endif     // CXX_MAPS_H