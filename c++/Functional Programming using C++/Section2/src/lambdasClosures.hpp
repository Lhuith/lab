#ifndef LAMBDAS_CLOSURES_H
#define LAMBDAS_CLOSURES_H

#include <fplus/fplus.hpp>
#include <iostream>
#include <vector>

namespace lambdasClosures {
int main() {
    std::vector<int> xs = {0, 1, 2, 3, 4};
    const auto ys = fplus::keep_if([](int x) -> bool {
        return x % 2 == 0;
    },
                                   xs);

    // [capture list] (parameters) -> return type
    // {
    //		body
    // }

    int val = 42;
    const auto add_value = [val](auto x) {
        return x + val;
    };

    std::cout << add_value(10) << std::endl;
    val = 23;
    std::cout << add_value(10) << std::endl;

    return 0;
}
}     // namespace lambdasClosures
#endif     // LAMBDAS_CLOSURES_H