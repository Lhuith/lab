#ifndef THREAD_FUNCTIONS_WITH_ARGS_H
#define THREAD_FUNCTIONS_WITH_ARGS_H

#include <iostream>
#include <thread>
using namespace std;

namespace threadFunctionsWithArgs {

// thread entry point
// void hello(std::string str) {
//     std::cout << str << '\n';
// }

void hello(std::string& str) {
    str = "xyz";
}

// requires rvalue argument
void func(std::string&& str) {
    std::cout << "ownership of \"" << str << "\" transferred to thread" << '\n';
}

// class whose member function
// will be used as the thread's entry point
class greeter {
   public:
    void hello() {
        std::cout << "hello, member function thread!\n";
    }
};

int main() {
    // hello() takes a string argument
    // std::thread thr(hello, "Hello, Thread!");

    // thr.join();

    // std::string str = "movable";
    // std::cout << "starting thread" << '\n';

    // // wrap str in a call to std::move()
    // std::thread thr(func, std::move(str));
    // thr.join();

    // // verify that str has been modified
    // std::cout << "do I still have any data?" << ' ';
    // std::cout << (str.empty() ? "No" : "Yes") << ".\n";

    // std::string str = "abc";

    // // wrap argument in a call to std::ref()
    // std::thread thr(hello, std::ref(str));
    // thr.join();

    // // verify that it has been modified
    // std::cout << "str is now " << str << '\n';

    // // create an object of the class
    // greeter greet;

    // // create an std::thread object
    // // pass a pointer to the member function
    // // a pointer to the object to call it on
    // std::thread thr(&greeter::hello, &greet);

    // thr.join();

    int i = 3;

    // use a lambda expression as the thread's entry point
    std::thread thr(
        // the first argument is the lambda expression
        [&i] { return i *= 2; });
    thr.join();

    std::cout << "value of i is now " << i << endl;
    cout << endl;

    // use a lambda expression as the thread's entry point
    std::thread thr2(
        // the first argument is the lambda expression
        [](int i1, int i2) {
            std::cout << "the sum of " << i1 << " and " << i2 << " is " << i1 + i2 << '\n';
        },
        // the remaining arguments are passed to the lambda expression
        2, 3);

    thr2.join();

    return 0;
}
}     // namespace threadFunctionsWithArgs
#endif     // THREAD_FUNCTIONS_WITH_ARGS_H