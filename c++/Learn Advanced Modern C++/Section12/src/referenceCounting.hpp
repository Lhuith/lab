#ifndef REFERENCE_COUNTING_H
#define REFERENCE_COUNTING_H

#include <iostream>
using namespace std;

namespace referenceCounting {

class Strung {
   private:
    int size;
    char *data;
    int *counter;     // the reference counter - also allocated on the heap

   public:
    Strung(int size) : size(size) {
        counter = new int{0};     // allocate the counter - no bound objects initially
        data = new char[size];

        ++*counter;     // "this" has been bound, increment the counter
        cout << "constructor: data = " << static_cast<void *>(data) << ", counter = " << counter << ", count = " << *counter << endl;
    }
    ~Strung() noexcept {
        cout << "destructor: data = " << (void *)data << ", counter = " << counter;
        if (counter) {
            cout << ", count = " << *counter << endl;
            // any other code need to clean up the object
            --*counter;              // an object has been unbound - decrement the counter
            if (*counter == 0) {     // if we are the last bound object, release the memory
                cout << "deleting shared memory at " << static_cast<void *>(data) << endl;
                cout << "deleting counter at " << static_cast<void *>(counter) << endl;
                delete counter;
                delete[] data;
            }
        } else
            cout << endl;
    }

    // declare overloaded swap() as a friend of this class
    friend void swap(Strung &l, Strung &r) noexcept;

    // < copy constructor
    Strung(const Strung &arg) {
        // make a shallow copy of the argument
        size = arg.size;
        data = arg.data;
        counter = arg.counter;

        // any other code needed to configure the new object
        ++*counter;     // "this" has been bound - increment counter
    }
    // < assignment operator
    Strung &operator=(const Strung &arg) {
        cout << "assigned-to object: data = " << (void *)data << ", counter = " << counter << ", count = " << *counter << endl;

        if (data != arg.data) {      // if arg is bound to different shared memory
            --*counter;              // unbind from our current shared memory
            if (*counter == 0) {     // if we are the last bound object, release the memory
                cout << "deleting shared memory at " << static_cast<void *>(data) << endl;
                delete counter;
                delete[] data;
            }

            size = arg.size;
            data = arg.data;
            counter = arg.counter;

            ++*counter;     // "this" has been bound - increment the counter
        }
        return *this;     // return the assigned-to object
    }

    /*
                // assignment operator
        Strung& operator =(const Strung& arg) {
                cout << "assigned-to object: data = " << (void *)data << ", counter = " << counter << ", count = " << *counter << endl;

                Strung temp(arg);	// create copy of other
                swap(*this, temp);	// replace our data with temp's data
                cout << "assigned-to object: data = " << (void *)data << ", counter = " << counter << ", count = " << *counter << endl;
                return *this;
        }	// temp is destroyed
     */

    // < move constructor
    Strung(Strung &&arg) noexcept {
        cout << "move constructor called" << endl;
        data = arg.data;
        size = arg.size;
        counter = arg.counter;     // shallow copy of counter pointer

        // prevent double deletion
        arg.data = nullptr;
        arg.counter = nullptr;
    }

    // < move assignment operator
    Strung &operator=(Strung &&arg) noexcept {
        cout << "move assignment operator called" << endl;
        Strung temp(std::move(arg));     //	call move constructor
        swap(*this, temp);               //	exchange our data with temp's data

        return *this;
    }

    int length() {
        return size;
    }
    int count() {
        return *counter;
    }

    void print() {
        cout << "size = " << size;
        cout << ", data address " << static_cast<void *>(data);
        cout << ", counter " << static_cast<void *>(counter);
        if (counter)
            cout << ", count = " << *counter;
        cout << endl;
    }
};

inline void swap(Strung &l, Strung &r) noexcept {
    using std::swap;
    swap(l.size, r.size);
    swap(l.data, r.data);
    swap(l.counter, r.counter);
}

int main() {
    Strung a{5};
    cout << "a: ";
    a.print();

    // Strung b{6};
    // cout << "b: ";
    // b.print();
    // cout << endl;
    // cout << "copy construction of c from b\n";
    // Strung c{b};

    // cout << "b: ";
    // b.print();
    // cout << "c: ";
    // c.print();
    // cout << endl;
    // cout << "assigning a from c\n";
    // a = c;

    // cout << "a: ";
    // a.print();
    // cout << "c: ";
    // c.print();
    // cout << endl;

    // cout << "exiting program ... \n";

    Strung b{6};
    cout << "b: ";
    b.print();
    cout << endl;
    cout << "move construction of c from b\n";
    Strung c{std::move(b)};

    cout << "b: ";
    b.print();
    cout << "c: ";
    c.print();
    cout << endl;
    cout << "move assign a from c\n";
    a = std::move(c);

    cout << "a: ";
    a.print();
    cout << "c: ";
    c.print();

    cout << "exiting program ... \n";

    return 0;
}
}     // namespace referenceCounting
#endif     // REFERENCE_COUNTING_H