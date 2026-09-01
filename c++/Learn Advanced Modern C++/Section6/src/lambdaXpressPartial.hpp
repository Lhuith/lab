#ifndef LAMBDA_XPRESS_PARTIAL_H
#define LAMBDA_XPRESS_PARTIAL_H

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace lambdaXpressPartial {

// function which returns a lambda function
auto greeter(const string& salutation) {
    return [salutation](const string& name) { return salutation + ", "s + name; };     // lambda function
}

int main() {
    // vector<string> words{"a", "collection", "of", "words", "with", "varying", "lengths"};
    // int max{5};

    // // save the lambda expression in a variable
    // auto is_longer_than = [max](const string& str) { return str.size() > (size_t)max; };

    // // pass this variable as the predicate
    // auto res = find_if(cbegin(words), cend(words), is_longer_than);

    // // display it
    // if (res != cend(words)) {
    //     cout << R"(the first word which is more than )";
    //     cout << *res << R"(")" << endl;
    // }

    // store the lambda function in a variable
    auto greet = greeter("Hello"s);

    // call the lambda function
    cout << "Greeting: " << greet("students"s) << endl;
    cout << "Greeting: " << greet("James"s) << endl;

    auto greet_formal = greeter("Good morning"s);

    // call the lambda function
    cout << "formal greeting: " << greet_formal("Dr Stroustrup"s) << endl;

    return 0;
}
}     // namespace lambdaXpressPartial
#endif     // LAMBDA_XPRESS_PARTIAL_H