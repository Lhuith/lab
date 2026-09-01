#ifndef MAP_INSERT_H
#define MAP_INSERT_H

#include <iostream>
#include <map>
#include <string>

using namespace std;

namespace mapInsert {
int main() {
    map<string, int> scores;
    scores.insert(make_pair("Maybelline", 86));     // create an empty std::map
    scores.insert({"Graham", 78});

    cout << "map elements: " << endl;
    for (auto it : scores)     // use a range-for loop
        cout << it.first << " has score of " << it.second << endl;

    // inert or assign an element with key "Graham" and value 66
    auto res = scores.insert(make_pair("Graham"s, 66));

    auto iter = res.first;
    if (res.second) {
        cout << "inserted a new element with name " << iter->first;
        cout << " and score " << iter->second << endl;
    } else {
        cout << "modifying existing element with name " << iter->first;
        iter->second = 66;
        cout << " to have score " << iter->second << endl;
    }

    return 0;
}
}     // namespace mapInsert
#endif     // MAP_INSERT_H