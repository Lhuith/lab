#ifndef FILTER_H
#define FILTER_H

#include <algorithm>
// #include <fplus/fplus.hpp>
#include <iostream>
#include <vector>

using namespace std;

// DRY = don't repeat yourself
namespace filter {

bool is_even(int x) {
    return x % 2 == 0;
}

// keep if, as in keep if <...> is True | False
template <typename F, typename T>
vector<T> keep_if(const vector<T>& xs, F f) {
    vector<T> ys;
    copy_if(begin(xs), end(xs), back_inserter(ys), f);
    return ys;
}

int main() {
    std::vector<int> xs = {0, 1, 2, 3, 4};
    auto res = keep_if(xs, is_even);

    for (auto r : res)
        cout << r << ", ";
    cout << '\n';

    std::vector<double> xs2 = {0, 1.1, 2.3, 3.1, 44};
    auto res2 = keep_if(xs2, is_even);

    for (auto r : res2)
        cout << r << ", ";
    cout << '\n';

    // const auto ys = fplus::keep_if(is_even, xs);

    // std::vector<int> ys_other;
    // for (int x : xs)
    //     if (is_even(x))
    //         ys_other.push_back(x);

    // // std::list<int> xs = {0, 1, 2, 3, 4};
    // auto it = xs.begin();
    // while (it != xs.end()) {
    //     if (!is_even(*it))
    //         it = xs.erase(it);     // bad
    //     else
    //         ++it;
    // }

    return 0;
}
}     // namespace filter
#endif     // FILTER_H