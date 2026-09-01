#ifndef EXTERN_TEMPLATES_H
#define EXTERN_TEMPLATES_H

// #include "externImpl.hpp"
#include "externTemplate.hpp"
// #include "manual.hpp"

using namespace std;

// define the template in one source file only
// template <typename T>
// std::ostream& print(std::ostream& os, const T& t) {
//     return os << t;
// }

// // manual instantiation of the template
// template std::ostream& print(std::ostream& os, const std::string& str);

namespace externTemplates {
int main() {
    std::string str{"Hello"};
    std::cout << "main() printing " << str << ": ";
    print(std::cout, str);
    std::cout << std::endl;
    func(str);
    std::cout << std::endl;

    // func();
    // cout << "the meaning of life is: " << meaning_of_life << endl;

    return 0;
}
}     // namespace externTemplates
#endif     // EXTERN_TEMPLATES_H