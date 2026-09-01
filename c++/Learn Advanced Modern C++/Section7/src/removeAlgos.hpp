#ifndef REMOVE_ALGOS_H
#define REMOVE_ALGOS_H

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace removeAlgos {

int main() {
    vector<int> vec{3, 1, 4, 1, 5, 9};

    cout << "original vector: ";
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;
    cout << "before calling remove, the factor has " << vec.size() << " elements\n";

    auto defunct = remove(begin(vec), end(vec), 1);
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;

    cout << "before calling erase, the vector has " << vec.size() << " elements\n";
    vec.erase(defunct, end(vec));

    cout << "after calling erase, the vector has " << vec.size() << " elements\n";

    cout << "result of removal: ";
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;

    return 0;
}
}     // namespace removeAlgos
#endif     // REMOVE_ALGOS_H