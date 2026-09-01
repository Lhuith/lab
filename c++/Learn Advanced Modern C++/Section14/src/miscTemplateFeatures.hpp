#ifndef MISC_TEMPLATE_FEATURES_H
#define MISC_TEMPLATE_FEATURES_H

// im in 32bit compiler atm
static_assert(sizeof(int*) == 4, "this program requires a 64-bit compiler");

#include <iostream>
using namespace std;

namespace miscTemplateFeatures {

template <typename T = int>
class number {
    T value;

   public:
    number(const T& value) : value(value) {}
    void print() {
        std::cout << "value: " << value << "\n";
    }
};

template <typename T = int>
void func(const T& t1, const T& t2) {
    std::cout << "the sum of " << t1 << " and " << t2 << " is " << (t1 + t2) << "\n";
};

int main() {
    // instantiate number object with long double
    number<long double> high_precision(1.99999);

    // instantiate number object with int
    number<> default_number(1.99999);

    high_precision.print();
    default_number.print();

    cout << endl;

    long double hp1{1.99999}, hp2{3.0004};
    int normal1{2}, normal2{3};

    // instantiate function with long double
    func(hp1, hp2);

    // instantiate function with int
    func(normal1, normal2);

    return 0;
}
}     // namespace miscTemplateFeatures
#endif     // MISC_TEMPLATE_FEATURES_H