#ifndef EXCEPTION_SPECIAL_MEM_FUNCS_H
#define EXCEPTION_SPECIAL_MEM_FUNCS_H

#include <iostream>
using namespace std;

namespace exceptionSpecialMemFuncs {

class studentGrade {
    int grade;

   public:
    studentGrade(int g) : grade(g) {
        if (grade < 0 || grade > 100) {
            // invalid grade - throw exception
            throw std::out_of_range("invalid grade");
        }
    }
};

int main() {
    int result;
    cout << "please enter the student's grade (between 0 and 100): ";
    cin >> result;
    try {
        studentGrade sgrade(result);
        cout << "sgrade created\n";     // if we get here, no exception was thrown - safe to use sgrade
    } catch (const std::exception& e) {
        cout << "studentGrade constructor threw an exception: \n"
             << e.what() << endl;
    }

    return 0;
}
}     // namespace exceptionSpecialMemFuncs
#endif     // EXCEPTION_SPECIAL_MEM_FUNCS_H