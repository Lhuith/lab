// code for a "breakout" game
// based on a talk by Vittorio Romeo and code by "GamTrimli"
// uses the SFML graphics library

#include "game.hpp"

// the main function for the program
int main() {
    // create an instance of the game, initialize it run it
    game the_game;
    the_game.reset();
    the_game.run();

    return 0;
}