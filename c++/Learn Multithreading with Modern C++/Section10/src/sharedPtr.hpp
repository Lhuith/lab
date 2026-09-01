#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

using namespace std;

namespace sharedPtr {

// std::shared_tpr has an "atomic" reference counter
std::shared_ptr<int> shptr = std::make_shared<int>(42);

std::mutex mut;

void func1() {
    // increments shared_p's reference counter - safe
    // std::shared_ptr<int> shp1 = shptr;

    // potentially conflicting access - must be protected
    std::lock_guard<std::mutex> lgd(mut);
    *shptr = 5;
}

void func2() {
    // increments shared_p's reference counter - safe
    // std::shared_ptr<int> shp2 = shptr;

    // potentially conflicting access - must be protected
    std::lock_guard<std::mutex> lgd(mut);
    *shptr = 7;
}

int main() {
    // // pass a pointer as the constructor argument
    // std::shared_ptr<int> ptr1(new int(42));

    // // calling std::make_shared() is better
    // auto ptr2 = std::make_shared<int>(32);

    // // can be dereferenced
    // std::cout << *ptr1 << '\n';
    // std::cout << *ptr2 << '\n';

    // // pointer arithmetic is not supported
    // // ++ptr1;

    // // assignment, copying and moving are allowed
    // ptr1 = ptr2;
    // std::cout << *ptr1 << '\n';

    // std::shared_ptr<int> ptr3(ptr2);
    // std::shared_ptr<int> ptr4(std::move(ptr2));

    // // releases the collocated memory
    // ptr1 = nullptr;

    std::cout << "shptr data: " << *shptr << '\n';

    std::thread thr1(func1);
    std::thread thr2(func2);

    thr1.join();
    thr2.join();

    std::cout << "shptr data: " << *shptr << '\n';

    return 0;
}
}     // namespace sharedPtr
#endif     // SHARED_PTR_H