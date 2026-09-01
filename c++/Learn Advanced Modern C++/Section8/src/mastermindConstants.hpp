#ifndef MASTERMIND_CONSTANTS_H
#define MASTERMIND_CONSTANTS_H

#include <array>

namespace mastermindConstants {
const int npegs = 4;
const int nturns = 10;
const int ncolours = 3;
}     // namespace mastermindConstants

using peg_array = std::array<char, mastermindConstants::npegs>;
using colour_array = std::array<const char, mastermindConstants::ncolours + 1>;

namespace mastermindConstants {
const colour_array colours = {'r', 'g', 'b'};
}

#endif     // MASTERMIND_CONSTANTS_H