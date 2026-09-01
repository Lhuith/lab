#include "date.hpp"

#include "data_impl.hpp"

// implemented using RAII
date::date(int d, int m, int y) {
    // pImpl = new date_impl(d, m, y);     // allocate in constructor
    pImpl = std::make_unique<date_impl>(d, m, y);     // allocate in constructor
}

// date::~date() {
// delete pImpl;
// }
date::~date() = default;
date::date(date&&) noexcept = default;
date& date::operator=(date&&) noexcept = default;

void date::set_day(int day) {
    pImpl->set_day(day);
}

void date::print() {
    pImpl->print();
}
