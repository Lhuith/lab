#ifndef FUNCTOR_H
#define FUNCTOR_H

#include <iostream>
#include <vector>
using namespace std;

namespace functor {

// class evenp {     // class with function call operator
//    public:
//     bool operator()(int n) {     // our function call operator
//         return (n % 2 == 0);     // return true if exactly divisible by 2
//     }
// };

class divisible {
   private:
    int divisor{1};

   public:
    divisible(int d) : divisor(d) {}
    bool operator()(int n) {
        return (n % divisor == 0);
    }
};

void do_it(const vector<int>& vec, divisible is_div) {
    for (auto v : vec)
        if (is_div(v))
            cout << v << " is divisible\n";
}

int main() {
    // evenp is_even;     // create a functor object

    // if (is_even(6)) {     // call its function call operator with argument 6
    // cout << "6 is an even number\n";
    // }

    vector<int> numbers{1, 4, 7, 11, 12, 23, 36};     // vector of numbers

    cout << "vector: ";
    for (auto number : numbers)
        cout << number << ", ";
    cout << endl;

    cout << "finding elements which are divisible by 3\n";

    divisible divisible_by_three{3};

    // pass this argument to the function call
    do_it(numbers, divisible_by_three);

    return 0;
}
}     // namespace functor
#endif     // FUNCTOR_H