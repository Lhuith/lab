#ifndef NEW_PARA_ALGOS_CONT_H
#define NEW_PARA_ALGOS_CONT_H

#include <algorithm>
#include <execution>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

namespace newParaAlgosCont {

namespace se = std::execution;

void inner_prod() {
    std::vector<int> x{1, 2, 3, 4, 5};
    std::vector<int> y{5, 6, 7, 8, 9};

    // auto result = std::inner_product(x.begin(), x.end(),     // interator range for the first vector
    //                                  y.begin(),              // start of second vector
    //                                  0);                     // initial value of sum

    auto result = std::transform_reduce(se::par,                // execution policy
                                        x.begin(), x.end(),     // iterator range for first vector
                                        y.begin(),              // start of second vector
                                        0);                     // initial value of sum

    std::cout
        << "first vector: ";
    for (auto i : x)
        std::cout << i << ", ";
    std::cout << '\n';

    std::cout << "second vector: ";
    for (auto i : y)
        std::cout << i << ", ";
    std::cout << '\n';

    std::cout << "result of inner product: " << result << '\n';
}

int main() {
    // std::vector<int> vec{1, 2, 3, 4};
    // std::vector<int> vec2{5, 6, 7, 8};
    // std::vector<int> vec3;

    // // double each element of vec and store the results in vec2
    // // std::transform(vec.begin(), vec.end(), std::back_inserter(vec2),
    // //                [](int n) { return 2 * n; });

    // // add each element in v to the corresponding element in v2 and store the result in v3
    // std::transform(vec.begin(), vec.end(), vec2.begin(), std::back_inserter(vec3),
    //                [](int n1, int n2) { return n1 + n2; });

    // // display the first input vector
    // cout << "first input vector: ";
    // for (auto i : vec)
    //     std::cout << i << ", ";
    // std::cout << '\n';

    // // display the second input vector
    // std::cout << "second input vector: ";
    // for (auto i : vec2)
    //     std::cout << i << ", ";
    // std::cout << '\n';

    // // display the output vector
    // std::cout << "ouput vector: ";
    // for (auto i : vec3)
    //     std::cout << i << ", ";
    // std::cout << '\n';

    inner_prod();

    return 0;
}
}     // namespace newParaAlgosCont
#endif     // NEW_PARA_ALGOS_CONT_H