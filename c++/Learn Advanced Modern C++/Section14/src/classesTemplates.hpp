#ifndef CLASSES_TEMPLATES_H
#define CLASSES_TEMPLATES_H

#include <iostream>
using namespace std;

namespace classesTemplates {

// c++14 generic lambda
auto lambda = [](auto x, auto y) { return x + y; };

// equivalent functor class with member template
class functor {
   public:
    template <typename T>
    T operator()(T x, T y) { return x + y; }     // lambda expression body
};

// templated class with parameter T
template <typename T>
class comparer {
    T t1, t2;

   public:
    comparer(const T& t1, const T& t2) : t1(t1), t2(t2) {}

    // member template with parameter func
    template <typename func>
    bool compare(func f) { return f(t1, t2); }
};

int main() {
    // // create a functor object, instantiate its function call operator and call it
    // cout << "functor()(2, 5): ";
    // cout << functor()(2, 5) << endl;
    // cout << "lambda()(2, 5): ";
    // cout << lambda(2, 5) << endl;

    int x{1}, y{2};

    // instantiate a comparer object where T is an int
    comparer<int> c(x, y);
    cout << "comparer class: t1 = " << x << ", t2 = " << y << endl;

    // instantiate comparer:compare() where <func> is a lambda expression
    auto b = c.compare([](int i1, int i2) { return i1 < i2; });
    cout << "result of calling compare: " << boolalpha << b << endl;
    cout << noboolalpha;

    return 0;
}
}     // namespace classesTemplates
#endif     // CLASSES_TEMPLATES_H