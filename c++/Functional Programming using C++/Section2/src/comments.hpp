#ifndef COMMENTS_H
#define COMMENTS_H

#include <fplus/fplus.hpp>
#include <iostream>
#include <vector>

namespace comments {

int str_to_int(const std::string& str) {
    int result;
    std::istringstream(str) >> result;
    return result;
}

template <typename T>
T product(const std::vector<T>& v) {
    return fplus::reduce(std::multiplies(), 1, v);
}

template <typename T>
T sum(const std::vector<T>& v) {
    return fplus::reduce(std::plus(), 0, v);
}

int main() {
    const std::string input = "1,5,4,7,2,2,3";
    const auto parts = fplus::split(',', false, input);
    const auto nums = fplus::transform(str_to_int, parts);

    // calculate the product of all nums
    // const auto result = fplus::reduce(std::plus(), 0, nums);

    const auto prod = product<int>(nums);
    const auto s = sum<int>(nums);

    std::cout << prod << std::endl;
    std::cout << s << std::endl;

    return 0;
}
}     // namespace comments
#endif     // COMMENTS_H