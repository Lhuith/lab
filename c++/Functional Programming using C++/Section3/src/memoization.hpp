#ifndef MEMOIZATION_H
#define MEMOIZATION_H

#include <fplus/fplus.hpp>
#include <iostream>

namespace memoization {

int costly_function(int x) {
    // something complicated
    return 42 + x;
}

// memoize : (a -> b) -> (a -> b)
template <typename F>
std::function<int(int)> memoize(F f) {
    std::unordered_map<int, int> storage;
    return [f, storage](int x) mutable -> int {
        const auto it = storage.find(x);
        if (it == storage.end())
            return storage.insert(
                              std::make_pair(x, f(x)))
                .first->second;
        else
            return it->second;
    };
}

const auto c_f_memoized = memoize(costly_function);

int main() {
    using namespace std;

    cout << c_f_memoized(11) << endl;
    cout << c_f_memoized(22) << endl;
    cout << c_f_memoized(11) << endl;

    return 0;
}
}     // namespace memoization
#endif     // MEMOIZATION_H