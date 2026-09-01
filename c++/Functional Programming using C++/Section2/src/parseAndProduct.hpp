#ifndef PARSE_AND_PRODUCT_H
#define PARSE_AND_PRODUCT_H

// "1,5,4,7,2,2,3" -> 1*5*4*7*2*2*3 ->1680

#include <fplus/fplus.hpp>
#include <iostream>

template <typename T>
T str_to(const std::string& str) {
    T result;
    std::istringstream(str) >> result;
    return result;
}

namespace parseAndProduct {
int main() {
    const std::string input = "1.1,5.111,4.2,7,2,2,3";
    // const auto parts = fplus::split(',', false, input);
    // const auto nums = fplus::transform(str_to<double>, parts);

    // // std::cout << "numbers: ";
    // // for (auto n : nums)
    // //     std::cout << n << ", ";
    // // std::cout << std::endl;

    // // reduce : (((a, a) -> a), a, [a]) -> a
    // const auto result =
    //     fplus::reduce(std::plus<double>(), 1, nums);

    const auto parse_and_product = fplus::fwd::compose(
        fplus::fwd::split(',', false),
        fplus::fwd::transform(str_to<double>),
        fplus::fwd::product());

    std::cout << parse_and_product(input) << std::endl;

    return 0;
}
}     // namespace parseAndProduct
#endif     // PARSE_AND_PRODUCT_H