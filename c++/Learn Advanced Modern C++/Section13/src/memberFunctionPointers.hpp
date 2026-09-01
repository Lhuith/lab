#ifndef MEMBER_FUNCTION_POINTERS_H
#define MEMBER_FUNCTION_POINTERS_H

#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace std::placeholders;

namespace memberFunctionPointers {

class Test {
   public:
    void func(int a, const string& b) {
        cout << "func called with arguments " << a << " and " << b << endl;
    }
};

// class with a member function which will be used with std::bind()
class matcher {
   public:
    bool match(const string& animal, const string& species) {
        return animal == species;
    }
};

int count_strings(vector<string>& texts, function<bool(const string&)> match_ptr) {
    int tally = 0;
    for (auto text : texts)
        if (match_ptr(text))
            ++tally;

    return tally;
}

int main() {
    // // define pfunc as a pointer to a member function of Test
    // void (Test::*pfunc)(int, const string&);     // we need the extra parentheses

    // // make pfunc point to the member function
    // pfunc = &Test::func;     // the '&' is not optional here

    // // c++11
    // // auto pfunc = &Test::func;

    // cout << "with Test object:\n";
    // Test test;
    // (test.*pfunc)(42, "Hello"s);

    // cout << "\nThrough pointer to Test:\n";
    // Test* ptest = &test;
    // (ptest->*pfunc)(42, "Hello"s);

    // // define pfunc as a pointer to a member function of Test
    // auto pfunc = &Test::func;

    // // generate a callable object from pds
    // auto f = mem_fn(pfunc);

    // // invoke this callable object
    // Test test;
    // f(test, 42, "Hello"s);     // pass the "this" object as the first argument

    vector<string> animals = {"cat", "dog", "tiger", "lion", "bear", "cat", "giraffe"};

    matcher m;
    // capture "cat" as the second argument to matcher::match()
    auto match_cat = bind(&matcher::match, &m, _1, "cat");

    // pass the callable object to count_strings()
    auto n = count_strings(animals, match_cat);
    cout << R"(the vector contains )" << n << R"( occurrences of the word "cat")" << endl;

    return 0;
}
}     // namespace memberFunctionPointers
#endif     // MEMBER_FUNCTION_POINTERS_H