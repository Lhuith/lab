#ifndef FUNC_COMP_H
#define FUNC_COMP_H

#include <fplus/fplus.hpp>
#include <iostream>

namespace funcComp {

const auto str_to_int = fplus::read_value_unsafe<int>;

int square_int(int x) {
    return x * x;
}

int main() {
    using namespace fplus;

    std::vector<std::string> inputs = {"2", "3", "4"};

    const auto parse_and_square =
        fwd::compose(str_to_int, square_int);

    const auto result = fwd::apply(
        inputs,
        fwd::transform(parse_and_square),
        fwd::sum());

    std::cout << result << std::endl;

    return 0;
}
}     // namespace funcComp
#endif     // FUNC_COMP_H