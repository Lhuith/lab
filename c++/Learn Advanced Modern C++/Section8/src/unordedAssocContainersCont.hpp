#ifndef UNORDED_ASSOC_CONTAINERS_CONT_H
#define UNORDED_ASSOC_CONTAINERS_CONT_H

#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

namespace unordedAssocContainersCont {
int main() {
    unordered_multimap<string, int> unsorted_scores;     // create unordered_multimap object

    unsorted_scores.insert({"Graham", 78});     // add some elements to it
    unsorted_scores.insert({"Grace", 66});
    unsorted_scores.insert({"Graham", 66});     // add duplicate elements
    unsorted_scores.insert({"Graham", 72});
    unsorted_scores.insert({"Hareesh", 77});
    unsorted_scores.insert({"James", 99});

    cout << "unsorted:\n";
    for (auto it : unsorted_scores)
        cout << it.first << " has a score of " << it.second << endl;

    multimap<string, int> sorted_scores;     // create ordered multimap object

    // copy into the ordered map
    // as we populate sorted scores with the elements. it will automatically sort them
    copy(begin(unsorted_scores), end(unsorted_scores), inserter(sorted_scores, end(sorted_scores)));

    cout << "sorted:\n";
    for (auto it : sorted_scores)
        cout << it.first << " has a score of " << it.second << endl;

    return 0;
}
}     // namespace unordedAssocContainersCont
#endif     // UNORDED_ASSOC_CONTAINERS_CONT_H