#include "interactions.hpp"

// determine whether two entities overlap
bool is_interacting(const entity& e1, const entity& e2) {
    auto box1 = e1.get_bounding_box();
    auto box2 = e2.get_bounding_box();
    return box1.intersects(box2);
}

// resolve potential collision between ball and the paddle
void handle_collision(ball& b, const paddle& p) {
    if (is_interacting(p, b)) {
        // make ball bounce upwards
        b.move_up();

        // make the new direction depend on where the collision occurs on the paddle
        // if the collision is on t he left of the paddle, make the ball bounce to the ?
        if (b.x() < p.x())
            b.move_left();
        else
            b.move_right();
    }
}

// resolve potential collision between ball and the brick
void handle_collision(ball& b, brick& br) {
    if (is_interacting(br, b)) {
        // update the brick's strength
        br.weaken();

        if (br.is_too_weak()) {
            // the brick is destroyed
            br.destroy();
        }

        // make a new direction depend on where the collision occurs on the brick
        // if the ball collides on the side of the brick, make the ball bounce to the x ?
        // if the ball collides on the top/bottom of the brick, make the ball bounce in the y?

        // first we find the amount of overlap in each direction
        // the smaller the left overlap, the closer the ball is to the left side of the brick
        // and similarly for the other sides of the brick
        float left_overlap = b.right() - br.left();
        float right_overlap = br.right() - b.left();
        float top_overlap = b.bottom() - br.top();
        float bottom_overlap = br.bottom() - b.top();

        // if the left overlap is smaller than the right overlap, ball hit left side
        bool from_left = std::abs(left_overlap) < std::abs(right_overlap);
        bool from_top = std::abs(top_overlap) < std::abs(bottom_overlap);

        // use the right or left overlap as appropriate
        float min_x_overlap = from_left ? left_overlap : right_overlap;
        float min_y_overlap = from_top ? top_overlap : bottom_overlap;

        // if the ball hit the left or right side of the brick change its horizontal direction
        // if the ball hit the top or bottom side of the brick, change its vertical direction
        if (std::abs(min_x_overlap) < std::abs(min_y_overlap)) {
            if (from_left)
                b.move_left();
            else
                b.move_right();
        } else {
            if (from_top)
                b.move_up();
            else
                b.move_down();
        }
    }
}
