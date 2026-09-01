#include "brick.hpp"

// initialize static data
sf::Texture brick::texture;

// use different colours, depending on the strength of the brick
// format: RGBA
const sf::Color brick_colour_hit1{0, 255, 0, 80};      // dull green
const sf::Color brick_colour_hit2{0, 255, 0, 170};     // medium green
const sf::Color brick_colour_hit3{0, 255, 0, 255};     // bright green

void brick::set_strength(int s) noexcept { strength = s; }
void brick::weaken() noexcept { --strength; }
bool brick::is_too_weak() const noexcept { return strength <= 0; }

// constructors
brick::brick(float x, float y) {
    // load the texture
    texture.loadFromFile("../data/img/brick01.png");
    sprite.setTexture(texture);

    // set the position of the brick
    sprite.setPosition(x, y);

    // by default, operations are relative to the sprites top lh corner
    // make them relative to the sprite's centre
    sprite.setOrigin(get_centre());
}

// compute the brick's new position
void brick::update() {     // nothing to do here
    // change the colour of the brick, depending on how many times it has been hit
    if (strength == 1)
        sprite.setColor(brick_colour_hit1);
    else if (strength == 2)
        sprite.setColor(brick_colour_hit2);
    else if (strength == 3)
        sprite.setColor(brick_colour_hit3);
};

void brick::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}