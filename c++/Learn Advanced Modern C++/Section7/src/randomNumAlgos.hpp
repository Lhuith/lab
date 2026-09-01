#ifndef RANDOM_NUM_ALGOS_H
#define RANDOM_NUM_ALGOS_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

using namespace std;

namespace randomNumAlgos {

void print(const vector<int>& vec) {
    ostream_iterator<int> oi(cout, ", ");
    copy(vec.begin(), vec.end(), oi);
}

void shuffle() {
    vector<int> vec{3, 1, 4, 1, 5, 9};
    static mt19937 mt;

    cout << "vector before shuffling\n";
    print(vec);
    uniform_int_distribution<int> uid(0, vec.size() - 1);

    for (size_t i = 0; i < vec.size(); ++i)
        std::swap(vec[i], vec[uid(mt)]);

    cout << "\nvector after shuffling\n";
    print(vec);
    cout << endl;
}

void bernoulli() {
    static mt19937 mt;
    static bernoulli_distribution bd;

    if (bd(mt))
        cout << "your subjects are grateful for your wise and benevolent rule\n";
    else
        cout << "the peasants are revolting!\n";
}

int main() {
    // vector<int> vec{3, 1, 4, 1, 5, 9};
    // static mt19937 mt;

    // cout << "vector before shuffling\n";
    // for (auto v : vec)
    //     cout << v << ", ";
    // cout << endl;

    // shuffle(begin(vec), end(vec), mt);

    // cout << "\nvector after shuffling\n";
    // for (auto v : vec)
    //     cout << v << ", ";
    // cout << endl;
    // bernoulli();
    shuffle();

    return 0;
}
}     // namespace randomNumAlgos
#endif     // RANDOM_NUM_ALGOS_H