#ifndef LOCK_FREE_PROG_PRAC_CONT_H
#define LOCK_FREE_PROG_PRAC_CONT_H

#include <iostream>
#include <list>
#include <thread>
#include <vector>

using namespace std;

namespace lockFreeProgPracCont {

template <typename T>
struct LockFreeQueue {
   private:
    // use the std::list to store the elements
    std::list<T> lst;

    // iHead and iTail iterators
    typename std::list<T>::iterator iHead, iTail;

   public:
    // class constructor
    LockFreeQueue() {
        // create a "dummy" element to separate iHead and iTail
        lst.push_back(T());
        iHead = lst.begin();
        iTail = lst.end();
    }

    // producer thread function
    void Produce(const T& t) {
        // add the new element
        lst.push_back(t);

        // update tail
        iTail = lst.end();

        // erase the removed elements
        lst.erase(lst.begin(), iHead);
    }

    // consume thread function
    bool Consume(T& t) {
        // go to the first element
        auto iFirst = iHead;
        ++iFirst;

        // if queue is not empty
        if (iFirst != iTail) {
            // update iHead
            iHead = iFirst;

            // fetch this first element
            t = *iHead;
            return true;
        }

        // no elements to fetch
        return false;
    }

    // function to display all the elements
    void Print() {
        // go to the first element
        auto head = iHead;
        ++head;

        // we cannot use a range-for loop, because we only access some of the elements
        for (auto el = head; el != iTail; ++el)
            std::cout << *el << ", ";
        std::cout << '\n';
    }
};

int main() {
    LockFreeQueue<int> lfq;
    std::vector<std::thread> threads;
    int j = 1;

    for (int i = 0; i < 10; ++i) {
        // run the member functions of LockFreeQueue in threads
        // syntax for member function with std::thread
        // first argument is a pointer to the member function
        // second argument is the address of the object the member function called on
        // (this will be "this" pointer in the member function)
        // then the arguments to the member function. These are passed as reference to int
        // so we need to wrap them in std::ref()
        /*
                lfq.Produce(i);
                lfq.Consume(j);
        */

        std::thread produce(&LockFreeQueue<int>::Produce, &lfq, std::ref(i));
        threads.push_back(std::move(produce));
        std::thread consume(&LockFreeQueue<int>::Consume, &lfq, std::ref(j));
        threads.push_back(std::move(consume));
    }

    // wait for the threads to complete
    for (auto& thr : threads)
        thr.join();

    lfq.Print();

    return 0;
}
}     // namespace lockFreeProgPracCont
#endif     // LOCK_FREE_PROG_PRAC_CONT_H