#ifndef STD_ALGO_OVERVIEW_H
#define STD_ALGO_OVERVIEW_H

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

namespace stdAlgoOverview {
int main() {
    std::string str{"HellO wOrld"};
    std::cout << "string to search: " << str << '\n';

    // search string for first occurrence of 'o'
    std::cout << "Searching for first occurrence of \'o\'\n";
    auto res = std::find_if(str.cbegin(), str.cend(),
                            [](const char c) { return ::toupper(c) == 'O'; });

    // did we find it?
    if (res != str.cend()) {
        // access the result
        std::cout << "found a matching element at index: " << res - str.cbegin() << '\n';
        std::cout << "at this point in the string: ";
        for (auto it = res; it != str.cend(); ++it)
            std::cout << *it;
        std::cout << '\n';
    } else
        std::cout << "no matching element\n";

    return 0;
}
}     // namespace stdAlgoOverview
#endif     // STD_ALGO_OVERVIEW_H