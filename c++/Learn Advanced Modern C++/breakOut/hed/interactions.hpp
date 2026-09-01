#ifndef INTERACTIONS_H
#define INTERACTIONS_H

#include "ball.hpp"
#include "brick.hpp"
#include "paddle.hpp"

// determine whether two entities overlap
bool is_interacting(const entity& e1, const entity& e2);

// resolve potential collision between ball and the paddle
void handle_collision(ball& b, const paddle& p);

// resolve potential collision between ball and the brick
void handle_collision(ball& b, brick& br);

#endif     // INTERACTIONS_H