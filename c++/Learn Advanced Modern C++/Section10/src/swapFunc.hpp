#ifndef SWAP_FUNC_H
#define SWAP_FUNC_H

#include <iostream>
using namespace std;

namespace swapFunc {

class strung {
   private:
    int size;
    char* data;

   public:
    strung(int s) : size(s), data(new char[s]) {}

    strung(const strung& arg) : size(arg.size) {
        cout << "calling copy constructor\n";
        data = new char[size];     // allocate the heap memory for arg's data

        for (int i = 0; i < size; ++i)     // populate the memory with arg's data
            data[i] = arg.data[i];
    }

    // assignment operator
    strung& operator=(const strung& arg) {
        cout << "calling assignment operator\n";
        strung temp(arg);      // create a copy of other
        swap(*this, temp);     // replace our data with temp's data
        return *this;          // return the assigned-to object
    }     // temp is destroyed

    // strung& operator=(const strung& arg) {
    //     cout << "calling assignment operator\n";

    //     if (&arg != this) {     // check for self-assignment
    //         cout << "reallocating memory\n";
    //         char* ndata = new char[arg.size];     // allocate the data member
    //         delete[] data;                        // release the original memory
    //         data = ndata;                         // assign the pointer

    //         size = arg.size;     // assign to the size member

    //         for (int i = 0; i < size; ++i)     // populate the data
    //             data[i] = arg.data[i];
    //     }

    //     return *this;     // return the assigned-to object
    // }

    // destructor
    ~strung() noexcept {
        cout << "calling destructor: " << static_cast<void*>(data) << endl;
        delete[] data;     // release the heap memory for the data
    }

    int length() const {
        return size;
    }

    // thanks gfg: vinod19ldr
    // https://www.geeksforgeeks.org/how-to-provide-a-swap-function-for-my-class-in-cpp/
    // void swap(strung& o) noexcept {
    //     std::swap(size, o.size);
    //     std::swap(data, o.data);
    // }

    // declare overloaded swap() as a friend of this class
    friend void swap(strung& l, strung& r) noexcept;

    void print() {
        cout << "strung with size = " << size;
        cout << ", data address " << static_cast<void*>(data) << endl;
    }
};

// void swap(strung& l, strung& r) noexcept {
//     l.swap(r);
// }

inline void swap(strung& l, strung& r) noexcept {
    cout << "in strung::swap\n";
    std::swap(l.size, r.size);
    std::swap(l.data, r.data);
}

int main() {
    // strung a(5), b(6);
    // cout << "before swapping\n";
    // cout << "a: ";
    // a.print();
    // cout << "b: ";
    // b.print();

    // swap(a, b);

    // cout << endl
    //      << "after swapping\n";
    // cout << "a: ";
    // a.print();
    // cout << "b: ";
    // b.print();
    // cout << endl;

    strung a{5};
    cout << "a: ";
    a.print();

    strung b{6};
    cout << "b: ";
    b.print();
    cout << endl;
    cout << "copy construction of c from b\n";
    strung c{b};

    cout << "b: ";
    b.print();
    cout << "c: ";
    c.print();
    cout << endl;
    cout << "assigning a from c\n";
    a = c;

    cout << "a: ";
    a.print();
    cout << "c: ";
    c.print();
    cout << endl;
    cout << "exiting program ... \n";

    return 0;
}
}     // namespace swapFunc
#endif     // SWAP_FUNC_H