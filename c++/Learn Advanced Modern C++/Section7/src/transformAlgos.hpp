#ifndef TRANSFORM_ALGOS_H
#define TRANSFORM_ALGOS_H

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace transformAlgos {

void print(const vector<int>& vec) {
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;
}

bool equal_strings(const string& lhs, const string& rhs) {
    // copy the arguments
    string lhs_copy{lhs};
    string rhs_copy{rhs};

    // convert to upper case
    transform(begin(lhs_copy), end(lhs_copy), begin(lhs_copy), ::toupper);
    transform(begin(rhs_copy), end(rhs_copy), begin(rhs_copy), ::toupper);

    // compare the results
    return lhs_copy == rhs_copy;
}

void test(const string& str1, const string& str2) {
    cout << str1 << " and " << str2 << " are" << (equal_strings(str1, str2) ? "" : " not") << " equal" << endl;
}

void transform_overload() {
    vector<int> vec1{3, 1, 4, 1, 5, 9};

    cout << "vec1: ";
    print(vec1);

    vector<int> vec2;
    // first, populate vec2 with elements twice those in vec1
    transform(cbegin(vec1), cend(vec1), back_inserter(vec2),
              [](int n) { return 2 * n; });

    cout << "vec2: ";
    print(vec2);

    // populate vec3 with results of adding together elements from vec1 and vec2
    // result should be 3* values in vec1
    vector<int> vec3;
    transform(cbegin(vec1), cend(vec1), cbegin(vec2), back_inserter(vec3),
              [](int n1, int n2) { return n1 + n2; });

    cout << "vec3: ";
    print(vec3);

    // equiv loop
    vector<int> vec4;
    for (size_t i = 0; i < vec1.size(); ++i)
        vec4.push_back(vec1[i] + vec2[i]);

    cout << "vec4: ";
    print(vec4);
}

void inplace_transform() {
    vector<int> vec{3, 1, 4, 1, 5, 9};

    cout << "vec: ";
    print(vec);

    // double each element in vec and use the results to populate vec2
    transform(begin(vec), end(vec), begin(vec), [](int n) { return 2 * n; });

    cout << "vec: ";
    print(vec);

    // equiv loop
    vector<int> vec2{3, 1, 4, 1, 5, 9};
    for (auto& v : vec2)
        v = 2 * v;

    cout << "vec2: ";
    print(vec2);
}

int main() {
    // vector<int> vec{3, 1, 4, 1, 5, 9};

    // cout << "vec: ";
    // print(vec);

    // vector<int> vec2;
    // // double each element in vec and use the results to populate vec2
    // transform(cbegin(vec), cend(vec), back_insert_iterator(vec2),
    //           [](int n) { return 2 * n; });

    // cout << "vec2: ";
    // print(vec2);

    // // equiv loop
    // vector<int> vec3;
    // for (auto v : vec)
    //     vec3.push_back(v * 2);

    // cout << "vec3: ";
    // print(vec3);

    // inplace_transform();
    // transform_overload();

    test("lambda", "Lambda");
    test("lambda", "lambada");

    return 0;
}
}     // namespace transformAlgos
#endif     // TRANSFORM_ALGOS_H