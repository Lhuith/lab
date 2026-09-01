#ifndef ASSIGNMENT4_H
#define ASSIGNMENT4_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace assignment4 {
struct language {
    string lang;
    string designer;
    int date;
};

int main() {
    vector<language> languages;
    ifstream ifile{"../data/language.txt"};
    if (ifile) {
        string text{""};
        while (getline(ifile, text)) {
            stringstream textStream(text);
            vector<string> words;
            string word{""};

            while (textStream >> word)
                words.push_back(word);

            if (words.size() < 3) {
                cout << "unable to create language object from data\n";
                continue;
            }

            // working on the assumption that
            // - last value will always be date
            // - first value will always be name
            // - anything between is just an assortment of names and junk
            string lang{words.front()};

            string names{""};
            for (size_t i = 1; i < words.size() - 1; ++i) {
                names += words[i];

                if (i != words.size() - 2)
                    names += " ";
            }

            int date{0};
            istringstream(words[words.size() - 1]) >> date;
            languages.push_back(language{lang, names, date});
        }
        for (const auto &lang : languages)
            cout << lang.lang << ", " << lang.designer << ", " << lang.date << endl;

        ifile.close();
    }

    return 0;
}
}     // namespace assignment4
#endif     // ASSIGNMENT4_H