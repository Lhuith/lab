#ifndef VARIADIC_TEMPLATES_H
#define VARIADIC_TEMPLATES_H

#include <iostream>
#include <string>
#include <tuple>

using namespace std;

namespace variadicTemplates {

template <typename... Args>     // Args is a list of types(template parameter pack)
void func(Args... args) {       // args is a list of arguments whose types match Args
    cout << "compiler has deduced call with " << sizeof...(args) << " arguments(s)\n";
}

template <typename... Args>                   // Args is a list of types(template parameter pack)
void func2(Args... args) {                    // args is a list of arguments whose types match Args
    auto arg_tuple = make_tuple(args...);     // store the arguments in a tuple
    auto first = get<0>(arg_tuple);
    cout << "first argument is " << first << endl;
}

template <typename T>
void func3(T t) {
    cout << "non-variadic template\n";
    cout << "processing argument " << t << endl;
}

template <typename T, typename... Args>     // Args is a list of types (template parameter pack)
void func3(T t, Args... args) {             // args is a list of arguments whose types match Args
    size_t n_args = sizeof...(args) + 1;
    cout << "Variadic template: compiler has deduced variadic call with " << n_args << " argument(s)\n";
    cout << "processing argument " << t << endl;
    func3(args...);
}

int main() {
    int i{42};
    double d{0.0};
    string s{"text"};

    // func(s);           // instantiated as func(string&);
    // func(i, d, s);     // instantiated as func(int, double, string);

    // func2(s);           // instantiated as func(string&);
    // func2(i, d, s);     // instantiated as func(int, double, string);

    func3(i, d, s);     // instantiated as func(int, double, string);
    return 0;
}
}     // namespace variadicTemplates
#endif     // VARIADIC_TEMPLATES_H