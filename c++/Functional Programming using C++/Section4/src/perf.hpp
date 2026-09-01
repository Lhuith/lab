#ifndef PERF_H
#define PERF_H

#include <algorithm>
#include <chrono>
#include <iostream>
#include <set>
#include <vector>

namespace perf {

class Timer {
   public:
    Timer() : beg_(clock::now()) {}
    void reset() { beg_ = clock::now(); }
    double elapsed() const {
        return std::chrono::duration_cast<second>(clock::now() - beg_).count();
    }

   private:
    typedef std::chrono::high_resolution_clock clock;
    typedef std::chrono::duration<double, std::ratio<1>> second;
    std::chrono::time_point<clock> beg_;
};

int main() {
    using namespace std;

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Timer stopwatch;
    for (int i = 0; i < 2000'000; ++i) {
        // O(n)
        find(begin(v), end(v), 8);
    }
    cout << "vector: " << stopwatch.elapsed() << " s" << endl;

    set<int> s = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    stopwatch.reset();
    for (int i = 0; i < 2000'000; ++i) {
        // O(log(n))
        find(begin(s), end(s), 8);
    }
    cout << "set: " << stopwatch.elapsed() << " s" << endl;

    // very sleep windows
    // sysprof linux

    // row v row faster then column by column

    // fast
    // for (int y = 0; y < height; ++y) {
    //     for (int x = 0; x < width; ++x) {
    //         // ...
    //     }
    // }

    // // slow
    // for (int x = 0; x < width; ++x) {
    //     for (int y = 0; y < height; ++y) {
    //         // ...
    //     }
    // }

    return 0;
}
}     // namespace perf
#endif     // PERF_H