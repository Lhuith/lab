#ifndef OVERVIEW_PART_FIVE_H
#define OVERVIEW_PART_FIVE_H

#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <vector>

using namespace std;

namespace overviewPartFive {

std::mt19937 mt;

// data structure representing a point on the screen
struct Point {
    int x;
    int y;
};

void uniquePtr() {
    // create a unique_ptr to an Pont object which has the initial values {3,6};
    auto uniq_ptr = std::make_unique<Point>(Point{3, 6});

    // std::unique_ptr<Point> uniq_ptr(new Point{3,6});	// c++11

    std::cout << uniq_ptr->x << ", " << uniq_ptr->y << '\n';
}

void _random() {
    // we want ints in the range 0 to 100
    std::cout << "5 random integers between 0 and 100:\n";
    std::uniform_int_distribution<int> uid(0, 100);

    // get 5 random numbers
    for (int i = 0; i < 5; ++i) {
        // invoking the distribution returns the next number in the sequence
        std::cout << uid(mt) << ", ";
    }

    std::cout << "\n\n";

    // we want doubles in the range 0 to 1
    std::cout << "5 random floating-point numbers between 0 and 1:\n";
    std::uniform_real_distribution<double> did(0, 1);

    // get 5 random numbers
    for (int i = 0; i < 5; ++i) {
        // invoking the distribution returns the next number in the sequence
        std::cout << did(mt) << ", ";
    }
    std::cout << '\n';
}

int main() {
    // // y is a local to the lambda body
    // auto add_two = [y = 2](int x) { return x + y; };

    // std::cout << "calling add_two(2) gives " << add_two(2) << '\n';
    // std::cout << "calling add_two(5) gives " << add_two(5) << '\n';

    // // z is a local variable in the containing scope of the lambda
    // int z = 1;

    // // y1 is local to the lambda body
    // // it is initialized using the local variable z
    // auto add_z_plus1 = [y = z + 1](int x) { return x + y; };

    // std::cout << "calling add_z_plus1(2) gives " << add_z_plus1(2) << '\n';
    // std::cout << "calling add_z_plus1(5) gives " << add_z_plus1(5) << '\n';

    // std::vector<std::string> strings(5);

    // std::cout << "capture by reference\n";

    // // lambda expression which captures "strings" by reference
    // [&strings]() {
    //     std::cout << "size in lambda = " << strings.size() << '\n';
    // }();

    // std::cout << "after calling lambda, size in main = " << strings.size() << '\n';
    // std::cout << "\ncapture by move\n";

    // // lambda expression which captures "strings" by move
    // // create a new variable "vec_strings" which is a local to the lambda body
    // // initialize it by move "strings" into it
    // [vec_strings = std::move(strings)]() {
    //     std::cout << "size in lambda = " << vec_strings.size() << '\n';
    // }();

    // std::cout << "after calling lambda, size in main = " << strings.size() << "\n\n";

    // _random();
    uniquePtr();

    return 0;
}
}     // namespace overviewPartFive
#endif     // OVERVIEW_PART_FIVE_H