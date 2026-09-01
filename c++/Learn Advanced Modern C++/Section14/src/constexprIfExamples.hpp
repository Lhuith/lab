#ifndef CONSTEXPR_IF_EXAMPLES_H
#define CONSTEXPR_IF_EXAMPLES_H

#include <iostream>
#include <string>

using namespace std;

namespace constexprIfExamples {

// general case (N > 1)
// template <int N>
// int fibonacci() {
//     return fibonacci<N - 1>() + fibonacci<N - 2>();
// }

// // specialization for N == 1
// template <>
// int fibonacci<1>() {
//     return 1;
// }

// // specialization for N == 0
// template <>
// int fibonacci<0>() {
//     return 1;
// }

template <int N>
constexpr int fibonacci() {
    if constexpr (N > 1) {
        return fibonacci<N - 1>() + fibonacci<N - 2>();
    } else {
        return N;
    }
}

// template <typename T>
// void func(T t) {
//     cout << "non-variadic template\n";
//     cout << "processing argument " << t << endl;
// }

// template <typename T, typename... Args>     // Args is a list of types(template parameter pack)
// void func(T t, Args... args) {              // args is a list of arguments whose types match Args
//     size_t n_args = sizeof...(args) + 1;
//     cout << "variadic template: compiler has deduced variadic call with " << n_args << " argument(s)\n";
//     cout << "processing argument " << t << endl;
//     func(args...);
// }

template <typename T, typename... Args>     // Args is a list of types(template parameter pack)
void func(T t, Args... args) {              // args is a list of arguments whose types match Args
    size_t n_args = sizeof...(args) + 1;
    cout << "variadic template: compiler has deduced variadic called with " << n_args << " argument(s)\n";
    cout << "processing argument " << t << endl;

    if constexpr (sizeof...(args) > 0)
        func(args...);
}

int main() {
    // constexpr int n{10};
    // cout << "fibonacci number " << n << " is: " << fibonacci<n>() << endl;

    int i{42};
    double d{0.0};
    string s{"text"};

    func(i, d, s);     // instantiated as func(int, double, string)

    return 0;
}
}     // namespace constexprIfExamples
#endif     // CONSTEXPR_IF_EXAMPLES_H