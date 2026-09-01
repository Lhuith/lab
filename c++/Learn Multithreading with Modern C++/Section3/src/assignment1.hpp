#ifndef ASSIGNMENT_1_H
#define ASSIGNMENT_1_H

#include <iostream>
#include <thread>
#include <vector>

namespace assignment1 {

void fizzBuzz(size_t max) {
    std::vector<std::string> names{"Abdul", "Bart", "Claudia", "Divya"};

    std::string says;
    for (size_t i = 1; i <= max; ++i) {
        bool divBy3 = i % 3 == 0;
        bool dibBy5 = i % 5 == 0;

        if (divBy3 && dibBy5) {
            says = "fizzbuzz!";
        } else if (divBy3) {
            says = "fizz!";
        } else if (dibBy5) {
            says = "buzz!";
        } else {
            says = std::to_string(i);
        }

        std::cout << names[(i - 1) % 4] << "\t\tsays " << says << std::endl;
    }
}

int main() {
    // fizzBuzz(32);
    std::thread thr(fizzBuzz, 32);

    thr.join();

    return 0;
}

}     // namespace assignment1
#endif     // ASSIGNMENT_1_H