#ifndef NEW_PARA_ALGOS_H
#define NEW_PARA_ALGOS_H

#include <execution>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

namespace newParaAlgos {

namespace se = std::execution;

void part_sum() {
    std::vector<int> vec{1, 2, 3, 4};
    std::vector<int> res(vec.size());

    // the elements of res will be {1, 1 + 2, 1 + 2 + 3, 1 + 2 + 3 + 4};
    // res will contain{1, 3, 6, 10};
    // std::partial_sum(vec.begin(), vec.end(), res.begin());
    // std::inclusive_scan(se::par, vec.begin(), vec.end(), res.begin());

    // the elements of res will be { -1, 1 + (-1), 1 + 2 + (-1), 1 + 2 + 3 + (-1)}
    // res will contain {-1, 0, 2, 5}
    std::exclusive_scan(se::par_unseq, vec.begin(), vec.end(), res.begin(), -1);

    // this is equivalent to
    std::vector<int> vec3{-1, 1, 2, 3};
    std::vector<int> vec4(vec3.size());
    std::inclusive_scan(se::par_unseq, vec3.begin(), vec3.end(), vec4.begin());

    std::cout << "vector elements: ";
    for (auto i : vec)
        std::cout << i << ", ";
    std::cout << '\n';

    std::cout << "elements of exclusive scan vector: ";
    for (auto i : res)
        std::cout << i << ", ";
    std::cout << '\n';

    std::cout << "vector3 elements: ";
    for (auto i : vec3)
        std::cout << i << ", ";
    std::cout << '\n';

    std::cout << "elements of inclusive scan: ";
    for (auto i : vec4)
        std::cout << i << ", ";
    std::cout << '\n';
}

int main() {
    // std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7};

    // std::cout << "vector elements: ";
    // for (auto i : vec)
    //     std::cout << i << ", ";
    // std::cout << '\n';

    // // sum the elements of vec, using initial value 0
    // //  performed in left-to-right order, one addition at a time
    // //  ((((0 + 1) + 2) + 3)+ ...)
    // // auto sum = std::accumulate(vec.begin(), vec.end(), 0);

    // // sum the elements of vec, using initial value 0
    // // performed as four parallel additions
    // // ((0 + 1) + (2 + 3) + (4 + 5) + (6 + 7))
    // auto sum = std::reduce(se::par, vec.begin(), vec.end(), 0);

    // std::cout << "the sum of the elements is " << sum << '\n';

    part_sum();

    return 0;
}
}     // namespace newParaAlgos
#endif     // NEW_PARA_ALGOS_H