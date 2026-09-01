#ifndef CONWAY_CELL_H
#define CONWAY_CELL_H

#include <iostream>

#include "conway_life.hpp"

using namespace std;

class cell
{
    // cell status
    bool alive;

public:
    // cells are empty by default
    cell() : alive(false) {}

    // draw cell on grid
    void draw(int row, int col) const
    {
        // ANSI control command
        // escape [;mH moves the cursor to row n, colum m
        // these are 1-index-based, i.e row 1 is the first row
        cout << "\x1b[" << row + 1 << ";" << col + 1 << "H";
        cout << (alive ? live_cell : dead_cell);
    };

    // bring cell to life
    void create()
    {
        alive = true;
    }

    // end cells life
    void erase()
    {
        alive = false;
    }

    bool is_alive() const { return alive; }
};

#endif // CONWAY_CELL_H