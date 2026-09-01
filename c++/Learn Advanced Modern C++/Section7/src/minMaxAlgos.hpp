#ifndef MIN_MAX_ALGOS_H
#define MIN_MAX_ALGOS_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace minMaxAlgos {

int main() {
    string word1{"first_word"}, word2{"word2"};

    // min() and max() with arguments
    // the return value is the largest/smallest element
    auto max_args = max(word1, word2);
    auto min_args = min(word1, word2);

    cout << "max with arguments returned \"" << max_args << "\"" << endl;
    cout << "min with arguments returned \"" << min_args << "\"" << endl;

    // min() and max() with arguments and a predict
    auto max_pred = max(word1, word2,
                        [](const string& lhs, const string& rhs) { return lhs.size() < rhs.size(); });
    auto min_pred = min(word1, word2,
                        [](const string& lhs, const string& rhs) { return lhs.size() < rhs.size(); });

    cout << "max with predicate returned \"" << max_pred << "\"" << endl;
    cout << "min with predicate returned \"" << min_pred << "\"" << endl;

    // min() and max() with initializer list
    auto max_init = max({"collection", "of", "words"});
    auto min_init = min({"collection", "of", "words"});

    cout << "max with initializer list returned \"" << max_init << "\"" << endl;
    cout << "min with initializer list returned \"" << min_init << "\"" << endl;

    // minmax() takes arguments or an initializer list and returns an std::pair of values
    auto mm = minmax({"collection", "of", "words"});
    cout << "minmax returned an std::pair{\"" << mm.first << "\", \"" << mm.second << "\"}" << endl;

    // min_element() and max_element() take an iterator range and return iterator
    vector<string> words{"a", "collection", "of", "words", "with", "varying", "lengths"};

    auto max_words = max_element(cbegin(words), cend(words));
    cout << "max_element returned \"" << *max_words << "\"" << endl;

    auto min_words = min_element(cbegin(words), cend(words),
                                 [](const string& lhs, const string& rhs) { return lhs.size() < rhs.size(); });
    cout << "min_element returned \"" << *min_words << "\"" << endl;

    // minmax_element() takes an iterator range and returns  an std::pair of iterators
    auto mm_el = minmax_element(cbegin(words), cend(words));
    auto m1 = mm_el.first;      // get an iterator to the smallest element
    auto m2 = mm_el.second;     // get an iterator to the largest element
    cout << "minmax_element returned an std::pair{\"" << *m1 << "\", \"";
    cout << *m2 << "\"}" << endl;

    return 0;
}
}     // namespace minMaxAlgos
#endif     // MIN_MAX_ALGOS_H