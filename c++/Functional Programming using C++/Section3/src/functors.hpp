#ifndef FUNCTORS_H
#define FUNCTORS_H

#include <fplus/fplus.hpp>
#include <iostream>
#include <map>

namespace functors {

// identity : a -> a
// template <typename T>
// T identity(T x) { return x; }

// // template <typename F, A, B>
// // maybe<B> lift_maybe(F f, const maybe<A>& m) {
// //     if (is_just(m))
// //         return just<B>(f(unsafe_get_just(m)));
// //     return nothing<B>();
// // }

// int square(int x) {
//     return x * x;
// }

// // maybe<int> foo = just(4);
// // maybe<int> bar = nothing<int>

// auto foo_squared = lift_maybe(square, foo);
// // foo_squared is now Just 16

// auto bar_squared = lift_maybe(square, bar);
// // bar_squared is nothing

// lift_dict : ((a -> b) Map key a) -> Key key b
template <typename ValOut, typename F, typename Key, typename ValIn>
std::map<Key, ValOut> lift_dict(F f, const std::map<Key, ValIn>& dict) {
    std::map<Key, ValOut> result;
    for (const auto& key_and_val : dict) {
        result[key_and_val.first] = f(key_and_val.second);
    }
    return result;
}

int main() {
    // fmap(identity) == indentity;

    // fmape(compose(f, g) == compose(fmap(f), fmap(g)));

    // left_maybe : ((a -> b), Maybe a) -> Maybe b

    using namespace fplus;

    std::map<int, double> dict = {{2, 1.41}, {3, 173}, {4, 2.0}};
    auto dict_squared = lift_dict<double>(square<double>, dict);
    auto dict_shown = lift_dict<std::string>(show<double>, dict);
    std::cout << show_cont(dict_squared) << std::endl;
    std::cout << show_cont(dict_shown) << std::endl;

    return 0;
}
}     // namespace functors
#endif     // FUNCTORS_H