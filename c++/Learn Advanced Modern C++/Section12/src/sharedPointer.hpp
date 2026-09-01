#ifndef SHARED_POINTER_H
#define SHARED_POINTER_H

#include <iostream>
#include <memory>

using namespace std;

namespace sharedPointer {
int main() {
    shared_ptr<int> p1{new int(42)};
    auto p2{make_shared<int>(42)};

    cout << *p1 << endl;     // single object can be dereferenced
    // ++p1;                // error - pointer arithmetic not supported
    // ++p2;                // error - pointer arithmetic not supported
    p1 = p2;                               // ok shared_ptr can be assigned to
    shared_ptr<int> p3(p2);                // ok shared_ptr can be copied
    shared_ptr<int> p4(std::move(p2));     // ok
    p1 = nullptr;                          // calls delete on the pointer member
                                           // and sets ???
    return 0;
}
}     // namespace sharedPointer
#endif     // SHARED_POINTER_H