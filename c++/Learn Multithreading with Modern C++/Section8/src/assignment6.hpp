#ifndef ASSIGNMENT6_H
#define ASSIGNMENT6_H

#include <chrono>
#include <future>
#include <iostream>
#include <thread>

using namespace std;

namespace assignment6 {

void produce(std::promise<int>& px, std::pair<int, int>&& p) {
    std::this_thread::sleep_for(2s);
    px.set_value(p.first + p.second);
}

void consume(std::future<int>& fx) {
    cout << "thread consumed: " << fx.get() << '\n';
}

int main() {
    std::promise<int> result;

    // make a pair to add in producer
    // trying to be fancy with rvalue and pairs
    std::thread producer(produce, std::ref(result), std::make_pair(6, 7));

    // reference result's future
    std::future fut = result.get_future();
    std::thread consumer(consume, std::ref(fut));

    producer.join();
    consumer.join();

    return 0;
}
}     // namespace assignment6
#endif     // ASSIGNMENT6_H