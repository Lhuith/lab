#ifndef FUTURE_PROMISE_H
#define FUTURE_PROMISE_H

#include <chrono>
#include <future>
#include <iostream>
#include <thread>

using namespace std;

namespace futurePromise {

// mutex to protect ouput
std::mutex mut;

// the producer's task function takes a std::promise as argument
void produce(std::promise<int>& px) {
    // try {
    using namespace std::literals;

    // produce the result
    int x = 42;
    std::this_thread::sleep_for(2s);

    // // code that may throw
    // if (1) {
    //     px.set_exception(std::make_exception_ptr(std::out_of_range("oops")));
    //     return;
    // }

    // store the result in the shared state
    std::cout << "promise sets shared state to " << x << '\n';
    px.set_value(x);

    // } catch (...) {
    //     // exception thrown - store it in the shared state
    //     px.set_exception(std::current_exception());
    // }
}

// the consumer's task function takes an std::future as argument
void consume(std::shared_future<int>& fx) {
    // get the result from the shared state
    std::cout << "thread " << std::this_thread::get_id() << " calling get()...\n";
    // try {
    int x = fx.get();
    std::lock_guard<std::mutex> lck_guard(mut);
    std::cout << "thread " << std::this_thread::get_id() << " returns from calling get()\n";
    std::cout << "thread " << std::this_thread::get_id() << " has answer is " << x << '\n';

    //     } catch (std::exception& e) {
    //         // exception thrown - get it from the shared data
    //         std::cout << "exception caught: " << e.what() << '\n';
    //     }
}

int main() {
    // create an std::promise object
    // this creates an associated std::future object
    // and sets up a shared state between them
    std::promise<int> prom;

    // // get the future associated with the promise
    // std::future<int> fut = prom.get_future();

    // get an std::shared_future associated with the promise
    // this will move the promise's future into a shared future
    std::shared_future<int> shared_fut1 = prom.get_future();

    // copy the shared future object
    std::shared_future<int> shared_fut2 = shared_fut1;

    // start the threads
    // the producer task function takes the promise as argument
    std::thread thr_producer(produce, std::ref(prom));

    // start two consumer threads
    // the consumer task function takes a shared future as argument
    // each thread uses a different shared future object
    std::thread thr_consumer(consume, std::ref(shared_fut1));
    std::thread thr_consumer2(consume, std::ref(shared_fut2));

    thr_consumer.join();
    thr_consumer2.join();
    thr_producer.join();

    return 0;
}
}     // namespace futurePromise
#endif     // FUTURE_PROMISE_H