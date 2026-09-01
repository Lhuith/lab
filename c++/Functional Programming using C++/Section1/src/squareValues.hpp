#ifndef SQUARE_VALUES_H
#define SQUARE_VALUES_H

#include <algorithm>
#include <fplus/fplus.hpp>
#include <iostream>
#include <iterator>
#include <vector>

namespace squareValues {

using namespace std;

typedef vector<int> Ints;
int square(int x) {
    return x * x;
}

Ints square_vec_goto(const Ints& xs) {
    Ints ys;
    ys.reserve(xs.size());
    auto it = begin(xs);
loopBegin:
    if (it == end(xs))
        goto loopEnd;
    ys.push_back(square(*it));
    ++it;
    goto loopBegin;
loopEnd:
    return ys;
}

Ints square_vec_while(const Ints& xs) {
    Ints ys;
    ys.reserve(xs.size());
    auto it = begin(xs);
    while (it != end(xs)) {
        ys.push_back(square(*it));
        ++it;
    }
    return ys;
}

Ints square_vec_for(const Ints& xs) {
    Ints ys;
    ys.reserve(xs.size());
    for (auto it = begin(xs); it != end(xs); ++it) {
        ys.push_back(square(*it));
    }
    return ys;
}

Ints range_based_for(const Ints& xs) {
    Ints ys;
    ys.reserve(xs.size());
    for (const int x : xs)
        ys.push_back(square(x));
    return ys;
}

Ints sqr_std_transform(const Ints& xs) {
    Ints ys;
    ys.reserve(xs.size());
    transform(begin(xs), end(xs), back_inserter(ys), square);
    return ys;
}

template <typename F, typename T>
vector<T> transform_vec(F f, const vector<T>& xs) {
    vector<T> ys;
    ys.reserve(xs.size());
    transform(begin(xs), end(xs), back_inserter(ys), f);
    return ys;
}

Ints sqr_transform_vec(const Ints& xs) {
    return transform_vec(square, xs);
}

Ints sqr_fplus_transform(const Ints& xs) {
    return fplus::transform(square, xs);
}

int main() {
    Ints xs(8192);
    for (int i = 0; i < 65536; ++i) {
        sqr_fplus_transform(xs);
    }

    return 0;
}
}     // namespace squareValues
#endif     // SQUARE_VALUES_H