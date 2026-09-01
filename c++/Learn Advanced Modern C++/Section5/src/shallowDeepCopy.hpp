#ifndef SHALLOW_DEEP_COPY_H
#define SHALLOW_DEEP_COPY_H

#include <iostream>
using namespace std;

namespace shallowDeepCopy {

class strung {
    char *data;  // array member to store the characters
    int size;    // the number of elements in the array
   public:
    // constructor
    strung(const std::string &s) : size(s.size()) {
        data = new char[size];  // allocate the heap memory for the data

        for (int i = 0; i < size; i++)  // populate the data
            data[i] = s[i];
    }

    // copy constructor
    strung(const strung &arg) : size(arg.size) {  // deep copy
        cout << "calling copy constructor \n";
        data = new char[size];  // allocate the heap memory for args data

        for (int i = 0; i < size; ++i)
            data[i] = arg.data[i];
    }

    // synthesized member functions
    strung &operator=(const strung &arg) {
        cout << "calling assignment operator \n";

        if (&arg != this) {             // check for self-assignment
            delete[] data;              // release the original memory
            data = new char[arg.size];  // allocate the data member

            size = arg.size;  // assign to the size member

            for (int i = 0; i < size; ++i)  // populate the data
                data[i] = arg.data[i];
        }
        return *this;  // return assigned-to object
    }

    // destructor
    ~strung() {
        cout << "calling destructor" << endl;
        delete[] data;  // release the heap memory
    }

    int length() { return size; }
};

int main() {
    strung str("1"s);
    strung str2("two"s);
    strung str3(str2);

    cout << "str2 size: " << str2.length() << endl;
    cout << "str3 size: " << str3.length() << endl;
    str2 = str3;
    cout << "str2 size: " << str2.length() << endl;
    cout << "str size : " << str.length() << endl;

    return 0;
}

}  // namespace shallowDeepCopy
#endif  // SHALLOW_DEEP_COPY_H