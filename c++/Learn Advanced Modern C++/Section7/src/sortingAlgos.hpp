#ifndef SORTING_ALGOS_H
#define SORTING_ALGOS_H

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace sortingAlgos {

class student {
    std::string name;
    int id;

   public:
    student(std::string name, int id) : name(name), id(id) {}
    friend bool operator==(const student& lhs, const student& rhs);
    friend bool operator!=(const student& lhs, const student& rhs);
    friend bool operator<(const student& lhs, const student& rhs);
    void print() {
        cout << "name: " << name << ", id: " << id << endl;
    }
};

bool operator==(const student& lhs, const student& rhs) {
    if (lhs.name == rhs.name)
        return true;
    return false;
}

bool operator!=(const student& lhs, const student& rhs) {
    return !(lhs == rhs);
}

bool operator<(const student& lhs, const student& rhs) {
    return (lhs.name < rhs.name);     // order by name (alphabetical order)
}

void print(const vector<int>& vec) {
    for (auto v : vec)
        cout << v << ", ";
    cout << endl;
}

void sort_predicate() {
    vector<int> vec{3, 1, 4, 1, 5, 9};

    cout << "vec: ";
    print(vec);

    sort(begin(vec), end(vec),
         [](int m, int n) { return m > n; });

    cout << "vec after sorting: ";
    print(vec);
}

void _is_sorted() {
    vector<int> vec{1, 4, 5, 6, 2, 7, 5};

    cout << "vec: ";
    print(vec);

    cout << "vec is sorted: " << boolalpha << is_sorted(cbegin(vec), cend(vec)) << endl;

    cout << "calling sorted \n";
    sort(begin(vec), end(vec));

    cout << "vec is sorted: " << is_sorted(cbegin(vec), cend(vec)) << endl;
    cout << noboolalpha << endl;     // boy scout move
}

void _is_sorted_until() {
    vector<int> vec{1, 4, 5, 6, 2, 7, 5};

    cout << "vec: ";
    print(vec);

    auto el = is_sorted_until(cbegin(vec), cend(vec));

    if (el != cend(vec)) {
        cout << "the first " << distance(cbegin(vec), el) << " elements are sorted\n";
        cout << "the first element which is not in order has value " << *el << endl;
    } else
        cout << "couldn't find an initial sequence which is sorted \n";
}

int main() {
    // student stu1("John Smith", 561234);
    // student stu2("John Smith", 453811);
    // student stu3("Jack Jones", 262184);
    // student stu4("Jack Jones", 692837);

    // vector<student> students = {stu1, stu2, stu3, stu4};

    // cout << "vector before sorting: " << endl;
    // for (auto s : students)
    //     s.print();

    // // the "john smith" students may be in either order
    // sort(begin(students), end(students));     // sort elements using < operator

    // cout << "vector after sorting: " << endl;
    // for (auto s : students)
    //     s.print();

    // sort_predicate();
    // _is_sorted();
    _is_sorted_until();

    return 0;
}
}     // namespace sortingAlgos
#endif     // SORTING_ALGOS_H