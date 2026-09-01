#ifndef UNIQ_POINTER_H
#define UNIQ_POINTER_H

#include <iostream>
#include <memory>

// #include <vector>
// #include <array>

using namespace std;

namespace uniqPointer {

// data stucture representing a point on the screen
struct point {
    int x;
    int y;
};

unique_ptr<point> point_ptr(int x, int y) {
    // point p = {x, y};     // create a point object

    // auto ptr{};     // create a local unique_ptr object
    return make_unique<point>(point{x, y});     // the allocated memory is transferred
}     // from p to the returned object
      // NB not return std::move(ptr);

void func(unique_ptr<point> upp) {
    cout << upp->x << ", " << upp->y << endl;
}

void structUnique() {
    // create a unique_ptr to an point which has initial value{3,6};
    auto p{make_unique<point>(point{3, 6})};     // create local unique_ptr object
    // unique_ptr<point> p{ new Point{3,6}};     // c++ 11

    // cout << p->x << ", " << p->y << endl;
    func(std::move(p));
    cout << (p == nullptr) << endl;

    auto upp{point_ptr(3, 6)};
    cout << upp->x << ", " << upp->y << endl;
}

int main() {
    // // in c++11 we have to provide a pointer by calling new() explicitly

    // // allocate a single int with value 42
    // unique_ptr<int> p1{new int(42)};     // p1's member points to the int on the heap

    // // allocate array of 6 ints
    // unique_ptr<int[]> p2{new int[6]};     // p2's member points to the first element of the array

    // // usually better to use std::array or std::vector
    // // std::array<int, 6> arr;
    // // std::vector<int> vec(6);

    // // c++14 has make_inique, which calls new() internally
    // auto p3{make_unique<int>(42)};
    // auto p4{make_unique<int[]>(6)};

    // unique_ptr<int> p1{new int(42)};
    // unique_ptr<int[]> p2{new int[6]};

    // auto p3{make_unique<int>(42)};
    // auto p4{make_unique<int[]>(6)};

    // cout << *p1 << endl;     // single object can be dereferenced
    // // cout << p1[0]                // error - single object cannot be indexed
    // cout << p2[0] << endl;     // array can be indexed
    // // cout << *p2 << endl;         // error - array cannot be dereferenced
    // // ++p1;                        // error - pointer arithmetic not supported
    // // ++p2;                        // error - pointer arithmetic not supported
    // // p1 = p2;                     // error - unique_ptr can only be moved
    // // unique_ptr<int> p5(p4);      // error - unique_ptr can only be moved
    // unique_ptr<int> p5(std::move(p3));     // ok
    // // unique_ptr<int> p6(std::move(p4));   // error - incompatible types
    // p1 = nullptr;     // calls delete on the pointer member and sets the pointer to nullptr

    structUnique();

    return 0;
}
}     // namespace uniqPointer
#endif     // UNIQ_POINTER_H