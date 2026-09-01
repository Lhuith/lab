#ifndef PIMPL_IDIOM_H
#define PIMPL_IDIOM_H

#include <iostream>

#include "date.hpp"

using namespace std;

namespace pimplIdiom {
int main() {
    // date_impl d(16, 11, 2019);
    date d(16, 11, 2019);
    d.print();
    std::cout << "\n";
    d.set_day(17);
    d.print();
    std::cout << "\n";

    return 0;
}
}     // namespace pimplIdiom
#endif     // PIMPL_IDIOM_H