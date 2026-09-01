#ifndef CALLABLE_OBJECTS_H
#define CALLABLE_OBJECTS_H

#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace std::placeholders;

namespace callableObjects {

// non-member function
bool match(const string& test) {
    return test == "cat";
}

// functor
class functor_match {
   public:
    bool operator()(const string& test) {
        return test == "cat";
    }
};

bool bind_match(const string& animal, const string& species) {
    return animal == species;
}

int count_strings(vector<string>& texts, function<bool(const string&)> match_ptr) {
    int tally = 0;
    for (auto text : texts)
        if (match_ptr(text))
            ++tally;

    return tally;
}

int main() {
    vector<string> animals = {"cat", "dog", "tiger", "lion", "bear", "cat", "giraffe"};
    int n;

    // function pointer
    cout << "calling count_strings with function pointer\n";
    n = count_strings(animals, match);
    cout << R"(the vector contains )" << n << R"( occurrences of the word "cat")" << endl;

    // functor
    cout << "\ncalling count_strings with functor\n";
    n = count_strings(animals, functor_match());
    cout << R"(the vector contains )" << n << R"( occurrences of the word "cat")" << endl;

    // lambda expression
    cout << "\ncalling count_strings with lambda expression\n";
    n = count_strings(animals,
                      [](const string& test) { return test == "cat"; });
    cout << R"(the vector contains )" << n << R"( occurrences of the word "cat")" << endl;

    // bind() object
    cout << "\ncalling count_strings with bind() object\n";
    auto match_cat = bind(bind_match, _1, "cat");     // captures "cat" as second argument
    n = count_strings(animals, match_cat);
    cout << R"(the vector contains )" << n << R"( occurrences of the word "cat")" << endl;

    return 0;
}
}     // namespace callableObjects
#endif     // CALLABLE_OBJECTS_H