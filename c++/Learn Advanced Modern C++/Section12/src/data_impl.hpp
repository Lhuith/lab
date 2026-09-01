#ifndef Date_impl_H
#define Date_impl_H

#include <iostream>

// note: the actual body/logic of date
class date_impl {
    int day;
    int month;
    int year;

   public:
    date_impl(int d, int m, int y) : day(d), month(m), year(y) {}
    void set_day(int d) { day = d; }
    void print() { std::cout << day << "/" << month << "/" << year; }
};

#endif     // Date_impl_H