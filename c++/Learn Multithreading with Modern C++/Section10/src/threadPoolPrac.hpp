#ifndef THREAD_POOL_PRAC_H
#define THREAD_POOL_PRAC_H

#include <atomic>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

using namespace std;

namespace threadPoolPrac {

mutex m;

class concurrent_queue_exception : public std::runtime_error {
   public:
    concurrent_queue_exception() : std::runtime_error("queue is empty") {}
    concurrent_queue_exception(const char* s) : std::runtime_error(s) {}
};

template <class T>
class concurrent_queue {
    std::mutex m;
    std::queue<T> q;
    std::condition_variable cv;

   public:
    concurrent_queue() = default;
    void push(T value) {
        std::lock_guard<std::mutex> lg(m);
        q.push(value);
        cv.notify_one();
    }
    void pop(T& value) {
        std::unique_lock<std::mutex> lg(m);
        // if (q.empty()) {
        //     throw concurrent_queue_exception("queue is empty");
        // }
        cv.wait(lg, [this] { return !q.empty(); });
        value = q.front();
        q.pop();
    }
};

using Func = std::function<void()>;

class thread_pool {
    concurrent_queue<Func> work_queue;
    std::vector<std::thread> threads;
    void worker() {
        while (true) {
            Func task;
            work_queue.pop(task);
            task();
        }
    }

   public:
    thread_pool() {
        const unsigned thread_count = thread::hardware_concurrency();
        for (unsigned i = 0; i < thread_count; ++i)
            threads.push_back(thread{&worker, this});
    }
    ~thread_pool() {
        for (auto& t : threads) {
            t.join();
        }
    }
    void submit(Func f) {
        work_queue.push(f);
    }
};

using namespace std::literals;

void task() {
    lock_guard<mutex> lg(m);
    cout << "thread id: " << this_thread::get_id() << " started task" << endl;
    this_thread::sleep_for(100ms);
    cout << "thread id: " << this_thread::get_id() << " finished task" << endl;
}

int main() {
    cout << "creating a thread pool with " << thread::hardware_concurrency() << " threads" << endl;
    thread_pool pool;

    for (int i = 0; i < 10; ++i)
        pool.submit(task);

    this_thread::sleep_for(5s);

    return 0;
}
}     // namespace threadPoolPrac
#endif     // THREAD_POOL_PRAC_H