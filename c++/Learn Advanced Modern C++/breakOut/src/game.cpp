#include "game.hpp"

#include "interactions.hpp"

// function to scan all the entities and clean up the destroyed ones
void entity_manager::refresh() {
    // we must clean up the alias pointers first, to avoid dangling pointers
    // we simply remove them from their vector
    for (auto& [type, alias_vector] : grouped_entities) {
        // remove_if takes an iterator range and a predicate
        // all the elements for which the predicate is true are moved to the back
        // it returns an iterator to the first moved element
        // erase takes an iterator range and deletes all the elements in the range
        alias_vector.erase(remove_if(begin(alias_vector), end(alias_vector),
                                     [](auto p) { return p->is_destroyed(); }),
                           end(alias_vector));
    }

    // now we can safely destroy the objects, now that there are no aliases to them
    all_entities.erase(remove_if(begin(all_entities), end(all_entities),
                                 [](const auto& p) { return p->is_destroyed(); }),
                       end(all_entities));
}

// function to destroy all the entities
void entity_manager::clear() {
    // again, we must clear the alias pointers first
    grouped_entities.clear();
    all_entities.clear();
}

// function to update all the entities
void entity_manager::update() {
    for (auto& e : all_entities)
        e->update();
}

// function to update make all the entities draw themselves
void entity_manager::draw(sf::RenderWindow& window) {
    for (auto& e : all_entities)
        e->draw(window);
}

game::game() {
    // limit the framerate
    game_window.setFramerateLimit(60);     // max rate is 60 frames

    // load a font from file
    // verdana.loadFromFile("/usr/local/share/fonts/webfonts/verdana.ttf");
    verdana.loadFromFile("../data/font/Verdana.ttf");

    // configure our text objects
    text_state.setFont(verdana);
    text_state.setPosition(constants::window_width / 2.0f - 100.0f, constants::window_height / 2.0f - 100.0f);
    text_state.setCharacterSize(35);
    text_state.setFillColor(sf::Color::White);
    text_state.setString("Paused");

    text_lives.setFont(verdana);
    text_lives.setPosition(constants::window_width / 2.0f - 65.0f, constants::window_height / 2.0f - 50.0f);
    text_lives.setCharacterSize(35);
    text_lives.setFillColor(sf::Color::White);
    text_lives.setString("Lives: " + std::to_string(lives));
}

void game::reset() {
    // Reset the number of lives
    lives = constants::player_lives;

    state = game_state::PAUSED;

    // destroy all the entities and re-create them
    manager.clear();

    manager.create<background>(0.0f, 0.0f);
    manager.create<ball>(constants::window_width / 2.0f, constants::window_height / 2.0f);
    manager.create<paddle>(constants::window_width / 2.0f, constants::window_height - constants::paddle_height);

    for (int i = 0; i < constants::brick_columns; ++i) {
        for (int j = 0; j < constants::brick_rows; ++j) {
            // calculate the brick's position
            float x = constants::brick_offset + (i + 1) * constants::brick_width;
            float y = (j + 1) * constants::brick_height;

            // create the brick object
            manager.create<brick>(x, y);
        }
    }

    // limit the framerate
    game_window.setFramerateLimit(60);     // max rate is 60 frames
}

// game loop
void game::run() {
    // was the pause key pressed in the last frame?
    bool pause_key_active{false};

    while (game_window.isOpen()) {
        // clear the screen
        game_window.clear(sf::Color::Black);

        // check for any events since the last loop iteration
        sf::Event event;

        // if the user pressed "escape", or clicked on "close", we close the window
        // this will terminate the program
        while (game_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                game_window.close();
        }

        // check for user input
        // if the user presses "escape", we jump out of the loop
        // this will terminate the program
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            break;

        // if the user press's "P", we pause/unpause the game
        // to prevent repeated use, we ignore it if it was pressed on the last iteration
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)) {
            // if it was not pressed on the last iteration, toggle the status
            if (!pause_key_active) {
                if (state == game_state::PAUSED)
                    state = game_state::RUNNING;
                else
                    state = game_state::PAUSED;
            }
            pause_key_active = true;
        } else
            pause_key_active = false;

        // if the user presses "R", we reset the game
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
            reset();

        // if the game is not running, the entities are not updated
        // they are redrawn only if the game is paused
        if (state == game_state::PAUSED)
            manager.draw(game_window);

        // chose the correct text for the state of the game
        if (state != game_state::RUNNING) {
            switch (state) {
                case game_state::PAUSED:
                    text_state.setString("  Paused    ");
                    break;
                case game_state::GAME_OVER:
                    text_state.setString(" Game over! ");
                    break;
                case game_state::PLAYER_WINS:
                    text_state.setString("Player Wins!");
                    break;
                default:
                    break;
            }

            game_window.draw(text_state);
            game_window.draw(text_lives);
        } else {
            // if there are no remaining balls on the screen
            if (manager.get_all<ball>().empty()) {
                // spawn a new one and reduce the player's remaining lives
                manager.create<ball>(constants::window_width / 2.0f, constants::window_height / 2.0f);
                --lives;

                state = game_state::PAUSED;
            }

            // if there are no remaining bricks on the screen, the player has won!
            if (manager.get_all<brick>().empty())
                state = game_state::PLAYER_WINS;

            // if the player has used up all their lives, the game is over
            if (lives <= 0)
                state = game_state::GAME_OVER;

            // update the text for the number of remaining lives
            text_lives.setString("Lives: " + std::to_string(lives));

            // calculate the updates graphics
            manager.update();

            // for every ball, call a function which
            //  for every brick, call a function which
            //   calls handle_collision with the ball and the brick as arguments
            manager.apply_all<ball>([this](auto& the_ball) {
                manager.apply_all<brick>([&the_ball](auto& the_brick) {
                    handle_collision(the_ball, the_brick);
                });
            });

            // paddle interaction
            manager.apply_all<ball>([this](auto& the_ball) {
                manager.apply_all<paddle>([&the_ball](auto& the_paddle) {
                    handle_collision(the_ball, the_paddle);
                });
            });

            manager.refresh();

            // display the updated graphics
            manager.draw(game_window);
        }

        game_window.display();
        // // in the paused state, the entities are not updated, only redrawn
        // if (state != game_state::PAUSED) {
        //

        // }

        // manager.draw(game_window);
        //
    }
}