#ifndef CONWAY_GRID_H
#define CONWAY_GRID_H

#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>

#include "conway_cell.hpp"

class grid
{
    // cells on screen
    // we have a border consisting of inactive cells.
    // these are used in the calculation for the next generation of cells,
    // but are not displayed on screen;
    cell cells[rowMax + 2][colMax + 2];

public:
    // create a cell at (row, column)
    void create(int row, int column)
    {
        cells[row][column].create();
    }

    // draw all the cells
    void draw()
    {
        // ANSI control command
        // \x1b means escape
        // Escape[2J clears the screen and returns the cursor to the "home" position
        cout << "\x1b[2J";

        for (int row = 0; row < rowMax; ++row)
        {
            for (int column = 0; column < colMax; ++column)
            {
                cells[row][column].draw(row, column);
            }
        }
    }

    // populate the grid with cells, at random
    void randomize()
    {
        const int factor = 5;
        const int cutoff = RAND_MAX / factor;

        time_t now;
        time(&now);
        // srand(now);

        for (int row = 1; row < rowMax; ++row)
        {
            for (int column = 1; column < colMax; ++column)
            {
                if (rand() / cutoff == 0)
                {
                    create(row, column);
                }
            }
        }
    }

    // will the cell at (row, column) survive to the next generation?
    bool will_survive(int row, int column)
    {
        if (!cells[row][column].is_alive())
        {
            // there is no cell at this pos!
            return false;
        }

        // find the number of live neighbours for this cell
        //
        //  x x x
        //  x o x
        //  x x x
        int neighbours = cells[row - 1][column - 1].is_alive() +
                         cells[row - 1][column].is_alive() +
                         cells[row - 1][column + 1].is_alive() +
                         cells[row][column - 1].is_alive() +
                         cells[row][column + 1].is_alive() +
                         cells[row + 1][column - 1].is_alive() +
                         cells[row + 1][column].is_alive() +
                         cells[row + 1][column + 1].is_alive();

        if (neighbours < min_neighbours || neighbours > max_neighbours)
        {
            // cell has died
            return false;
        }

        // if we get here, the cell has survived
        return true;
    }

    // will a cell be born at (row, column) in the next generation?
    bool will_create(int row, int column)
    {
        if (cells[row][column].is_alive())
        {
            // there already is a cell at this pos!
            return false;
        }

        // find the number of parents for this cell
        //
        //  x x x
        //  x o x
        //  x x x
        int parents = cells[row - 1][column - 1].is_alive() +
                      cells[row - 1][column].is_alive() +
                      cells[row - 1][column + 1].is_alive() +
                      cells[row][column - 1].is_alive() +
                      cells[row][column + 1].is_alive() +
                      cells[row + 1][column - 1].is_alive() +
                      cells[row + 1][column].is_alive() +
                      cells[row + 1][column + 1].is_alive();

        if (parents < min_parents || parents > max_parents)
        {
            // cannot create a cell here
            return false;
        }

        // if we get here, a new cell can be born
        return true;
    }

    // update to the next generation
    void update(const grid &next)
    {
        for (int row = 1; row < rowMax; ++row)
        {
            for (int column = 1; column < colMax; ++column)
            {
                cells[row][column] = next.cells[row][column];
            }
        }
    }
};

// non-member function
// calculate which cells survive to the next generation and which are born

// by default, all cells in the next generation are initially unpopulated
// calculate which live cells survive to the next generation
// and unpopulated cells are populated in the next generation
void calculate(grid &old_generation, grid &new_generation)
{
    for (int row = 1; row < rowMax; ++row)
    {
        for (int column = 1; column < colMax; ++column)
        {
            // will this live cell survive to the next generation?
            if (old_generation.will_survive(row, column))
            {
                new_generation.create(row, column);
            }
            // will this unpopulated cell be populated in the next generation?
            else if (old_generation.will_create(row, column))
            {
                new_generation.create(row, column);
            }
        }
    }
}

#endif // CONWAY_GRID_H