#ifndef CONSTANT_EXPRESSION_H
#define CONSTANT_EXPRESSION_H

#include <iostream>
using namespace std;

namespace constantExpression {
int main() {
    int i{42}, j{99};

    // NB compile with -pedantic with g++
    [[maybe_unused]] int arr[i + j];     // array dimension must be a constant expression

    return 0;
}
}     // namespace constantExpression
#endif     // CONSTANT_EXPRESSION_H