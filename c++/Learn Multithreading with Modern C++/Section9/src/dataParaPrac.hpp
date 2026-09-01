#ifndef DATA_PARA_PRAC_H
#define DATA_PARA_PRAC_H

#include <algorithm>
#include <future>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

using namespace std;

namespace dataParaPrac {

static std::mt19937 mt;
std::uniform_real_distribution<double> dist(0, 100);

// compute the sum of a range of elements
double accum(double *beg, double *end) {
    return std::accumulate(beg, end, 0.0);
}

// divide the data into 4 parts
// use a separate part of the process each subset
double add_parallel(std::vector<double> &vec) {
    // find the first element of the vector
    auto vec0 = &vec[0];

    // find the number of elements
    auto vsize = vec.size();

    // start the threads
    // pass the subnet's range as argument to the task function
    auto fut1 = std::async(std::launch::async, accum, vec0, vec0 + vsize / 4);
    auto fut2 = std::async(std::launch::async, accum, vec0 + vsize / 4, vec0 + 2 * vsize / 4);
    auto fut3 = std::async(std::launch::async, accum, vec0 + 2 * vsize / 4, vec0 + 3 * vsize / 4);
    auto fut4 = std::async(std::launch::async, accum, vec0 + 3 * vsize / 4, vec0 + vsize);

    // reduce step
    // combine the results for each subset
    return fut1.get() + fut2.get() + fut3.get() + fut4.get();
}

// divide the data into 4 parts
// use a separate part of the process each subset
double add_parallel_pack(std::vector<double> &vec) {
    // type alias to simplify the code
    using task_type = double(double *, double *);

    // packaged tasks to manage each thread
    std::packaged_task<task_type> ptask1(accum);
    std::packaged_task<task_type> ptask2(accum);
    std::packaged_task<task_type> ptask3(accum);
    std::packaged_task<task_type> ptask4(accum);

    // future objects for each thead's result
    auto fut1 = ptask1.get_future();
    auto fut2 = ptask2.get_future();
    auto fut3 = ptask3.get_future();
    auto fut4 = ptask4.get_future();

    // find the first element of the vector
    auto vec0 = &vec[0];

    // find the number of elements
    auto vsize = vec.size();

    // start the threads
    // pass the subset's range as argument to the task function
    std::thread thr1(std::move(ptask1), vec0, vec0 + vsize / 4);
    std::thread thr2(std::move(ptask2), vec0 + vsize / 4, vec0 + 2 * vsize / 4);
    std::thread thr3(std::move(ptask3), vec0 + 2 * vsize / 4, vec0 + 3 * vsize / 4);
    std::thread thr4(std::move(ptask4), vec0 + 3 * vsize / 4, vec0 + vsize);

    thr1.join();
    thr2.join();
    thr3.join();
    thr4.join();

    // reduce step
    // combine the results for each subset
    return fut1.get() + fut2.get() + fut3.get() + fut4.get();
}

int main() {
    // populate a vector with elements 1, 2, ..., 16
    std::vector<double> vec(16);
    std::iota(vec.begin(), vec.end(), 1.0);

    // populate a vector with 10,000 random elements
    std::vector<double> vrand(10'000);
    std::generate(vrand.begin(), vrand.end(),
                  [&vrand]() { return dist(mt); });

    // do the calculations
    std::cout << "sum of first 16 integers: " << add_parallel_pack(vec) << '\n';
    std::cout << "sum of 10,000 random numbers: " << add_parallel_pack(vrand) << '\n';

    return 0;
}
}     // namespace dataParaPrac
#endif     // DATA_PARA_PRAC_H