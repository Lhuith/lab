#ifndef TEMPLATE_SPECIALIZATION_H
#define TEMPLATE_SPECIALIZATION_H

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

namespace templateSpecialization {

// generic Vector class
template <typename T>
class Vector {
   public:
    void identify() {
        cout << "Vector<T>\n";
    }
};

// partial specialization of Vector class for pointers
template <typename T>
class Vector<T*> {
   public:
    void identify() {
        cout << "Vector<T *>\n";
    }
};

// specialization of Vector class for bool type
template <>
class Vector<bool> {
   public:
    void identify() {
        cout << "Vector<bool>\n";
    }
};

// generic Reverse function
template <typename T>
void Reverse(T& container) {
    cout << "calling generic Reverse\n";
    std::reverse(begin(container), end(container));
}

// specialization of Reverse function for std::list
// list is itself a class template
// the element type is part of the list's type
// we need to provide a template parameter for std::lists's element
template <typename Elem>
void Reverse(std::list<Elem>& container) {
    cout << "calling specialization of Reverse of list<Elem>\n";
    container.reverse();
}

int main() {
    // Vector<int> ivec;
    // Vector<bool> bvec;

    // cout << "Vector<int> identify: ";
    // ivec.identify();
    // cout << "Vector<bool> identify: ";
    // bvec.identify();

    // vector<int> vec{3, 1, 4, 1, 5, 9};

    // cout << "vec before calling Reverse()\n";
    // for (auto v : vec)
    //     cout << v << ", ";
    // cout << '\n';

    // Reverse(vec);     // call generic reverse

    // cout << "vec after calling Reverse()\n";
    // for (auto v : vec)
    //     cout << v << ", ";
    // cout << '\n';

    // list<int> lis{3, 1, 4, 1, 5, 9};

    // cout << "\nlis before calling Reverse()\n";
    // for (auto l : lis)
    //     cout << l << ", ";
    // cout << "\n";

    // Reverse(lis);     // call specialized Reverse

    // cout << "lis after calling Reverse()\n";
    // for (auto l : lis)
    //     cout << l << ", ";
    // cout << "\n";

    Vector<int> vec;
    Vector<int*> ptr_vec;

    cout << "vec<int> identify: ";
    vec.identify();
    cout << "vec<int *> identify: ";
    ptr_vec.identify();

    return 0;
}
}     // namespace templateSpecialization
#endif     // TEMPLATE_SPECIALIZATION_H