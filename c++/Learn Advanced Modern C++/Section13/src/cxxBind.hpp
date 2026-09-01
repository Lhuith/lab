#ifndef CXX_BIND_H
#define CXX_BIND_H

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::placeholders;

namespace cxxBind {

bool match(const string& animal, const string& species) {
    cout << R"(argument is ")" << animal << R"(", 2nd argument is ")" << species << "\"" << endl;
    return animal == species;
}

int main() {
    vector<string> animals = {"cat", "dog", "tiger", "lion", "bear", "cat", "giraffe"};

    // cout << "the vector contains ";
    // auto n = count_if(cbegin(animals), cend(animals), match("cat"));     // error!
    // cout << R"(the vector contains )" << n << R"( occurrences of the word "cat")" << endl;

    // if (match_cat("dog"))     // calls match("dog", "cat")
    //     cout << "matched\n";
    // else
    //     cout << "not matched\n";
    string toSearch = "cat"s;
    // auto match_cat = bind(match, _1, "cat");     // captures cat as the second argument
    auto match_cat = [species = toSearch](const string& animal) { return match(animal, species); };

    cout
        << "the vector contains ";
    cout << count_if(cbegin(animals), cend(animals), match_cat);
    cout << R"( occurrences of the word ")" << toSearch << R"(")" << endl;

    return 0;
}
}     // namespace cxxBind
#endif     // CXX_BIND_H