#ifndef LESS_THAN_OPS_H
#define LESS_THAN_OPS_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace lessThanOps {

class student {
    std::string name;     // student name - not necessarily unique
    int id;               // student ID number - unique to each student

   public:
    student(std::string name, int id) : name(name), id(id) {}
    friend bool operator==(const student& lhs, const student& rhs);
    friend bool operator!=(const student& lhs, const student& rhs);
    friend bool operator<(const student& lhs, const student& rhs);
    void print() {
        cout << "name: " << name << ", id = " << id << endl;
    }
};

bool operator==(const student& lhs, const student& rhs) {
    return lhs.id == rhs.id;
}

bool operator!=(const student& lhs, const student& rhs) {
    return !(lhs == rhs);
}

bool operator<(const student& lhs, const student& rhs) {
    return (lhs.id < rhs.id);     // order by ID (numerical order)
}

void vectorSort() {
    vector<string> names = {"Dilbert", "PHB", "Dogbert", "Asok", "Ted", "Alice", "Wally"};

    cout << "vector before sort()\n";
    for (auto name : names)
        cout << name << ", ";
    cout << endl
         << endl;
    sort(begin(names), end(names));

    cout << "vector after sort() \n";
    for (auto name : names)
        cout << name << ", ";
    cout << endl
         << endl;
}

int main() {
    student stu1{"John Smith", 561234};
    student stu2{"John Smith", 453811};
    student stu3{"Jack Jones", 692837};

    cout << "stu1: ";
    stu1.print();

    cout << "stu2: ";
    stu2.print();

    cout << "stu3: ";
    stu3.print();

    vector<student> students = {stu1, stu2, stu3};
    cout << "vector before sorting: " << endl;
    for (auto student : students)
        student.print();
    cout << endl;

    sort(begin(students), end(students));

    cout << "vector after sorting: " << endl;
    for (auto student : students)
        student.print();

    // cout << boolalpha << endl;
    // cout << "stu1 < stu2: " << (stu1 < stu2) << endl;
    // cout << "stu1 < stu3: " << (stu1 < stu3) << endl
    //      << endl;
    // cout << "stu2 < stu3: " << (stu2 < stu3) << endl;
    // cout << "stu2 < stu1: " << (stu2 < stu1) << endl
    //      << endl;
    // cout << "stu3 < stu2: " << (stu3 < stu2) << endl;
    // cout << "stu3 < stu1: " << (stu3 < stu1) << endl;
    // cout << noboolalpha << endl;

    // vectorSort();
    return 0;
}
}     // namespace lessThanOps
#endif     // LESS_THAN_OPS_H