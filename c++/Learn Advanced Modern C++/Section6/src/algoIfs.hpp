#ifndef ALGO_IFS_H
#define ALGO_IFS_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace algoIfs {

class ge_n {
   private:
    const int n;

   public:
    ge_n(const int n) : n(n) {}
    // overloaded () operator
    // takes an std::string, returns true if more than 5 characters
    bool operator()(const string& s) const {
        return ((int)s.size() > n);
    }
};

// functor
// class ge_5 {
//    public:
//     // overloaded () operator
//     // takes an std::string, returns true if more than 5 characters
//     bool operator()(const string& s) const {
//         return (s.size() > 5);
//     }
// };

int main() {
    // manually coded examples
    vector<string> names = {"Dilbert", "PHB", "Dogbert", "Asok", "Ted", "Alice", "Wally"};

    // ge_5 long_enough;
    // for (auto name : names) {
    //     if (long_enough(name)) {
    //         cout << "loop: the first name with > 5 characters is \"" << name << "\"" << "\n";
    //         break;
    //     }
    // }

    // // find the first element with more than 5 characters
    // // pass the functor object as predicate
    // auto res = find_if(cbegin(names), cend(names), ge_5());

    // diplay it
    // if (res != cend(names))
    //     cout << "algorithm: first name with > 5 characters is \"" << *res << "\"" << "\n";

    // // find the first element with more than 5 characters
    // // pass the functor object as predicate
    // auto res = find_if_not(cbegin(names), cend(names), ge_5());

    // // diplay it
    // if (res != cend(names))
    //     cout << "algorithm: first name with <= 5 characters is \"" << *res << "\"" << "\n";

    // find the first element with more than 5 characters
    // pass the functor object as predicate
    auto res = find_if_not(cbegin(names), cend(names), ge_n(5));

    // diplay it
    if (res != cend(names))
        cout << "algorithm: first name with > 5 characters is \"" << *res << "\"" << "\n";

    return 0;
}
}     // namespace algoIfs
#endif     // ALGO_IFS_H