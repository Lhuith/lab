#ifndef CONWAY_H
#define CONWAY_H

#include <iostream>
using namespace std;

#include "conway_grid.hpp"

// uncomment if running windows console
// #include "conway_ansi_escapes.hpp"

namespace conway
{

    int main(int argc, char *argv[])
    {
        cout << "Conway's game of Life\n";
        cout << "Press the return key to display each generation\n";

        // wait for user to press the return key;
        cin.get();

        // uncomment if running in windows console
        // enable ANSI escape codes in windows
        // setupConsole();

        // grid for the first generation
        grid current_generation;

        // populate the cells at random
        current_generation.randomize();

        while (true)
        {
            // draw the current generation
            current_generation.draw();

            // wait for user to press the return key
            // cin.get();

            // grid for next generation
            grid next_generation;

            // populate the cells in the next generation
            calculate(current_generation, next_generation);

            // update to the next generation
            current_generation.update(next_generation);
        }

        // move cursor to bottom of screen
        cout << "\x1b[" << 0 << ";" << rowMax - 1 << "H";

        // uncomment if running in windows console
        // restore console on windows
        // restoreConsole();

        return 0;
    }
}

#endif // CONWAY_H