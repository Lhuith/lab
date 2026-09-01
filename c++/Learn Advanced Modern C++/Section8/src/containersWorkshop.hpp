#ifndef CONTAINERS_WORKSHOP_H
#define CONTAINERS_WORKSHOP_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

namespace containersWorkshop {

class family {
    vector<string> children;

   public:
    family() {}
    family(const vector<string>& c) : children(c) {}
    void addChildren(const string& c) {
        children.push_back(c);
    }

    void print() {
        cout << "{";
        for (auto c : children)
            cout << c << " ";
        cout << "}";
    }
};

set<string>
fileToStringSet(const string& dir) {
    ifstream file{dir};
    set<string> words;

    if (file.is_open()) {
        istreambuf_iterator<char> iis(file);
        istreambuf_iterator<char> eof;
        string wordsRaw;

        copy_if(iis, eof, back_inserter(wordsRaw),
                [](char c) {
                    bool maybePunct = ispunct(c);
                    return !maybePunct;
                });
        // to lower
        transform(begin(wordsRaw), end(wordsRaw), begin(wordsRaw),
                  [](char c) { return tolower(c); });

        set<string> words;
        istringstream ssWordsRaw(wordsRaw);
        istream_iterator<string> issWordsRaw(ssWordsRaw);
        istream_iterator<string> eofWordsRaw;

        while (issWordsRaw != eofWordsRaw) {
            string s = *issWordsRaw++;
            words.insert(begin(words), s);
        }
        return words;
        file.close();
    }
    return words;
}

void findAndPrintUnOrd(
    const unordered_multimap<string, string>& map, const string& familyName) {
    auto gra_keys = map.equal_range(familyName);

    cout << "\t<" << familyName << ">: {";
    for (auto it = gra_keys.first; it != gra_keys.second; ++it)
        cout << it->second << " ";
    cout << "}" << endl;
}

void findAndPrint(
    const multimap<string, string>& map, const string& familyName) {
    auto gra_keys = map.equal_range(familyName);

    cout << "\t<" << familyName << ">: {";
    for (auto it = gra_keys.first; it != gra_keys.second; ++it)
        cout << it->second << " ";
    cout << "}" << endl;
}

int main() {
    // // read from text file, showing distinct words
    // set<string> o_set = fileToStringSet("../data/words.txt");
    // cout << "distinct words set: ";
    // for (auto s : o_set)
    //     cout << s << ", ";
    // cout << endl;
    // cout << "-- -- -- -- -- -- -- -- -- -- -- --" << endl;
    // cout << endl;
    // cout << "please enter some sweet words, then ^Z: \n";
    // istream_iterator<string> iis(cin);
    // istream_iterator<string> eof;

    // set<string> _set;
    // map<string, int> _map;
    // vector<std::pair<string, int> > _vec;

    // while (iis != eof) {
    //     string s = *iis++;
    //     _set.insert(begin(_set), s);

    //     std::pair p = {s, s.size()};
    //     _map.insert(begin(_map), p);
    //     _vec.insert(begin(_vec), p);
    // }

    // cout << "set: ";
    // for (auto s : _set)
    //     cout << s << ", ";
    // cout << endl;

    // cout << "map: ";
    // for (auto it : _map)
    //     cout << it.first << ", " << it.second << ", ";
    // cout << endl;

    // cout << "vec: ";
    // for (auto it : _vec)
    //     cout << it.first << ", " << it.second << ", ";
    // cout << endl;

    map<string, family> families;
    families.insert({"Martens", family({"Eugene", "Guile", "Kyra"})});
    families["Martens"].addChildren("Bobby");

    families.insert({"Simpsons", family({"lisa", "Bart", "Maggie"})});

    cout << "map:\n";
    for (auto f : families) {
        cout << "\t<" << f.first << ">: ";
        f.second.print();
        cout << endl;
    }

    cout << "multimap: " << endl;
    multimap<string, string> families_multi;
    families_multi.insert({"Martens", "Eugene"});
    families_multi.insert({"Martens", "Guile"});
    families_multi.insert({"Martens", "Kyra"});
    families_multi.insert({"Martens", "Bobby"});

    families_multi.insert({"Simpsons", "Lisa"});
    families_multi.insert({"Simpsons", "Bart"});
    families_multi.insert({"Simpsons", "Maggie"});

    findAndPrint(families_multi, "Martens");
    findAndPrint(families_multi, "Simpsons");

    cout << "unordered_multimap: " << endl;
    unordered_multimap<string, string> families_unord_multi;
    families_unord_multi.insert({"Martens", "Eugene"});
    families_unord_multi.insert({"Martens", "Guile"});
    families_unord_multi.insert({"Martens", "Kyra"});
    families_unord_multi.insert({"Martens", "Bobby"});

    families_unord_multi.insert({"Simpsons", "Lisa"});
    families_unord_multi.insert({"Simpsons", "Bart"});
    families_unord_multi.insert({"Simpsons", "Maggie"});

    findAndPrintUnOrd(families_unord_multi, "Martens");
    findAndPrintUnOrd(families_unord_multi, "Simpsons");

    return 0;
}
}     // namespace containersWorkshop
#endif     // CONTAINERS_WORKSHOP_H