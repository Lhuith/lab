#ifndef LIB_DEFINED_OPS_H
#define LIB_DEFINED_OPS_H

#include <functional>
#include <iostream>

using namespace std;

namespace libDefinedOps {

// function template with parameter func
// if caller does not provide a callable object, use T's operator <
template <typename T, typename Func = greater<T>>
bool compare(const T& t1, const T& t2, Func func = Func()) {
    return func(t1, t2);
}

int main() {
    int x{1}, y{2};
    cout << "x = " << x << ", y = " << y << endl;

    auto b = compare(x, y, [](int i1, int i2) { return i1 < i2; });
    cout << "result of calling compare lambda: " << boolalpha << b << endl;

    auto b2 = compare(x, y);
    cout << "result of calling compare with default: " << b2 << endl;
    cout << noboolalpha;

    return 0;
}
}     // namespace libDefinedOps
#endif     // LIB_DEFINED_OPS_H