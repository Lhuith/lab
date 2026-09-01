#ifndef RAII_CLASS_MOVE_H
#define RAII_CLASS_MOVE_H

#include <iostream>
using namespace std;

namespace raiiClassMove {

class strung {
   private:
    int size;
    char* data;

   public:
    strung(int size) : size(size), data(new char[size]) {}

    strung(const strung& arg) : size(arg.size) {
        cout << "calling copy constructor\n";
        data = new char[size];     // allocate the heap memory for arg's data

        for (int i = 0; i < size; ++i)
            data[i] = arg.data[i];
    }

    // assignment operator
    strung& operator=(const strung& arg) {
        cout << "calling assignment operator\n";

        if (&arg != this) {     // check for self-assignment
            cout << "reallocating memory\n";
            delete[] data;                 // release the original memory
            data = new char[arg.size];     // allocate the data member

            size = arg.size;     // assign to the size member

            for (int i = 0; i < size; ++i)     // populate the data
                data[i] = arg.data[i];
        }

        return *this;     // return the assigned-to object
    }

    // move constructor
    strung(strung&& arg) noexcept {
        cout << "move constructor called" << endl;
        data = arg.data;
        size = arg.size;

        // anything else?
        // 'arg' and 'this' now have a pointer to the same allocated memory
        // we must make sure 'arg' does not delete the pointer
        arg.data = nullptr;     // safe - deleing nullptr has no effect
        arg.size = 0;
    }

    // move assignment operator
    // strung& operator=(strung&& arg) noexcept {
    //     if (this != &arg) {
    //         delete[] data;
    //         data = arg.data;
    //         size = arg.size;
    //         cout << "move assignment operator called" << endl;

    //         arg.data = nullptr;
    //         arg.size = 0;
    //     }
    //     return *this;
    // }

    // move-swap assignment operator
    strung& operator=(strung&& arg) noexcept {
        cout << "move-swap assignment operator called" << endl;
        strung temp(std::move(arg));     // call move constructor
        swap(*this, temp);

        return *this;
    }

    // destructor
    ~strung() {
        cout << "calling destructor: " << static_cast<void*>(data) << endl;
        delete[] data;
    }

    friend void swap(strung& l, strung& r) noexcept;

    void print() {
        cout << "strung with size = " << size;
        cout << ", data address " << static_cast<void*>(data) << endl;
    }
};

inline void swap(strung& l, strung& r) noexcept {
    cout << "in strung::swap\n";
    std::swap(l.size, r.size);
    std::swap(l.data, r.data);
}

int main() {
    // strung a{5};
    // cout << "a: ";
    // a.print();
    // {
    //     strung b{6};
    //     cout << "b: ";
    //     b.print();
    //     cout << endl;
    //     cout << "Copy construction of c from b\n";
    //     strung c{b};
    //     cout << "b: ";
    //     b.print();
    //     cout << "c: ";
    //     c.print();
    //     cout << endl;
    //     cout << "Move construction of d from b\n";
    //     strung d{std::move(b)};
    //     cout << "b: ";
    //     b.print();
    //     cout << "d: ";
    //     d.print();
    //     cout << endl;
    // }

    strung a{5};
    cout << "a: ";
    a.print();
    {
        strung b{6};
        cout << "b: ";
        b.print();
        cout << endl;
        cout << "copy assignment of b from a\n";
        b = a;
        cout << "b: ";
        b.print();
        cout << "a: ";
        a.print();
        cout << endl;
        cout << "copy construction of c from b\n";
        strung c{b};
        cout << "b: ";
        b.print();
        cout << "c: ";
        c.print();
        cout << endl;
        cout << "move assignment of c from a\n";
        c = std::move(a);
        cout << "a: ";
        a.print();
        cout << "c: ";
        c.print();
        cout << endl;
    }
    return 0;
}
}     // namespace raiiClassMove
#endif     // RAII_CLASS_MOVE_H