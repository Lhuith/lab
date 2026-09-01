#ifndef MASTERMIND_GAME_H
#define MASTERMIND_GAME_H

#include <algorithm>
#include <iostream>
#include <random>

#include "mastermindConstants.hpp"

using namespace std;

namespace mastermindGame {

// find the number of exact matches
// an exact match occurs when a peg in "guess" has the same colour
// as the corresponding peg in "solution"
int exact_matches(const peg_array& guess, const peg_array& solution) {
    // create a new peg_array
    // if there is an exact match, append the colour of the matching peg
    // otherwise, append 0
    peg_array matches;
    transform(begin(guess), end(guess), begin(solution), begin(matches),
              [](const char c1, const char c2) { return (c1 == c2) ? c1 : '\0'; });

    // return the number of exact matches (the number of non-zero elements)
    return count_if(begin(matches), end(matches), [](const char c) { return c != '\0'; });
}

// find the number of loose matches
// an loose match occurs when a peg in "guess" has the same colour
// as any peg in "solution"
int loose_matches(const peg_array& guess, const peg_array& solution) {
    string copy_guess;

    // counter to store the number of loose matches
    int count{0};

    // make a copy of the user's guess
    copy(begin(guess), end(guess), back_inserter(copy_guess));

    // loop over the solution
    // look for each solution peg anywhere in the users guess
    for (auto colour = begin(solution); colour != end(solution); ++colour) {
        auto it = find_if(begin(copy_guess), end(copy_guess),
                          [=](const char c) { return c == *colour; });

        // if the solution peg is anywhere in the user's guess, increment the counter.
        // remove the peg from the user's guess (do not process again)
        if (it != end(copy_guess)) {
            ++count;
            copy_guess.erase(it);
        }
    }

    // return the counter
    return count;
}

string normalize(const string& s) {
    string retval{""};

    copy_if(cbegin(s), cend(s), back_inserter(retval),
            [](char c) { return isalpha(c); });
    transform(begin(retval), end(retval), begin(retval),
              [](char c) { return tolower(c); });

    return retval;
}

peg_array get_input() {
    string input{""}, normal{""};
    peg_array result{""};

    do {
        cout << "enter " << mastermindConstants::npegs << " characters (";
        for (auto c : mastermindConstants::colours)
            cout << c;
        cout << ")" << endl;
        getline(cin, input);

        normal = normalize(input);
    } while (normal.size() != mastermindConstants::npegs);

    for (size_t i = 0; i < normal.size(); ++i) {
        result[i] = normal[i];
    }
    return result;
}

peg_array populate() {
    peg_array code{0};
    // random_device rd;
    // mt19937 mt(rd());
    static mt19937 mt;
    uniform_int_distribution<int> ud(0, mastermindConstants::ncolours - 1);

    generate(begin(code), end(code),
             [&]() { return mastermindConstants::colours[ud(mt)]; });

    return code;
}

int main() {
    // peg_array pegs = populate();
    peg_array pegs = {'r', 'r', 'r', 'b'};

    bool winner{false};

    for (int i = 0; i < mastermindConstants::nturns; ++i) {
        peg_array input = get_input();

        auto exact = exact_matches(input, pegs);
        auto loose = loose_matches(input, pegs) - exact;
        cout << exact << " exact match(es)" << endl;
        cout << loose << " near match(es)" << endl;

        if (exact == mastermindConstants::npegs) {
            cout << "you have found the correct solution! ";
            for (auto peg : pegs)
                cout << peg;
            cout << endl;
            winner = true;
            break;
        }
    }
    if (!winner) {
        cout << "sorry! the solution was:";
        for (auto peg : pegs)
            cout << peg;
        cout << endl;
    }

    return 0;
}
}     // namespace mastermindGame
#endif     // MASTERMIND_GAME_H