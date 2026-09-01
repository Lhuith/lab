#ifndef ALGOS_EXECUTION_POLS_H
#define ALGOS_EXECUTION_POLS_H

#include <algorithm>
#include <exception>
#include <execution>
#include <iostream>
#include <vector>

using namespace std;

namespace algosExecutionPols {

namespace se = std::execution;
int main() {
    std::vector<int> vec{3, 1, 4, 1, 5, 9};

    try {
        // predicate throws an exception
        std::sort(se::seq, vec.begin(), vec.end(), [](int a, int b) {
            throw std::out_of_range("oops");
            return true;
        });
    } catch (std::exception& e) {
        std::cout << "caught exception: " << e.what() << '\n';
    }

    for (auto v : vec)
        std::cout << v << ", ";
    std::cout << '\n';

    return 0;
}
}     // namespace algosExecutionPols
#endif     // ALGOS_EXECUTION_POLS_H