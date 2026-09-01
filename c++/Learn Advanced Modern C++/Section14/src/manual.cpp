#include "manual.hpp"

// define the non-template function
void func(const std::string& str) {
    std::cout << "func() printing " << str << ": ";

    // call the template function
    // the compiler will not instantiate it here (it cannot see the definition)
    print(std::cout, str);
}