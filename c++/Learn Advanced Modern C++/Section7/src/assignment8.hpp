#ifndef ASSIGNMENT8_H
#define ASSIGNMENT8_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <random>
#include <sstream>
#include <string>

using namespace std;

namespace assignment8 {

template <typename T>
void print(const vector<T>& vec, const string& delim) {
    ostream_iterator<T> oi(cout, delim.c_str());
    copy(vec.begin(), vec.end(), oi);
    cout << endl;
}
template <typename T>
void print(const vector<T>& vec) {
    print<T>(vec, ", "s);
}

vector<string> toStringVector(const string& str) {
    vector<string> words;
    istringstream ssWordsRaw(str);
    istream_iterator<string> issWordsRaw(ssWordsRaw);
    istream_iterator<string> eofWordsRaw;
    copy(issWordsRaw, eofWordsRaw, back_inserter(words));
    return words;
}

vector<string> fileToStringVector(const string& dir) {
    ifstream file{dir};
    vector<string> words;

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

        words = toStringVector(wordsRaw);

        vector<string> words;
        istringstream ssWordsRaw(wordsRaw);
        istream_iterator<string> issWordsRaw(ssWordsRaw);
        istream_iterator<string> eofWordsRaw;
        copy(issWordsRaw, eofWordsRaw, back_inserter(words));

        file.close();
    }

    return words;
}

int main() {
    mt19937 mt;
    uniform_int_distribution<int> i_disto(0, 1000);
    vector<int> vec;

    // 1 - random number fill
    generate_n(back_inserter(vec), 10, [&]() { return i_disto(mt); });

    // 2 _ 1
    cout << "1. vec: ";
    print<int>(vec);
    auto max_val = max_element(cbegin(vec), cend(vec));

    // 3 - max value
    cout << "3. max value is: " << *max_val << endl;

    // 4 - max index
    cout << "4. max index is at: " << distance(cbegin(vec), max_val);
    cout << endl;

    // 5 - sum total
    auto sum = accumulate(cbegin(vec), cend(vec), 0);
    cout << "5. total sum is: " << sum;
    cout << endl;

    // 6 - odd number count
    auto count = count_if(cbegin(vec), cend(vec),
                          [](int n) { return n % 2 == 1; });
    cout << "6. odd numbers are: " << count << endl;

    // 7 - normalized double vector
    // assumed we want it in another vector considering other assignment ops
    vector<double> normalizedVec;
    transform(cbegin(vec), cend(vec), back_inserter(normalizedVec),
              [max_val](double n) { return n / *max_val; });

    cout << "7. normalized vector: ";
    print<double>(normalizedVec);

    // 8 - sorted copy
    vector<double> sortedCopyVec(normalizedVec.size());
    partial_sort_copy(cbegin(vec), cend(vec),
                      begin(sortedCopyVec), end(sortedCopyVec));
    cout << "sorted copy vec: ";
    print<double>(sortedCopyVec);

    auto greaterThen455Index = upper_bound(cbegin(sortedCopyVec), cend(sortedCopyVec), 455);
    cout << "8. first value greater then 455 is: " << *greaterThen455Index << endl;
    cout << "8. first value index is at: " << distance(cbegin(sortedCopyVec), greaterThen455Index) << endl;
    cout << "8. # of values(inclusive) > than 455 is: " << distance(greaterThen455Index, cend(sortedCopyVec)) << endl;

    // 9 - odd numbers copy
    vector<double> oddDoubleVec;
    copy_if(cbegin(vec), cend(vec), back_inserter(oddDoubleVec),
            [](int n) { return n % 2 == 1; });
    cout << "9. odd<doubles> : ";
    print<double>(oddDoubleVec);

    // 10 - sort vector descending
    sort(begin(vec), end(vec),
         [](int n, int m) { return m < n; });
    cout << "10. after sorting: ";
    print<int>(vec);

    // 11 - random shuffle
    // shuffle ([1] to [len(vec) -1])
    shuffle(begin(vec) + 1, end(vec) - 1, mt);

    cout << "11. after shuffling: ";
    print<int>(vec);

    // 12 no odd numbers
    auto defunct = remove_if(begin(vec), end(vec),
                             [](int n) { return n % 2 == 1; });
    vec.erase(defunct, end(vec));

    cout << "12. oddless vec: ";
    print<int>(vec);

    // 13 write to file
    // thanks Marek R
    // https://stackoverflow.com/questions/33094317/remove-trailing-comma-in-csv-file-written-for-a-vector-using-copy-and-ostream-it
    ofstream ofile{"../data/vec.txt"};
    if (ofile.is_open()) {
        auto it = vec.end();
        if (it != vec.begin()) {
            --it;     // points to last element, instead of what lies beyond
            ostream_iterator<int> oi(ofile, ",");
            copy(vec.begin(), it, oi);
            ofile << *it;
        }

        ofile.close();
    }

    ifstream istreamOfile{"../data/vec.txt"};
    string posVecString;
    if (istreamOfile.is_open()) {
        istreambuf_iterator<char> iis(istreamOfile);
        istreambuf_iterator<char> eof;
        copy(iis, eof, back_inserter(posVecString));

        cout << "13. written to file: " << posVecString << endl;

        istreamOfile.close();
    }

    // 14 read words.txt
    ifstream words1File{"../data/words.txt"};
    ifstream words2File{"../data/words2.txt"};

    if (words1File.is_open()) {
        istreambuf_iterator<char> iis(words1File);
        istreambuf_iterator<char> eof;
        string wordsRaw;

        int characterCount{0}, newLine{0};
        copy_if(iis, eof, back_inserter(wordsRaw),
                [&characterCount, &newLine](char c) {
                    bool maybePunct = ispunct(c);

                    if (c == '\n') {
                        newLine++;
                    }

                    if (!maybePunct && !isspace(c)) {
                        characterCount++;
                    }
                    return !maybePunct;
                });

        // to lower
        transform(begin(wordsRaw), end(wordsRaw), begin(wordsRaw),
                  [](char c) { return tolower(c); });

        cout << "14. words.txt raw: \n";
        cout << wordsRaw << endl;
        vector<string> words;
        words = toStringVector(wordsRaw);

        cout << "14. words vector: ";
        print<string>(words);

        sort(begin(words), end(words));
        cout << "14. words.txt (sorted, non-distinct): " << endl;
        print<string>(words, ",");

        vector<string> distinct;
        unique_copy(cbegin(words), cend(words), back_inserter(distinct));

        cout << "14. words.txt (distinct): " << endl;
        print<string>(distinct, ",");

        // 15
        cout << "15. # of words: " << words.size() << endl;
        cout << "15. # of distinct words: " << distinct.size() << endl;

        // 16
        cout << "16. # of new lines (excluding end): " << newLine << endl;

        // 17
        cout << "17. # of characters: " << characterCount << endl;

        words1File.close();
    }

    // 18 - common words
    auto words1 = fileToStringVector("../data/words.txt"s);
    cout << "18. words1: " << endl;
    print<string>(words1, " ");

    auto words2 = fileToStringVector("../data/words2.txt"s);
    cout << "18. words2: " << endl;
    print<string>(words2, " ");

    sort(begin(words1), end(words1));
    sort(begin(words2), end(words2));

    vector<string> commonWords;
    set_intersection(
        cbegin(words1), cend(words2), cbegin(words2), cend(words2), back_inserter(commonWords));

    auto uniqueIt = unique(begin(commonWords), end(commonWords));
    commonWords.erase(uniqueIt, cend(commonWords));
    cout << "18. common words are: ";
    print<string>(commonWords, " ");

    // 19 - factorial of 6
    vector<int> factor(6);
    iota(begin(factor), end(factor), 1);
    cout << "19. factorial of 6 is : " << accumulate(cbegin(factor), cend(factor), 1, multiplies<int>()) << endl;

    return 0;
}
}     // namespace assignment8
#endif     // ASSIGNMENT8_H