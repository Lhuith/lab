#ifndef ALGO_PREDICTS_H
#define ALGO_PREDICTS_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace algoPredicts {

class is_shorter {
   public:
    // overloaded () operator
    //  takes two strings as arguments
    //  returns true/false depending on relative string length
    bool operator()(const string& lhs, const string& rhs) {
        return lhs.size() < rhs.size();
    }
};

// // define a predicate function
// bool is_shorter(const string& lhs, const string& rhs) {
//     return lhs.size() < rhs.size();
// }

int main() {
    vector<string> names = {"Dilbert", "PHB", "Dogbert", "Asok", "Ted", "Alice", "Wally"};

    cout << "vector before sort()\n";
    for (auto name : names)
        cout << name << ", ";
    cout << "\n\n";

    // sort the data in alphabetical order
    sort(begin(names), end(names));

    cout << "sorted alphabetically: " << endl;
    // cout << "vector after sort()\n";
    vector<string>::iterator it;
    for (auto name : names)
        cout << name << ", ";
    cout << endl;

    // sort the data, passing the function pointer as the predicate
    sort(begin(names), end(names), is_shorter());

    cout << endl
         << "sorted by length:  " << endl;
    for (auto name : names)
        cout << name << ", ";
    cout << endl;

    return 0;
}
}     // namespace algoPredicts
#endif     // ALGO_PREDICTS_H