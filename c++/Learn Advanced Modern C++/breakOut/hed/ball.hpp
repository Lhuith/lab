#ifndef BALL_H
#define BALL_H

#include "constants.hpp"
#include "entity.hpp"

// class to represent the bouncing ball
// inherits from moving_entity
class ball : public moving_entity {
    // private data members
    static sf::Texture texture;

   public:
    // interface of the class

    // constructor
    // arguments are the initial coordinates of the centre
    // SFML uses the computer graphics convention
    // (0, 0) is the top left corner of the screen
    // x increases to the right
    // y increases downwards
    ball(float x, float y);

    // implement the pure virtual functions
    void update() override;
    void draw(sf::RenderWindow& window) override;

    // moving_entity
    void move_up() noexcept override;
    void move_down() noexcept override;
    void move_left() noexcept override;
    void move_right() noexcept override;
};

#endif     // BALL_H