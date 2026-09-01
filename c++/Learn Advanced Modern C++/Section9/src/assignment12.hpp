#ifndef ASSIGNMENT12_H
#define ASSIGNMENT12_H

#include <iostream>
using namespace std;

namespace assignment12 {

class base {
    int i;

   public:
    base(int i) : i(i) {}
    void virtual print() const { cout << "calling base\n"; }
};
class child : public base {
   public:
    child(int i) : base(i) {};
    void print() const override { cout << "calling child\n"; }
};
class grandchild : public child {
   public:
    grandchild(int i) : child(i) {};
    void print() const override { cout << "calling grandchild\n"; }
};

void print_class(base& b) {
    b.print();
}

int main() {
    base b(1);
    child c(2);
    grandchild gc(3);

    print_class(b);
    print_class(c);
    print_class(gc);

    return 0;
}
}     // namespace assignment12
#endif     // ASSIGNMENT12_H