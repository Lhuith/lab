#ifndef CONSTANTS_H
#define CONSTANTS_H

// code for a "breakout" game
// based on a talk by Vittorio Romeo
// uses the SFML graphics library

struct constants {
    static constexpr int window_width{520};
    static constexpr int window_height{450};
    // ball stuff
    static constexpr float ball_speed{6.0f};
    // paddle stuff
    static constexpr float paddle_width{60.0f};
    static constexpr float paddle_height{20.0f};
    static constexpr float paddle_speed{8.0f};
    // brick stuff
    static constexpr float brick_width{43.0f};
    static constexpr float brick_height{20.0f};
    static constexpr float brick_offset{brick_width / 2.0f};
    static constexpr int brick_strength{3};     // how many times a brick can be hit
    static constexpr float brick_columns{10};
    static constexpr float brick_rows{4};

    // player
    static constexpr int player_lives{3};     // how many lives a player has to start with
};

#endif     // CONSTANTS_H