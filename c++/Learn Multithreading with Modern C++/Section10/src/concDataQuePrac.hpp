#ifndef CONC_DATA_QUE_PRAC_H
#define CONC_DATA_QUE_PRAC_H

#include <future>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

using namespace std;

namespace concDataQuePrac {

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

concurrent_queue<string> cq;

// waiting thread
void reader() {
    string sdata;
    try {
        cout << "reader calling pop..." << endl;
        cq.pop(sdata);     // pop the data off the queue
        cout << "reader received data: " << sdata << endl;
    } catch (exception& e) {
        cout << "exception caught: " << e.what() << endl;
    }
}

// modifying thread
void writer() {
    std::this_thread::sleep_for(5s);
    cout << "writer calling push ..." << endl;
    cq.push("populated");     // push the data onto the queue
    cout << "writer returned from push..." << endl;
}

int main() {
    auto w = async(std::launch::async, writer);
    auto r = async(std::launch::async, reader);
    r.wait();
    w.wait();

    return 0;
}
}     // namespace concDataQuePrac
#endif     // CONC_DATA_QUE_PRAC_H