#ifndef COPY_ALGOS_H
#define COPY_ALGOS_H

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace copyAlgos {

void print(const vector<int>& vec) {
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;
}

void copy_if() {
    vector<int> vec{3, 1, 4, 1, 5, 9};

    cout << "vec: ";
    print(vec);

    // copy odd elements from vec into vec2
    // use an insert iterator to populate empty container
    vector<int> vec2;
    copy_if(cbegin(vec), cend(vec), back_inserter(vec2),
            [](int n) { return (n % 2 == 1); });

    cout << "vec2: ";
    print(vec2);

    // equivalent loop
    vector<int> vec3;
    for (auto v : vec)
        if (v % 2 == 1)
            vec3.push_back(v);

    cout << "vec3: ";
    print(vec3);
}

void copy_n() {
    vector<int> vec{3, 1, 4, 1, 5, 9};

    cout << "vec: ";
    print(vec);

    // copy first two elements from vec into vec3
    vector<int> vec2;
    copy_n(cbegin(vec), 2, back_inserter(vec2));

    cout << "vec2: ";
    print(vec2);

    // equivalent loop
    vector<int> vec3;
    for (int i = 0; i < 2; ++i)
        vec3.push_back(vec[i]);
    cout << "vec3: ";
    print(vec3);
}

int main() {
    // vector<int> vec{3, 1, 4, 1, 5, 9};

    // cout << "vec0: ";
    // print(vec);

    // // copy elements from vec into vec2
    // vector<int> vec2(vec.size());     // target container must be big enough BABY!
    // copy(cbegin(vec), cend(vec), begin(vec2));

    // cout << "vec2: ";
    // print(vec2);

    // // use an insert iterator to populate empty container
    // vector<int> vec3;
    // copy(cbegin(vec), cend(vec), back_inserter(vec3));

    // cout << "vec3: ";
    // print(vec3);

    // // use a loop to populate vec4
    // vector<int> vec4;
    // for (auto v : vec)
    //     vec4.push_back(v);
    // cout << "vec4: ";
    // print(vec4);
    // copy_n();
    copy_if();
    return 0;
}
}     // namespace copyAlgos
#endif     // COPY_ALGOS_H