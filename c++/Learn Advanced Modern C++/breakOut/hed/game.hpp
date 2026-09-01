#ifndef GAME_H
#define GAME_H

#include <memory>
#include <typeinfo>
#include <vector>

#include "background.hpp"
#include "ball.hpp"
#include "brick.hpp"
#include "constants.hpp"
#include "paddle.hpp"

// a class to manage the entities in the game
// it stores the entities in a vector of std::unique_ptr
// the manage can create an entity object and add it to the vector

// example: create a ball object at position (x, y) on the screen
// manager.create<ball>(x,y);

// when an entity is destroyed, the game will mark it as destroyed, but not delete it.
// instead, the manager will scan all entities and clean up the destroyed ones

// the manager can also locate all the objects with a given entity type
// these are stored as alias pointers (non-owning) to the allocated objects
// this is useful for performing an operator on e.g all bricks

// use aliases to simplify the code
using entity_vector = std::vector<std::unique_ptr<entity>>;
using entity_alias_vector = std::vector<entity*>;

class entity_manager {
    // a vector to store all the entities in the game (all bricks objects, background, ball, paddle)
    entity_vector all_entities;

    // a map to store the entities grouped by type
    // we can iterate over this to get a vector of all brick object, then a vector of all ball objects,
    // the vector will contain a non-owning pointers to the objects
    // do not delete these pointers!
    // do not use them after the objects they point to have been destroyed!
    std::map<size_t, entity_alias_vector> grouped_entities;

   public:
    // function to create an entity of the type T using args as the constructor arguments
    // we use a variadic template to pass any number of arguments
    // we use perfect forwarding to avoid any unnecessary copying of the arguments
    template <typename T, typename... Args>
    T& create(Args&&... args) {
        // check that the type parameter is derived from the entity base class
        static_assert(std::is_base_of<entity, T>::value,
                      R"("T" type parameter in create() must be derived from "entity")");

        // create a unique_ptr to the entity
        // forward the arguments to the entity's constructor
        auto ptr{std::make_unique<T>(std::forward<Args>(args)...)};

        // make an alias pointer to the allocated memory
        // this will be stored in the entity_type_vector
        auto ptr_alias = ptr.get();

        // get the hash code for the entity object's type
        auto hash = typeid(T).hash_code();     // guaranteed unique

        // insert the alias pointer to the map
        grouped_entities[hash].emplace_back(ptr_alias);

        // insert the object's pointer into the entities vector
        all_entities.emplace_back(std::move(ptr));

        // return the new object
        return *ptr_alias;
    }

    // function to scan all entities and clean up the destroyed ones
    void refresh();

    // function to destroy all entities
    void clear();

    // function to retrieve all the objects of a given type
    template <typename T>
    auto& get_all() {
        return grouped_entities[typeid(T).hash_code()];
    }

    // apply a function to all entities of a given type
    template <typename T, typename Func>
    void apply_all(const Func& func) {
        auto& entity_group{get_all<T>()};

        for (auto ptr : entity_group)
            func(*dynamic_cast<T*>(ptr));
    }

    // function to update all the entities
    void update();

    // function to make all the entities draw themselves
    void draw(sf::RenderWindow& window);
};

class game {
    // enum with allowed values for the game's state
    enum class game_state { PAUSED,
                            GAME_OVER,
                            RUNNING,
                            PLAYER_WINS };

    // create the game's window using an object of class RenderWindow
    // he constructor takes an SFML 2D vector with the window dimensions
    // and an std::string with the window title
    // the SFML code is in the sf namespace
    sf::RenderWindow game_window{{constants::window_width, constants::window_height},
                                 "Simple Breakout Game Version 9"};

    // instead of embedding every entity in the game class, use an entity_manager
    entity_manager manager;

    // use SFML text and font classes to communicate with the player
    sf::Font verdana;
    sf::Text text_state, text_lives;

    // member to store the current state of the game
    game_state state{game_state::GAME_OVER};

    // how many lives does the player have left?
    int lives{constants::player_lives};

   public:
    game();

    // reinitialize the game
    void reset();

    // game loop
    void run();
};

#endif     // GAME_H