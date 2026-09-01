#ifndef CXX_SEMAPHORES_H
#define CXX_SEMAPHORES_H

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

namespace cxxSemaphores {

class Semaphore {
   private:
    std::mutex mtx;
    std::condition_variable cv;
    int counter{0};
    int max_counter{1};

   public:
    void release() {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "adding one item" << std::endl;

        if (counter < max_counter) {
            ++counter;
            count();
        }

        cv.notify_all();
    }
    void acquire() {
        std::unique_lock<std::mutex> lock(mtx);
        std::cout << "removing one item" << std::endl;

        while (counter == 0) {
            cv.wait(lock);
        }

        --counter;
        count();
    }
    void count() {
        std::cout << "value of counter: ";
        std::cout << counter << std::endl;
    }
};

int main() {
    Semaphore sem;

    auto insert = [&sem]() {
        sem.release();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    };

    auto relinquish = [&sem] {
        sem.acquire();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    };

    std::vector<std::thread> tasks;

    for (int i = 0; i < 2; ++i)
        tasks.push_back(std::thread(insert));
    for (int i = 0; i < 4; ++i)
        tasks.push_back(std::thread(relinquish));
    for (int i = 0; i < 3; ++i)
        tasks.push_back(std::thread(insert));
    for (auto& task : tasks)
        task.join();

    return 0;
}
}     // namespace cxxSemaphores
#endif     // CXX_SEMAPHORES_H