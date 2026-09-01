#ifndef WEAK_POINTER_CYCLE_PREVENTION_H
#define WEAK_POINTER_CYCLE_PREVENTION_H

#include <iostream>
#include <memory>

using namespace std;

namespace weakPointerCyclePrevention {

struct Son;

struct Father {
    ~Father() {
        cout << "father destructor" << endl;
    }

    void setSon(const shared_ptr<Son>& s) {
        mySon = s;
    }

    shared_ptr<const Son> mySon;
};

struct Son {
    Son(const shared_ptr<Father>& m) : myFather(m) {}
    ~Son() {
        cout << "son destructor" << endl;
    }
    weak_ptr<const Father> myFather;
};

int main() {
    cout << endl;
    {
        auto father = make_shared<Father>();
        auto son = make_shared<Son>(father);
        father->setSon(son);
    }
    cout << endl;

    return 0;
}
}     // namespace weakPointerCyclePrevention
#endif     // WEAK_POINTER_CYCLE_PREVENTION_H