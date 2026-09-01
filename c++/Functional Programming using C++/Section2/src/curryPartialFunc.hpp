#ifndef CURRY_PARTIAL_FUNC_H
#define CURRY_PARTIAL_FUNC_H

#include <fplus/fplus.hpp>
#include <iostream>
#include <string>

namespace curryPartialFunc {
int main() {
    std::vector<std::vector<int>> xss = {{0, 1, 2}, {3, 4, 5}};

    // 1
    auto res = fplus::transform(fplus::fwd::transform(fplus::square<int>), xss);

    // 2
    const auto add_four_curried = [](int a) {
        return [a](int b) {
            return [a, b](int c) {
                return [a, b, c](int d) {
                    return a + b + c + d;
                };
            };
        };
    };

    auto resCur = add_four_curried(1)(2)(3)(4);

    std::cout << fplus::show(res) << std::endl;
    std::cout << resCur << std::endl;
    return 0;
}
}     // namespace curryPartialFunc
#endif     // CURRY_PARTIAL_FUNC_H