#ifndef LIB_FUNCTION_OBJS_H
#define LIB_FUNCTION_OBJS_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace libFunctionObjs {
int main() {
    // cout << "helo from libFunctionObjs\n";
    vector<string> names = {"Dilbert", "PHB", "Dogbert", "Asok", "Ted", "Alice", "Wally"};

    cout << "vector before sort()\n";
    for (auto name : names)
        cout << name << ", ";
    cout << endl
         << endl;

    sort(begin(names), end(names), greater<string>());

    cout << "vector after sort() with std::less\n";
    for (auto name : names)
        cout << name << ", ";
    cout << endl;

    return 0;
}
}     // namespace libFunctionObjs
#endif     // LIB_FUNCTION_OBJS_H