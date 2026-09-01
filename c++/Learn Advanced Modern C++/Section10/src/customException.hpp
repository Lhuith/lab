#ifndef CUSTOM_EXCEPTION_H
#define CUSTOM_EXCEPTION_H

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

namespace customException {

class bad_student_grade : public std::out_of_range {
   public:
    // default constructor
    bad_student_grade() : std::out_of_range("invalid grade: please try again") {}

    // we need constructors which take a string, for consistency with std::exception
    bad_student_grade(const char* s) : std::out_of_range(s) {}
    bad_student_grade(const string& s) : std::out_of_range(s) {}

    // these default operators are good enough as we do not have any data members
    bad_student_grade(const bad_student_grade& other) = default;
    bad_student_grade& operator=(const bad_student_grade& other) = default;

    // finally, we can override the virtual what() member function
    // const char* what() const noexcept override { /* ... */ }
};

class studentGrade {
    int grade;

   public:
    studentGrade(int grade) : grade(grade) {
        if (grade < 0)
            throw bad_student_grade("bad grade");
        else if (grade > 100)
            throw bad_student_grade();
    }
};

int main() {
    int result;
    cout << "please enter the student's grade (between 0 and 100)" << endl;
    cin >> result;

    try {
        studentGrade sgrade(result);
        // if we get here, no exceptions was thrown - safe to use sgrade
        cout << "valid student grade entered: " << result << endl;
    } catch (bad_student_grade& e) {
        cout << e.what() << "\n";
    }

    return 0;
}
}     // namespace customException
#endif     // CUSTOM_EXCEPTION_H