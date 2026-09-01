#ifndef COND_VAR_PRAC_H
#define COND_VAR_PRAC_H

// simulation of a program which performs a download
//
// one thread fetches the data
// another thread displays a progress bar
// a third thread processes the data when the download is complete
//
// implemented using a condition variable to communicate between the threads

#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

using namespace std;

namespace condVarPrac {

using namespace std::literals;

// shared variable for the data being fetched
std::string sdata;

// bool flags for predicates
bool update_progress = false;
bool completed = false;

// mutexes to protect the shared variables
std::mutex data_mutex;
std::mutex completed_mutex;

// the condition variables
std::condition_variable data_cv;
std::condition_variable completed_cv;

// data fetching thread
void fetch_data() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "fetcher thread waiting for data..." << std::endl;
        std::this_thread::sleep_for(2s);

        // update sdata, then notify the progress bar thread
        std::unique_lock<std::mutex> uniq_lck(data_mutex);
        sdata += "block" + std::to_string(i + 1);
        std::cout << "fetched sdata: " << sdata << std::endl;
        update_progress = true;
        uniq_lck.unlock();
        data_cv.notify_all();
    }

    std::cout << "fetch sdata has ended\n";

    // tell the progress bar thread to exit
    // and wake up the processing thread
    std::lock_guard<std::mutex> lg(completed_mutex);
    completed = true;
    completed_cv.notify_all();
}

// progress bar thread
void progress_bar() {
    size_t len = 0;

    while (true) {
        std::cout << "progress bar thread waiting for data..." << std::endl;

        // wait until there is some new data to display
        std::unique_lock<std::mutex> data_lck(data_mutex);
        data_cv.wait(data_lck, [] { return update_progress; });

        // wake up and use the new value
        len = sdata.size();

        // set our flag back to false
        update_progress = false;
        data_lck.unlock();

        std::cout << "received " << len << " bytes so far" << std::endl;

        // check if the download has finished
        std::unique_lock<std::mutex> compl_lck(completed_mutex);

        // use wait_for() to avoid blocking
        // completed_cv.wait(compl_lck, [] { return completed; }); // blocks
        if (completed_cv.wait_for(compl_lck, 10ms, [] { return completed; })) {
            std::cout << "progress bar thread has ended" << std::endl;
            break;
        }
    }
}

void process_data() {
    std::this_thread::sleep_for(200ms);
    std::cout << "processing thread waiting for data ..." << std::endl;

    // wait until the download is complete
    std::unique_lock<std::mutex> compl_lck(completed_mutex);     // acquire lock

    completed_cv.wait(compl_lck, [] { return completed; });
    compl_lck.unlock();

    std::lock_guard<std::mutex> data_lck(data_mutex);
    std::cout << "processing sdata: " << sdata << std::endl;

    // processing data ...
}

int main() {
    // start the threads
    std::thread fetcher(fetch_data);
    std::thread prog(progress_bar);
    std::thread processor(process_data);

    fetcher.join();
    prog.join();
    processor.join();

    return 0;
}
}     // namespace condVarPrac
#endif     // COND_VAR_PRAC_H