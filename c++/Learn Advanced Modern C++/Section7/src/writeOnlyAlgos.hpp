#ifndef WRITE_ONLY_ALGOS_H
#define WRITE_ONLY_ALGOS_H

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace writeOnlyAlgos {

class square {
   private:
    int n{0};

   public:
    int operator()() {
        ++n;
        return n * n;
    };
};

void _generate() {
    vector<int> vec(10);                          // vector with 10 elements
    generate(begin(vec), end(vec), square());     // populate it with the first 10 squares

    /*
            square sq;
            for(auto& v: vec)
                c = sq();
    */

    for (auto v : vec)
        cout << v << ", ";
    cout << endl;
    cout << "empty array fill with back inserter\n";

    vector<int> vec2;                                  // empty vector
    generate_n(back_inserter(vec2), 10, square());     // populate it with the first 10 squares

    /*
            square sq;
            for(int i = 0; i < 10; ++i)
                vec.push_back(sq());
    */
    for (auto v : vec2)
        cout << v << ", ";
    cout << endl;
}

void fill_n() {
    // assign the first 10 elements to 42 and the rest to 99
    vector<int> vec(10);     // vector with 10 elements

    auto begin_rest = fill_n(begin(vec), 5, 42);     // assign 42 to the first 5 elements
    fill(begin_rest, end(vec), 99);                  // assign 99 to the remaining elements

    /*
            int i;
            for(i = 0; i < 5; ++i)
                vec[i] = 42;
            for(; i < 10; ++i)
                vec[i] = 99;
    */
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;

    // safe fill_n
    cout << "safe fill_n \n";
    // resize vec to have 5 elements, neat trick!
    vector<int> vec2;     // define empty vector
    if (vec2.size() < 5) {
        vector<int> new_vec(5);
        vec2.swap(new_vec);
    }
    fill_n(begin(vec2), 5, 42);     // auto begin_rest2 =
    for (auto v : vec2)
        cout << v << ", ";
    cout << endl;

    // safe fill_n take 2
    cout << "safe fill_n take 2 \n";
    vector<int> vec3;     // define empty vector

    fill_n(back_inserter(vec3), 5, 42);     // auto begin_rest =

    /*
            for(int i = 0; i < 5; ++i)
                vec.push_back(42);
    */

    for (auto v : vec3)
        cout << v << ", ";
    cout << endl;
}

int main() {
    // vector<int> vec(10);                // vector with 10 elements;
    // fill(begin(vec), end(vec), 42);     // assign 42 to all its elements

    // cout << "vector populated by fill: ";
    // for (auto v : vec)
    //     cout << v << ", ";
    // cout << endl;

    // vector<int> vec2(10);     // vector with 10 elements
    // for (auto& v : vec2)
    //     v = 42;

    // cout << "vector populated by loop: ";
    // for (auto v : vec2)
    //     cout << v << ", ";

    // cout << endl;
    // fill_n();
    _generate();

    return 0;
}
}     // namespace writeOnlyAlgos
#endif     // WRITE_ONLY_ALGOS_H