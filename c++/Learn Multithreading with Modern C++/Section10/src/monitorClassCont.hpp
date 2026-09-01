#ifndef MONITOR_CLASS_CONT_H
#define MONITOR_CLASS_CONT_H

#include <chrono>
#include <future>
#include <iostream>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

using namespace std;

namespace monitorClassCont {

using namespace std::literals;

// very simple "Bank" class

class Bank {
   public:
    void debit(const std::string& name, int amount) {
        std::cout << "debiting " << amount << " from " << name << '\n';
    }
    void credit(const std::string& name, int amount) {
        std::cout << "crediting " << amount << " from " << name << '\n';
    }
    void print(const std::string& name) {
        std::cout << "displaying account for " << name << '\n';
    }
};

// Monitor class
// can wrap any type
template <typename T>
class Monitor {
    // the object to be monitored
    T data;

    // mutex to protect the object
    std::mutex mut;

   public:
    // default constructor
    Monitor<T>(T data = T{}) : data(data) {}

    // function call operator
    // argument is a callable object of type func
    // which takes an argument of type T
    template <typename Func>
    auto operator()(Func func) {
        std::lock_guard<std::mutex> lck_guard(mut);
        // call the function, protected by the lock
        return func(data);
    }
};

int main() {
    // transfer $1000 from peter to paul
    // must be done as a single transcation

    // monitor wrapper for bank class
    // Monitor<Bank> mon;

    // // invoke its function call operator and
    // // pass callable object which takes a Bank argument
    // mon([](Bank bank) {
    //     // call its member functions, all under the same lock
    //     bank.debit("peter", 1000);
    //     bank.credit("paul", 1000);
    //     bank.print("peter");
    //     bank.print("paul");
    // });

    // std::cout << "done\n";

    using namespace std::literals;

    // monitor wrapper for std::string
    Monitor<std::string> str_mon("start: "s);

    // vector to sore returned futures from std::async()
    std::vector<std::future<void>> futs;

    for (int i = 0; i < 5; ++i) {
        futs.push_back(std::async([&str_mon, i] {
            // invoke its function call operator and
            // pass a callable object which takes an std::string argument
            str_mon([i](std::string& arg) {
                std::this_thread::sleep_for(10ms);

                stringstream ss;
                (ss << this_thread::get_id());

                arg += "id: " + ss.str() + ", i: " + std::to_string(i) + " | ";
            });

            // invoke the function call operator again
            str_mon([](const std::string& arg) {
                std::cout << arg << '\n';
            });
        }));
    }

    for (auto& fut : futs)
        fut.wait();

    std::cout << "done\n";

    return 0;
}
}     // namespace monitorClassCont
#endif     // MONITOR_CLASS_CONT_H