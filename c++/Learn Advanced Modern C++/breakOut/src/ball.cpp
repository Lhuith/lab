#include "ball.hpp"

// initialize static data
sf::Texture ball::texture;

ball::ball(float x, float y) : moving_entity() {
    // load the texture
    texture.loadFromFile("../data/img/ball.png");
    sprite.setTexture(texture);

    // set the initial position and velocity of the ball
    // use (x, y) for the initial position of the ball
    sprite.setPosition(x, y);
    velocity = {constants::ball_speed, constants::ball_speed};

    sprite.setOrigin(get_centre());
}

// compute the ball's new position
void ball::update() {
    // move the position of the ball
    sprite.move(velocity);

    // we check if the ball has moved off the left hand side of the window
    // if so, we change sign of the x-component of the velocity
    // this will make it move at the same speed, but to the right
    // the ball will appear to bounce back into the window
    if (x() < 0)
        velocity.x = -velocity.x;
    if (x() > constants::window_width)
        velocity.x = -velocity.x;

    // we can also do this for the top and bottom of the screen
    if (y() < 0)
        velocity.y = -velocity.y;
    if (y() > constants::window_height)
        destroy();
    // velocity.y = -velocity.y;
}

void ball::draw(sf::RenderWindow& window) {
    // ask the window to draw sprite for us
    window.draw(sprite);
}

void ball::move_up() noexcept {
    velocity.y = -constants::ball_speed;
}

void ball::move_down() noexcept {
    velocity.y = constants::ball_speed;
};

void ball::move_left() noexcept {
    velocity.x = -constants::ball_speed;
}

void ball::move_right() noexcept {
    velocity.x = constants::ball_speed;
}
