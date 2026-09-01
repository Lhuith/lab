#ifndef INTERACTING_CLI_H
#define INTERACTING_CLI_H

#include <fplus/fplus.hpp>
#include <iostream>

namespace interactingCli {

template <typename F>
void cmd_line_interact(F f) {
    std::cout << f(std::string(
                     std::istreambuf_iterator<char>(std::cin.rdbuf()),
                     std::istreambuf_iterator<char>()))
              << std::endl;
}

int main() {
    using namespace fplus;
    // const std::string input(
    //     std::istreambuf_iterator<char>(std::cin.rdbuf()),
    //     std::istreambuf_iterator<char>());

    // std::string output = fwd::apply(
    //     input,
    //     fwd::split_lines(false),
    //     fwd::sort(),
    //     fwd::join(std::string("\n")));

    // std::cout << output << std::endl;

    // 1
    // cmd_line_interact(fwd::to_upper_case());

    // 2
    cmd_line_interact(
        fwd::compose(
            fwd::split_lines(false),
            fwd::sort(),
            fwd::join(std::string("\n")))

    );

    return 0;
}
}     // namespace interactingCli
#endif     // INTERACTING_CLI_H