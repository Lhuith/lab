#ifndef UNORDED_ASSOC_CONTAINERS_H
#define UNORDED_ASSOC_CONTAINERS_H

#include <algorithm>
#include <array>
#include <iostream>
#include <list>
#include <random>
#include <unordered_map>

using namespace std;

namespace unordedAssocContainers {

void _unordered_map() {
    unordered_multimap<string, int> scores;     // create unordered_map object
    scores.insert({"Graham", 78});              // add some elements it
    scores.insert({"Grace", 66});
    scores.insert({"Graham", 66});     // add duplicate elements
    scores.insert({"Graham", 72});
    scores.insert({"Hareesh", 77});

    for (auto it : scores)
        cout << it.first << " has a score of " << it.second << endl;
}

int main() {
    // mt19937 mt;
    // uniform_int_distribution<int> dist(1, 100);

    // // the has table is ana array of linked lists
    // std::array<list<int>, 10> buckets;

    // // generate 150 random numbers with values between 1 and 100
    // // if between 1 and 10, put into buckets[0]
    // // if between 11 and 22, put into buckets[1], etc
    // for (int i = 0; i < 150; ++i) {
    //     int num = dist(mt);              // get a random number
    //     int idx = (num - 1) / 10;        // "hash function" to compute the hash value
    //     buckets[idx].push_back(num);     // use the hash value as the index into the array
    // }

    // // print out the contents of the buckets
    // for (size_t i = 0; i < 10; ++i) {
    //     auto bucket = buckets[i];
    //     cout << "bucket " << i << ": ";
    //     for (auto n : bucket)
    //         cout << n << ", ";
    //     cout << endl;
    // }

    // cout << endl;

    // // find "43" in the hash map
    // int target{43};
    // int idx = (target - 1) / 10;     // compute the hash value

    // cout << "looking for " << target << " in bucket " << idx << endl;
    // auto it = find(cbegin(buckets[idx]), cend(buckets[idx]), target);

    // if (it != cend(buckets[idx]))
    //     cout << "found " << target << " in bucket " << idx << endl;
    _unordered_map();

    return 0;
}
}     // namespace unordedAssocContainers
#endif     // UNORDED_ASSOC_CONTAINERS_H