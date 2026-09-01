#include "paddle.hpp"

// initialize static data
sf::Texture paddle::texture;

paddle::paddle(float x, float y) : moving_entity() {
    // load the texture
    texture.loadFromFile("../data/img/paddle.png");
    sprite.setTexture(texture);

    // set the initial position and velocity of the paddle
    sprite.setPosition(x, y);

    // set the velocity of the paddle
    velocity = {constants::paddle_speed, 0.0};     // the paddle can only move sideways

    // by default, operations are relative to the sprites top lh corner
    // make them relative to the sprites centre
    sprite.setOrigin(get_centre());
}

void paddle::move_down() noexcept {};

void paddle::move_up() noexcept {}

void paddle::move_left() noexcept {
    velocity.x = -constants::paddle_speed;
}

void paddle::move_right() noexcept {
    velocity.x = constants::paddle_speed;
}

// response to input from the player
// if the player presses the left arrow key, move to the left (negative velocity)
// if the player presses the right arrow key, move to the right (positive velocity)
// otherwise, do not move(zero velocity)
// do not allow the paddle to move off the screen
void paddle::process_player_input() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        // left arrow key pressed - move to the left
        // unless the paddle has gone past the left hand side
        if (x() >= 0)
            move_left();
        else
            velocity.x = 0;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        // similarly or the right arrow
        if (x() <= constants::window_width)
            move_right();
        else
            velocity.x = 0;
    } else {
        // some other key pressed, or not key at all
        velocity.x = 0;
    }
}

// compute the paddle's new position
void paddle::update() {
    process_player_input();

    // move the position of the paddle
    sprite.move(velocity);
}

void paddle::draw(sf::RenderWindow& window) {
    // ask the window to draw sprite for us
    window.draw(sprite);
}