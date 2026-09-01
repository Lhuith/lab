#ifndef COWNAY_LIFE_H
#define CONWAY_LIFE_H

const char live_cell{'o'};
const char dead_cell{' '};

// standard ANSI, with a 1-char border
// occupied rows go from 1 to 23
// occupied columns go from 1 to 79
const int rowMax = 23;
const int colMax = 79;

// conway's parameters;
const int min_neighbours = 2;
const int max_neighbours = 3;
const int min_parents = 3;
const int max_parents = 3;

#endif // COWNAY_LIFE_H