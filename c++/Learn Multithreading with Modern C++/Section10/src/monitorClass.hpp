#ifndef MONITOR_CLASS_H
#define MONITOR_CLASS_H

#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

namespace monitorClass {

using namespace std::literals;

#define LOCK(m) std::lock_guard<std::mutex> lck(m)

// very simple "Bank" class
class Bank {
    // shared data
    // ...

   public:
    void debit(const std::string& name, int amount) {
        std::cout << "debiting " << amount << " from " << name << '\n';
    }
    void credit(const std::string& name, int amount) {
        std::cout << "crediting " << amount << " to " << name << '\n';
    }
    void print(const std::string& name) {
        std::cout << "displaying account for " << name << '\n';
    }
};

class BankMonitor {
    std::mutex mut;
    Bank bank;

   public:
    void debit(const std::string& name, int amount) {
        // lock the mutex and forward the call
        LOCK(mut);
        bank.debit(name, amount);
    }
    void credit(const std::string& name, int amount) {
        // lock the mutex and forward the call
        LOCK(mut);
        bank.credit(name, amount);
    }
    void print(const std::string& name) {
        // lock the mutex and forward the call
        LOCK(mut);
        bank.print(name);
    }
};

int main() {
    // transfer $1000 from Peter to Paul
    BankMonitor bank_mon;

    // call its member functions
    // each member function locks separately
    std::thread thr([&bank_mon] {
        bank_mon.debit("Peter", 1000);
        bank_mon.credit("Paul", 1000);
        bank_mon.print("Peter");
        bank_mon.print("Paul");
    });

    thr.join();
    std::cout << "done\n";
    return 0;
}
}     // namespace monitorClass
#endif     // MONITOR_CLASS_H