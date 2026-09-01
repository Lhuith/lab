#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

// Abstract base class to represent any graphical entity on the screen
class entity {
   protected:
    sf::Sprite sprite;

    // boolean member tracks the entity's status
    bool destroyed{false};

   public:
    // pure virtual functions
    // concrete graphical entities must implement these functions
    // the update member function will compute the new position, appearance etc of?
    // the draw member function will cause the updated object to be displayed in the ?
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

    // helper function to get the bounding box of a sprite
    sf::FloatRect get_bounding_box() const noexcept;

    // helper function to get the centre of a sprite
    sf::Vector2f get_centre() const noexcept;

    // helper functions to get the position of the sprite
    float x() const noexcept;
    float y() const noexcept;

    // helper functions to  get the edges of the sprite
    float left() const noexcept;
    float right() const noexcept;
    float top() const noexcept;
    float bottom() const noexcept;

    // helper functions for the state of the entity
    void destroy() noexcept;
    bool is_destroyed() const noexcept;

    // virtual destructor
    virtual ~entity() {}
};

// abstract base class to represent graphical entities which can move around the screen
class moving_entity : public entity {
   protected:
    // SFML vector to store the object's velocity
    // this is the distance the ball moves between screen updates
    sf::Vector2f velocity;

   public:
    // helper functions inherited from parent class
    // float x();
    // float y();

    // helper functions to change the sprites direction
    virtual void move_up() noexcept = 0;
    virtual void move_down() noexcept = 0;
    virtual void move_left() noexcept = 0;
    virtual void move_right() noexcept = 0;

    // pure virtual functions inherited from parent class
    // virtual void update() = 0;
    // virtual void draw(sf::RenderWindow& window) = 0;
    // etc;
};

#endif     // ENTITY_H