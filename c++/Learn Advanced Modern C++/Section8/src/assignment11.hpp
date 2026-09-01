#ifndef ASSIGNMENT11_H
#define ASSIGNMENT11_H

#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using namespace std;

namespace assignment11 {
int main() {
    vector<pair<string, int>> vec_words;
    map<string, int> map_words;

    istream_iterator<string> iis(cin);
    istream_iterator<string> eof;

    while (iis != eof) {
        string word = *iis++;
        vec_words.push_back({word, word.size()});
        map_words[word] = word.size();
    }

    cout << "vector: ";
    for (auto v : vec_words)
        cout << "\"" << v.first << "\"" << ", size: " << v.second << ", ";
    cout << endl;

    cout << "map: ";
    for (auto v : map_words)
        cout << "\"" << v.first << "\"" << ", size: " << v.second << ", ";
    cout << endl;

    return 0;
}
}     // namespace assignment11
#endif     // ASSIGNMENT11_H