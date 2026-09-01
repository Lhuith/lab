#ifndef EQUALITY_OPS_H
#define EQUALITY_OPS_H

#include <iostream>
using namespace std;

namespace equalityOps {

class student {
    std::string name;     // student name - probs not unique
    int id;

   public:
    student(std::string name, int id) : name(name), id(id) {}
    friend bool operator==(const student& lhs, const student& rhs);
    friend bool operator!=(const student& lhs, const student& rhs);
    void print() {
        cout << "name: " << name << ", " << id << endl;
    };
};

bool operator==(const student& lhs, const student& rhs) {
    return lhs.id == rhs.id;
}

bool operator!=(const student& lhs, const student& rhs) {
    return !(lhs.id == rhs.id);
}

int main() {
    student stu1("john smith", 561234);
    student stu2("john smith", 453811);
    student stu3("jack jones", 692837);

    cout << "stu1: ";
    stu1.print();

    cout << "stu2: ";
    stu2.print();

    cout << "stu3: ";
    stu3.print();

    cout << boolalpha << endl;     // set output stream ??
    cout << "stu1 == stu2: " << (stu1 == stu2) << endl;
    cout << "stu1 != stu2: " << (stu1 != stu2) << endl
         << endl;
    cout << "stu1 == stu3: " << (stu1 == stu3) << endl;
    cout << "stu1 != stu3: " << (stu1 != stu3) << endl
         << endl;
    cout << "stu2 == stu3: " << (stu2 == stu3) << endl;
    cout << "stu2 != stu3: " << (stu2 != stu3) << endl;

    cout << noboolalpha << endl;

    return 0;
}
}     // namespace equalityOps
#endif     // EQUALITY_OPS_H