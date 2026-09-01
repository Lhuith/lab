#ifndef REFACTORING_H
#define REFACTORING_H

#include <fplus/fplus.hpp>
#include <iostream>

namespace refactoring {

struct base {
    virtual int get_val() const = 0;
};

struct foo : public base {
    int get_val() const override {
        return 1;
    }
};

struct bar : public base {
    int get_val() const override {
        return 10;
    }
};

int main() {
    using namespace std;
    using namespace fplus;

    std::vector<shared_ptr<base>> ptrs = {
        make_shared<foo>(),
        make_shared<foo>(),
        make_shared<foo>(),
        make_shared<foo>(),
    };

    const auto vals = transform(mem_fn(&base::get_val), ptrs);

    return 0;
}
}     // namespace refactoring
#endif     // REFACTORING_H