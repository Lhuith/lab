#ifndef SEARCHING_ALGOS_H
#define SEARCHING_ALGOS_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace searchingAlgos {

void search_index() {
    string str{"Hello world"};
    cout << "string to search: " << str << endl;

    string sub{"wo"};
    cout << "searching for substring: " << sub << endl;

    // returns an iterator top the first elements of "wo"
    auto pos = search(cbegin(str), cend(str), cbegin(sub), cend(sub));

    if (pos != cend(str))
        cout << "found substring " << sub << " starting at index " << distance(cbegin(str), pos) << endl;
}

void sequence_search() {
    vector<int> vec{1, 2, 2, 3, 2, 3, 3};

    // looks for a sequence of two elements with the value 3
    // returns an iterator to the start of the first seach sequence
    auto pos = search_n(cbegin(vec), cend(vec), 2, 3);

    if (pos != cend(vec))
        cout << "found two elements with value 3, starting at index " << distance(cbegin(vec), pos) << endl;
}

void adjacent_index() {
    string str{"Hello world"};
    cout << "string to search: " << endl;

    string vowels{"aeiou"};

    // returns an iterator to the first element of ??
    auto pos = adjacent_find(cbegin(str), cend(str));

    if (pos != cend(str))
        cout << "found adjacent elements with value " << *pos << " at index " << distance(cbegin(str), pos) << endl;
    else
        cout << "no match found";
}

int main() {
    // string str{"Hello world"};
    // cout << "string to search: " << str << endl;

    // string vowels{"aeiou"};

    // // returns an iterator to the first character in "vowels"
    // auto vowel = find_first_of(cbegin(str), cend(str), cbegin(vowels), cend(vowels));

    // if (vowel != cend(str))
    //     cout << "first vowel is " << *vowel << " at index " << distance(cbegin(str), vowel) << endl;

    // auto vowel2 = find_first_of(next(vowel), cend(str), cbegin(vowels), cend(vowels));

    // if (vowel2 != cend(str))
    //     cout << "second vowel is " << *vowel2 << " at index " << distance(cbegin(str), vowel2) << endl;

    // adjacent_index();
    // sequence_search();
    search_index();

    return 0;
}
}     // namespace searchingAlgos
#endif     // SEARCHING_ALGOS_H