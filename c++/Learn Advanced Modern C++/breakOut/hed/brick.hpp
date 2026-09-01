#ifndef BRICK_H
#define BRICK_H

#include "constants.hpp"
#include "entity.hpp"

// class to represent a brick
// inherits from entity
// a grid of bricks is displayed across the top of the screen
// this grid will be represented by an std::vector of brick objects
// when the ball hits a brick, the brick is destroyed and disappears
// when a brick is destroyed, it is deleted from the vector
class brick : public entity {
    // private data members
    static sf::Texture texture;

    // how many times the brick can be hit before destroying it
    int strength{constants::brick_strength};

   public:
    // interface of the class

    // constructors
    brick(float x, float y);

    // helper functions for the brick strength
    void set_strength(int) noexcept;
    void weaken() noexcept;
    bool is_too_weak() const noexcept;

    // implement the pure virtual functions
    void update() override;
    void draw(sf::RenderWindow& window) override;
};

#endif     // BRICK_H