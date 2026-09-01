#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "constants.hpp"
#include "entity.hpp"

// class to represent the background
// inherits from entity
class background : public entity {
    // private data members
    static sf::Texture texture;

   public:
    // interface of the class

    // constructor
    // arguments are the initial coordinates of the centre of the background
    // SFML uses the computer graphics convention
    // (0, 0) is the top left corner of the screen
    // x increases the right
    // y increases downwards
    background(float x, float y);

    // implement the pure virtual functions
    void update() override;
    void draw(sf::RenderWindow& window) override;
};

#endif     // BACKGROUND_H