#ifndef FORWARD_APP_H
#define FORWARD_APP_H

#include <fplus/fplus.hpp>
#include <iostream>

namespace forwardApp {

const auto str_to_int = fplus::read_value_unsafe<int>;

int main() {
    using namespace fplus;
    const std::string input = "1,5,4,7,2,2,3";

    // const auto parts = split(',', false, input);
    // const auto nums = transform(str_to_int, parts);
    const auto result =
        fwd::apply(input,
                   fwd::split(',', false),
                   fwd::transform(str_to_int),
                   fwd::product());

    // fwd::apply :
    // (a, (a -> b), (b -> c), (c -> d)) -> d

    // product : [a] -> a
    // fwd::product [a] -> a

    std::cout << result << std::endl;

    return 0;
}
}     // namespace forwardApp
#endif     // FORWARD_APP_H