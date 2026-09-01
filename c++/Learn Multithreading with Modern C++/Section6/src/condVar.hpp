#ifndef COND_VAR_H
#define COND_VAR_H

// the reader thread waits for a notification
// the writer thread modifies the shared variable "sdata"
// the writer thread sends a notification
// the reader thread receives the notification and resumes
// the reader thread uses the new value of the shared data
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <string>
#include <thread>

using namespace std;

namespace condVar {

using namespace std::literals;

// the shared data
std::string sdata;

// mutex to protect critical sections
std::mutex mut;

// the condition variable
std::condition_variable cond_var;

// flag for predicate
bool condition = false;

// waiting thread
void reader() {
    // lock the mutex
    std::cout << "reader thread locking mutex\n";
    std::unique_lock<std::mutex> uniq_lck(mut);
    std::cout << "reader thread has locked the mutex\n";

    // call wait()
    // this will unlock the mutex and make this thread
    // sleep until the condition variable wakes us up
    std::cout << "reader thread sleeping...\n";

    // while (isModding) {
    //     uniq_lck.unlock();
    //     std::cout << "reader is tapping his foot...\n";
    //     std::this_thread::sleep_for(10ms);
    //     uniq_lck.lock();
    // }
    cond_var.wait(uniq_lck, []() { return condition; });

    // the condition variable has woken this thread up
    // and locked the mutex
    // std::cout << "reader thread wakes up\n";
    std::cout << "reader thread " << std::this_thread::get_id() << " wakes up\n";

    // display the new value of the string
    std::cout << "data is \"" << sdata << "\"\n";
    std::cout << "reader thread unlocks the mutex\n";
}

// notifying thread
void writer() {
    {
        // lock the mutex
        std::cout << "writer thread locking mutex\n";

        // lock the mutex
        // this will be explicitly unlocked
        // std::lock_guard is sufficient
        std::lock_guard<std::mutex> lck_guard(mut);
        std::cout << "writer thread has locked the mutex\n";

        // pretend to be busy...
        std::this_thread::sleep_for(2s);

        // modify the string
        std::cout << "Writer thread modifying data...\n";
        sdata = "populated";

        // set the flag
        condition = true;

        std::cout << "writer thread unlocks the mutex\n";
    }

    // notify the condition variable
    std::cout << "writer thread sends notification\n";

    // cond_var.notify_one();
    // cond_var.notify_all();
    for (int i = 0; i < 2; ++i)
        cond_var.notify_one();

    // isModding = false;
}

int main() {
    // initialize the shared string
    sdata = "empty";

    // display the initial value
    std::cout << "data is \"" << sdata << "\"\n";

    // // start the threads
    // std::thread read(reader);
    // std::thread write(writer);

    // write.join();
    // read.join();

    // // start the threads
    // // if the writer thread finishes before the reader thread starts, the notification is lost
    // std::thread write(writer);
    // std::this_thread::sleep_for(500ms);
    // std::thread read(reader);

    // write.join();
    // read.join();

    // the notification is not lost,
    // even if the writer thread finishes before the reader thread starts
    // or there is a "spurious wakeup" (wait returns without a notification)

    std::thread write(writer);
    std::thread read1(reader);
    std::this_thread::sleep_for(10ms);
    std::thread read2(reader);
    std::this_thread::sleep_for(10ms);
    std::thread read3(reader);
    std::this_thread::sleep_for(10ms);

    write.join();
    read1.join();
    read2.join();
    read3.join();

    return 0;
}
}     // namespace condVar
#endif     // COND_VAR_H