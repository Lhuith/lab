#ifndef FUNCTION_ARGS_MOVE_SEM_H
#define FUNCTION_ARGS_MOVE_SEM_H

#include <iostream>
using namespace std;

namespace functionArgsMoveSem {

class test {
    string m_str;

   public:
    test(string str) : m_str(std::move(str)) {}
};

int main() {
    string name;

    test ltest(name);     // lvalue passed, name is copied into str
                          // str is moved into m_str

    test rtest(std::move(name));     // rvalue passed - name is moved into str
                                     // str is moved into m_str

    return 0;
}
}     // namespace functionArgsMoveSem
#endif     // FUNCTION_ARGS_MOVE_SEM_H