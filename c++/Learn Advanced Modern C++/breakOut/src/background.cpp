#include "background.hpp"

// initialize static data
sf::Texture background::texture;

background::background(float x, float y) : entity() {
    // load the texture
    texture.loadFromFile("../data/img/background.jpg");

    sprite.setTexture(texture);

    // set the initial position and velocity of the background
    // use (x, y) for the initial position of the background
    sprite.setPosition(x, y);
}

// compute the background's new position
void background::update() {
    // nothing to do here
}

void background::draw(sf::RenderWindow& window) {
    // ask the window to draw the sprite for us
    window.draw(sprite);
}
