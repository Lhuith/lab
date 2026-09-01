#ifndef THREAD_COORD_PRAC_H
#define THREAD_COORD_PRAC_H

#include <chrono>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

using namespace std;

namespace threadCoordPrac {

using namespace std::literals;

// shared variable for the data being fetched
std::string sdata;

// flags for thread communication
bool updated_progress = false;
bool completed = false;

// mutexes to protect the shared variables
std::mutex data_mutex;
std::mutex completed_mutex;

// data fetching thread
void fetch_data() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "fetcher thread waiting for data ... " << std::endl;
        std::this_thread::sleep_for(2s);

        // update sdata, then notify the progress bar thread
        std::lock_guard<std::mutex> data_lck(data_mutex);
        sdata += "block" + std::to_string(i + 1);
        std::cout << "sdata: " << sdata << std::endl;
        updated_progress = true;
    }     // lock_guard unlocks here

    std::cout << "fetch sdata has ended\n";

    // tell the progress bar thread to exit
    // and wake up the processing thread
    std::lock_guard<std::mutex> completed_lck(completed_mutex);
    completed = true;
}     // lock_guard unlocks here

void progress_bar() {
    size_t len = 0;

    while (true) {
        std::cout << "progress bar thread waiting for data ... " << std::endl;

        // wait until there is some new data to display
        std::unique_lock<std::mutex> data_lck(data_mutex);
        while (!updated_progress) {
            data_lck.unlock();
            std::this_thread::sleep_for(10ms);
            data_lck.lock();
        }

        // wake up and use the new value
        len = sdata.size();

        // set the flag back to false
        updated_progress = false;
        data_lck.unlock();

        std::cout << "received " << len << " bytes so far" << std::endl;

        // terminate when the download has finished
        std::lock_guard<std::mutex> completed_lck(completed_mutex);
        if (completed) {
            std::cout << "progress bar thread has ended" << std::endl;
            break;
        }
    }
}

void process_data() {
    std::cout << "processing thread waiting for data ... " << std::endl;

    // wait until the download is complete
    std::unique_lock<std::mutex> completed_lck(completed_mutex);     // acquire ?

    while (!completed) {
        completed_lck.unlock();
        std::this_thread::sleep_for(10ms);
        completed_lck.lock();
    }

    completed_lck.unlock();

    std::lock_guard<std::mutex> data_lck(data_mutex);
    std::cout << "processing sdata: " << sdata << std::endl;

    // processing the data ...
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
}     // namespace threadCoordPrac
#endif     // THREAD_COORD_PRAC_H