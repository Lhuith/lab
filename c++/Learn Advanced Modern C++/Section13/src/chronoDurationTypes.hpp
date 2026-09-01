#ifndef CHRONO_DURATION_TYPES_H
#define CHRONO_DURATION_TYPES_H

#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;
using namespace std::literals;     // for suffixes

namespace chronoDurationTypes {

void chronoMath() {
    seconds sec;
    auto s1 = 2s;
    auto s2 = 3s;
    cout << "s1 = " << s1.count() << " seconds " << endl;
    cout << "s2 = " << s2.count() << " seconds " << endl;

    sec = s1 + s2;     // s == 5 seconds
    cout << "sec = " << sec.count() << " seconds" << endl;

    auto msec = sec + 43ms;     // ms = 5043 milliseconds
    cout << "msec = " << msec.count() << " milliseconds" << endl;
}

void func(seconds sec) {     // function taking chrono::seconds argument
    cout << sec.count() << " seconds\n";
}

void chronoFuncy() {
    // seconds sec = 2;		// error - connect convert from int
    seconds sec = 2s;     // ok

    // func(2);     // error cannot convert from int
    func(2s);
}

void chronoCast() {
    seconds sec1 = 1h;     // ok, s == 3600 seconds
    cout << "sec1 = " << sec1.count() << " seconds" << endl;

    // seconds sec2 = 5043ms;     // error - data would be lost

    seconds s = duration_cast<seconds>(5043ms);     // ok - s is truncated to 5 seconds
    cout << "5043ms converted to " << s.count() << " seconds\n";

    seconds s2 = duration_cast<seconds>(-5043ms);     // ok - s2 is truncated to -5 seconds, towards 0
    cout << "-5043ms converted to " << s2.count() << " seconds\n";
}

int main() {
    // seconds s;     // undefined value
    // // cout << "uninitialized seconds variable has value " << s << endl;
    // cout << "uninitialized seconds variable has value " << s.count() << endl;

    // auto hour = 5h;        // 5 hour interval
    // auto mins = 10min;     // 10 minute interval
    // auto sec = 2s;         // 2 second interval
    // auto msec = 20ms;      // 20 milliseconds
    // auto usec = 50us;      // 50 microseconds
    // auto nsec = 80ns;      // 80 nanoseconds;

    // cout << "hour = " << hour.count() << " hours " << endl;
    // cout << "mins = " << mins.count() << " minutes " << endl;
    // cout << "sec = " << sec.count() << " seconds " << endl;
    // cout << "msec = " << msec.count() << " milliseconds " << endl;
    // cout << "usec = " << usec.count() << " microseconds " << endl;
    // cout << "nsec = " << nsec.count() << " nanoseconds " << endl;

    // chronoMath();
    // chronoFuncy();
    chronoCast();

    return 0;
}
}     // namespace chronoDurationTypes
#endif     // CHRONO_DURATION_TYPES_H