#ifndef PARTITIONING_ALGOS_H
#define PARTITIONING_ALGOS_H

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace partitioningAlgos {

void print_vec(const vector<int>& vec) {
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;
}

void _partition_point() {
    vector<int> vec{3, 1, 4, 1, 5, 9, 2, 8, 6};
    auto is_odd = [](int n) { return n % 2 == 1; };

    // partition: move odd elements to the front of the vector
    partition(begin(vec), end(vec), is_odd);

    cout << "vec after partition(): ";
    print_vec(vec);

    if (is_partitioned(cbegin(vec), cend(vec), is_odd)) {
        cout << "vec is partition by is_odd\n";

        auto ppoint = partition_point(cbegin(vec), cend(vec), is_odd);

        if (ppoint != cend(vec)) {     // check that the call succeeded
            cout << "the partition point is an element with value " << *ppoint;
            cout << " which is at index " << distance(cbegin(vec), ppoint) << endl;
        }
    } else
        cout << "vec is not partitioned by is_odd\n";
}

void _is_partitioned() {
    vector<int> vec{3, 1, 4, 1, 5, 9, 2, 8, 6};
    auto is_odd = [](int n) { return n % 2 == 1; };

    cout << "vec: ";
    print_vec(vec);

    // are all the odd elements at the front of the vector?
    if (is_partitioned(cbegin(vec), cend(vec), is_odd))
        cout << "vec is partitioned by oddness\n";
    else
        cout << "vec is not partitioned by oddness\n";

    // partition: move odd elements to the front of the vector
    partition(begin(vec), end(vec), is_odd);

    cout << "vec after partition(): ";
    print_vec(vec);

    // are all the odd elements at the front of the vector?
    if (is_partitioned(cbegin(vec), cend(vec), is_odd))
        cout << "vec is partitioned by oddness\n";
    else
        cout << "vec is not partitioned by oddness\n";
}

int main() {
    // vector<int> vec{3, 1, 4, 1, 5, 9, 2, 8, 6};

    // cout << "vec: ";
    // print_vec(vec);

    // // partition by oddness: move all odd elements to the front
    // // partition(begin(vec), end(vec), [](int n) { return n % 2 == 1; });
    // stable_partition(begin(vec), end(vec), [](int n) { return n % 2 == 1; });

    // // cout << "vec after partition(): ";
    // cout << "vec after stable_partition(): ";
    // print_vec(vec);
    // _is_partitioned();
    _partition_point();

    return 0;
}
}     // namespace partitioningAlgos
#endif     // PARTITIONING_ALGOS_H