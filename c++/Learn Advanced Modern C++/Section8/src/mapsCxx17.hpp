#ifndef MAPS_CXX17_H
#define MAPS_CXX17_H

#include <iostream>
#include <map>
using namespace std;

namespace mapsCxx17 {

void print(const map<string, int>& scores) {
    cout << "map elements: " << endl;

    for (auto el : scores)     // use a range-for loop to display all the elements
        cout << el.first << " has a score of << " << el.second << endl;
    cout << endl;
}

int main() {
    // pair p(1, 3.142);     // std::pair<int, double>

    // auto [i, d] = p;     // variable i has type int, initial value 1
    // variable d has type double, initial value 3.142
    // cout << "i = " << i << ", d = " << d << endl;

    map<string, int> scores;                        // create an empty std::map
    scores.insert(make_pair("Maybelline", 86));     // add some elements to it
    scores.insert({"Graham", 78});

    // cout << "calling print()\n";
    // print(scores);

    // cout << "using structured binding\n";
    // cout << "map elements: " << endl;
    // for (auto [name, score] : scores) {     // range-for loop with structured binding
    //     cout << name << " has a score of " << score << endl;
    // }

    cout << "map elements: " << endl;
    for (auto [name, score] : scores)
        cout << name << " has a score of " << score << endl;
    cout << endl;

    // auto [iter, success] = scores.insert(make_pair("Graham"s, 66));
    // if (success) {
    //     cout << "inserted the new element\n";
    // } else {
    //     auto [name, score] = *iter;     // get the members of the element pair
    //     cout << "insert failed: ";
    //     cout << "existing element with name " << name << " and score " << score << endl;
    // }

    // cout << "map elements:" << endl;
    // for (auto [name, score] : scores)
    //     cout << name << " has score of " << score << endl;

    // auto [iter, success] = scores.insert_or_assign("Graham"s, 66);
    // auto [name, score] = *iter;     // get the members of the element pair

    // if (success) {
    //     cout << "inserted a new element with name " << name << " and score " << score << "\n";
    // } else
    //     cout << "existing element with name " << name << " now has score " << score << endl;

    // cout << endl
    //      << "map elements: " << endl;

    // for (auto [name, score] : scores)
    //     cout << name << " has a score of " << score << endl;

    if (auto [iter, success] = scores.insert_or_assign("Graham"s, 66); success) {
        cout << "inserted a new element\n";
    } else {
        auto [name, score] = *iter;     // get the members of the element pair
        cout << "existing element with name " << name << " name has score " << score << endl;
    }

    cout << endl
         << "map elements: " << endl;
    for (auto [name, score] : scores)
        cout << name << " has a score of " << score << endl;

    return 0;
}
}     // namespace mapsCxx17
#endif     // MAPS_CXX17_H