#include <SFML/Graphics.hpp>
#include <random>
#include <string>

#include "constants.hpp"

using namespace std;
using namespace std::literals;

// class to represent the creature moving around the screen
class creature {
    // static random number engine and Bernoulli distribution objects
    static mt19937 mt;
    static bernoulli_distribution bd;

    // define some properties of the creature
    // SFML uses float internally
    float vx{4.0f};
    float vy{4.0f};
    sf::Vector2f velocity;

    // we use the SFML CircleShape
    sf::CircleShape circle;

   public:
    // interface of the class

    // constructor
    // arguments are the initial coordinates of the centre of the ball
    // SFML uses the computer graphics convention
    // (0, 0) is the top left corner the screen
    // x increases to the right
    // y increases downwards
    creature(float x, float y) {
        // set the initial position and velocity
        // use (x, y) for the initial position
        velocity = {vx, vy};
        circle.setPosition(x, y);

        // set the graphical properties
        circle.setRadius(5.0f);
        circle.setFillColor(sf::Color::Red);
    }

    void draw(sf::RenderWindow& window) {
        // ask the window to draw the shape for us
        window.draw(circle);
    }

    // compute the creature's new position
    void update() {
        // change the direction of movement at random
        vx = bd(mt) ? vx : -vx;
        vy = bd(mt) ? vy : -vy;

        // move the creature to its new position
        circle.move({vx, vy});
    }
};

mt19937 creature::mt;
bernoulli_distribution creature::bd;

// the main function for the program
int main() {
    // create a creature object in the middle of the screen
    creature the_creature(constants::window_width / 2.0, constants::window_height / 2.0);

    // create the game's window using an object of class RenderWindow
    // the constructor takes an SFML 2D vector with the window dimensions
    // and and std::string with the window title
    // the SFML code is in the sf namespace
    sf::RenderWindow window{{constants::window_width, constants::window_height}, "Random Walk"};

    // limit the framerate
    // this allows other process's to run and reduces power consumption
    window.setFramerateLimit(60);     // max rate is 60 frames per second

    while (window.isOpen()) {
        // clear the screen
        window.clear(sf::Color::Black);

        // check for any events
        sf::Event event;

        // if the user pressed "escape", or clicked on "close", we close the window
        // this will terminate the program
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            window.close();
            break;
        }

        // calculate the updated graphics
        the_creature.update();

        // display the update graphics
        the_creature.draw(window);
        // buffer data loaded in
        window.display();
        // dump
    }

    return 0;
}