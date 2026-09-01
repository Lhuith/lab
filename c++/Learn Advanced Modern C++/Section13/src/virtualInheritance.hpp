#ifndef VIRTUAL_INHERITANCE_H
#define VIRTUAL_INHERITANCE_H

#include <iostream>
using namespace std;

namespace virtualInheritance {

class Employee {
   public:
    void address() { cout << "Employee address = " << static_cast<void *>(this) << endl; }
};

class SalesEmployee : public virtual Employee {
};

class Manager : public virtual Employee {
};

class SalesManager : public SalesEmployee, public Manager {
};

int main() {
    SalesManager sm;

    cout << "cast to SalesEmployee\n";
    SalesEmployee *se{static_cast<SalesEmployee *>(&sm)};
    se->address();

    cout << "cast to manager\n";
    Manager *m{static_cast<Manager *>(&sm)};
    m->address();

    return 0;
}
}     // namespace virtualInheritance
#endif     // VIRTUAL_INHERITANCE_H