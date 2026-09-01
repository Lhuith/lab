#ifndef PADDLE_H
#define PADDLE_H

#include "constants.hpp"
#include "entity.hpp"

// a class to represent a paddle
// inherits from moving_entity
// the paddle moves across the bottom of the screen, under the user's control
// when the ball hits the paddle, it will bounce and change its direction
class paddle : public moving_entity {
    // private data and member functions
    static sf::Texture texture;

    // respond to input from the player
    void process_player_input();

   public:
    // interface of the class

    // constructor
    // arguments are the initial coordinates of the centre
    paddle(float x, float y);

    // implement the pure virtual functions
    void update() override;
    void draw(sf::RenderWindow& window) override;

    // moving_entity
    void move_up() noexcept override;
    void move_down() noexcept override;
    void move_left() noexcept override;
    void move_right() noexcept override;
};

#endif     // PADDLE_H