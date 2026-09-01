#ifndef WEAK_POINTER_H
#define WEAK_POINTER_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

namespace weakPointer {

void print(vector<shared_ptr<int>> vec) {
    cout << "vector elements: ";

    // for (shared_ptr<int> p : vec)
    //     cout << *p << ", ";

    for (weak_ptr<int> p : vec) {
        auto ptr = p.lock();

        if (ptr)
            cout << *ptr << ", ";
        else
            cout << "x, ";
    }

    cout << endl;
}

void vecPointer() {
    vector<shared_ptr<int>> vec{
        make_shared<int>(36),
        make_shared<int>(42),
        make_shared<int>(46),
        make_shared<int>(50)};

    print(vec);

    cout << "deleting vec[2]\n";
    vec[2] = nullptr;

    print(vec);
}

int main() {
    // // create a pointer
    // int *ptr = new int(36);
    // cout << "ptr's data is " << *ptr << endl;

    // // create pointer which is an alias to ptr
    // int *wptr = ptr;

    // // release the ptr's memory
    // delete ptr;

    // // how do we know if wptr is still valid?
    // cout << "wptr's data is " << *wptr << endl;

    // create shared_ptr<int> object
    // auto ptr{make_shared<int>(36)};     // reference count is 1
    // cout << "shared_ptr's data is " << *ptr << endl;

    // // create weak_ptr alias to ptr
    // weak_ptr<int> wptr = ptr;     // reference count is still 1

    // // release ptr's shared memory
    // ptr = nullptr;     // ptr's reference count is 0

    // // wptr is an alias to ptr - is it still valid?
    // shared_ptr<int> sp1 = wptr.lock();

    // if (sp1)
    //     cout << "shared_ptr's data is " << *ptr << endl;
    // else
    //     cout << "shared_ptr not valid" << endl;

    // try {
    //     shared_ptr<int> sp1{wptr};
    //     cout << "shared_ptr's data is " << *sp1 << endl;
    // } catch (exception& e) {
    //     cout << e.what() << endl;
    // }

    vecPointer();

    return 0;
}
}     // namespace weakPointer
#endif     // WEAK_POINTER_H