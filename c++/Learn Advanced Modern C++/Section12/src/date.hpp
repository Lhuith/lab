#ifndef Date_H
#define Date_H

#include <memory>

class date_impl;

// note: interface/handler that client will instantiates
// class date {
//     date_impl* pImpl;

//    public:
//     date(int d, int m, int year);
//     ~date();

//     void set_day(int day);
//     void print();
// };

// note unique_ptr is move only! and declaring destructor means we need to declare the move functions ourselves
// since it won't synthesize them for us when destructor is declared
class date {
    std::unique_ptr<date_impl> pImpl;

   public:
    date(int d, int m, int y);
    ~date();
    date(date&&) noexcept;
    date& operator=(date&&) noexcept;
    void set_day(int d);
    void print();
};

#endif     // Date_H