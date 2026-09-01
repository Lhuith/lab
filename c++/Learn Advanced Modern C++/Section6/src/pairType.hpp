#ifndef PAIR_TYPE_H
#define PAIR_TYPE_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace pairType {

class ge_n {
   private:
    const int n;
    int& idx;

   public:
    ge_n(const int n, int& idx) : n(n), idx(idx) {}

    bool operator()(const string& str) const {
        ++idx;
        return str.size() > (size_t)n;
    }
};

// pair<string, int> find_index(const vector<string>& vec, int max){}
pair<string, int> find_index(const vector<string>& vec, int max) {
    // int idx{-1};
    int idx = -1;

    // auto res = find_if(cbegin(vec), cend(vec),
    //                    // capture idx by reference
    //                    [max, &idx](const string& str) { ++idx;  return str.size() > (size_t)max; });

    vector<string>::const_iterator res = find_if(vec.begin(), vec.end(), ge_n(max, idx));

    if (res != cend(vec)) {
        return make_pair(*res, idx);
        // return pair{*res, idx};
    } else {
        return make_pair("", idx);
        // return pair{""s, idx};
    }
}

int main() {
    // cout << "helo from pairType\n";
    // pair<string, string> wordpair{"hello"s, "there"s};
    // auto wordpair{make_pair("hello"s, "there"s)};     // call to std::make_pair()
    // pair wordpair{"hello"s, "there"s};

    // cout << "first element of pair is \"" << wordpair.first << "\"" << endl;
    // cout << "seconds element of pair is \"" << wordpair.second << "\"" << endl;

    // vector<string> words{"a", "collection", "of", "words", "with", "varying", "lengths"};

    vector<string> words;
    words.push_back("a");
    words.push_back("collection");
    words.push_back("of");
    words.push_back("words");
    words.push_back("with");
    words.push_back("varying");
    words.push_back("lengths");

    int max = 5;

    // auto res = find_index(words, max)
    pair<string, int> res = find_index(words, max);

    if (res.first != ""s) {
        cout << R"(the first word which is more then )" << max << R"( letters long is ")";
        cout << res.first << R"(")" << endl;
        cout << "it's index is " << res.second << endl;
    }

    return 0;
}
}     // namespace pairType
#endif     // PAIR_TYPE_H