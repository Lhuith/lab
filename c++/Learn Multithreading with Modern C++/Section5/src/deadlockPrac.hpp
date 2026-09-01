#ifndef DEADLOCK_PRAC_H
#define DEADLOCK_PRAC_H

#include <chrono>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

using namespace std;

namespace deadlockPrac {
// dining philosophers problem (part 1)

// 5 philosophers set at a round table which has 5 forks on it.
// a philosopher has a fork each side of them.
// a philosopher can only eat if they can pick up both forks.
// if a philosopher picks up the fork on their right,
// that prevents the next philosopher from picking up their left fork.

// all the philosophers pick up their left fork at the same time
// they wait to pick up their right fork (which is also their neighbours left fork)
// their neighbour is waiting to pick up their own right fork
// all the philosophers are waiting for their neighbour

// the philosophers are blocked indefinitely
// deadlock

using namespace std::literals;

// some data about the problem
constexpr int nforks = 5;
constexpr int nphilosophers = nforks;
std::string names[nphilosophers] = {"A", "B", "C", "D", "E"};

// keep track of how many times a philosopher is able to eat
int mouthfuls[nphilosophers] = {0};

// a philosopher who has not picked up both forks is thinking
constexpr auto think_time = 2s;

// a philosopher who has picked up both forks is eating
constexpr auto eat_time = 1s;

// a mutex prevents more than one philosopher picking up the same fork
// a philosopher thread can only pick up a fork if it can lock the corresponding mutex
std::mutex fork_mutex[nforks];

// mutex to protect output
std::mutex print_mutex;

// functions to display information about the 'nth' philosopher

// interactions with a forks
void print(int n, const std::string& str, int lfork, int rfork) {
    std::lock_guard<std::mutex> print_lock(print_mutex);
    std::cout << "philosopher " << names[n] << str;
    std::cout << lfork << " and " << rfork << '\n';
}

// // interactions with a fork
void print(int n, const std::string& str, int forkno) {
    std::lock_guard<std::mutex> print_lock(print_mutex);
    std::cout << "philosopher " << names[n] << str << forkno << '\n';
}

void print(int n, const std::string& str) {
    std::lock_guard<std::mutex> print_lock(print_mutex);
    std::cout << "philosopher " << names[n] << str << '\n';
}

// thread which represents a dining philosopher
void dine(int phil_no) {
    // philosopher A has fork 0 on their left
    // and for 1 on their right
    // philosopher B has fork 1 on their left
    // and fork 2 on their right
    // ...
    // philosopher E has fork 4 on their left
    // and fork 0 on their right
    //
    // each philosopher must pick up their left fork first
    int lfork = phil_no;
    int rfork = (phil_no + 1) % nforks;

    if (lfork > rfork) {
        std::swap(lfork, rfork);
    }

    print(phil_no, "\'s left fork is number ", lfork);
    print(phil_no, "\'s right for is number ", rfork);
    // print(phil_no, "\'s forks are ", lfork, rfork);
    print(phil_no, " is thinking...");

    std::this_thread::sleep_for(think_time);

    // make attempt to eat
    print(phil_no, " reaches for for number ", lfork);
    // print(phil_no, " reaches for forks ", lfork, rfork);

    // try to pick up the left fork
    // fork_mutex[lfork].lock();
    // // try to pick up both forks
    // // std::lock(fork_mutex[lfork], fork_mutex[rfork]);
    // // print(phil_no, " picks up fork ", lfork, rfork);

    // print(phil_no, " is thinking...");

    // // succeeded - now trying to pick up the right fork
    // std::this_thread::sleep_for(think_time);

    // print(phil_no, " reaches for fork number ", rfork);

    // fork_mutex[rfork].lock();

    // // succeeded - this philosopher can now eat
    // print(phil_no, " picks up fork ", rfork);

    // try to pick up left fork
    bool locked = false;

    while (!locked) {
        fork_mutex[lfork].lock();
        print(phil_no, " picks up fork ", lfork);
        print(phil_no, " is thinking...");

        // succeeded - now try to pick up the right fork
        std::this_thread::sleep_for(think_time);
        print(phil_no, " reaches for fork number ", rfork);

        locked = fork_mutex[rfork].try_lock();

        if (!locked) {
            print(phil_no, " puts down fork ", lfork);
            std::this_thread::sleep_for(think_time);
            fork_mutex[lfork].unlock();
        }
    }

    print(phil_no, " is eating...");
    ++mouthfuls[phil_no];
    std::this_thread::sleep_for(eat_time);

    print(phil_no, " puts down fork ", lfork);
    print(phil_no, " puts down fork ", rfork);
    print(phil_no, " is thinking...");

    fork_mutex[lfork].unlock();
    fork_mutex[rfork].unlock();
    std::this_thread::sleep_for(think_time);

    // succeeded - this philosopher can now eat
    // print(phil_no, " is eating...");

    // std::this_thread::sleep_for(eat_time);

    // print(phil_no, " puts down fork ", lfork, rfork);
    // print(phil_no, " is thinking...");

    // fork_mutex[lfork].unlock();
    // fork_mutex[rfork].unlock();
    // std::this_thread::sleep_for(think_time);
}

int main() {
    // start a separate thread for each philosopher
    std::vector<std::thread> philos;

    for (int i = 0; i < nphilosophers; ++i)
        philos.push_back(std::move(std::thread{dine, i}));

    for (auto& philo : philos)
        philo.join();

    // how many times were the philosophers able to eat?
    for (int i = 0; i < nphilosophers; ++i) {
        std::cout << "philosopher " << names[i];
        std::cout << " had " << mouthfuls[i] << " mouthfuls\n";
    }
    return 0;
}
}     // namespace deadlockPrac
#endif     // DEADLOCK_PRAC_H