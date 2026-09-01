#ifndef POLYGON_EDGES_H
#define POLYGON_EDGES_H

#include <fplus/fplus.hpp>
#include <iostream>
#include <vector>

typedef std::pair<float, float> point;
typedef std::pair<point, point> edge;

namespace polygonEdges {
float point_distance(const point& p1, const point& p2) {
    const float dx = p2.first - p1.first;
    const float dy = p2.second - p1.second;
    return std::sqrt(dx * dx + dy * dy);
}

float edge_length(const edge& e) {
    return point_distance(e.first, e.second);
}

std::vector<edge> get_edges(const std::vector<point>& polygon) {
    return fplus::overlapping_pairs_cyclic(polygon);
}

const auto str_caps(const char& c) {
    return char(toupper(c));
}

const auto no_punct(const char& c) {
    return (ispunct(c) ? ' ' : c);
}

int main() {
    using namespace std;
    using namespace fplus;

    vector<point> polygon = {{1, 2}, {7, 3}, {6, 5}, {4, 4}, {2, 9}};

    // const auto result = fplus::maximum_on(
    //     edge_length,
    //     get_edges());

    const auto result = fwd::apply(polygon, get_edges, fwd::maximum_on(edge_length));

    std::cout << show(result) << endl;

    std::string test{"hello world! trying to learn funcs!!"};

    const auto toCapsArray =
        fwd::apply(
            test,
            fwd::transform(str_caps),
            fwd::transform(no_punct),
            fwd::split(' ', false),
            fwd::reverse(),
            fwd::sum());

    std::cout << fplus::show(toCapsArray) << std::endl;

    // 2
    int a = 3;

    // intermediate values
    int b = square(a);
    int c = min_2(2, b);
    int d = abs_diff(7, c);
    int e = fplus::clamp(1, 4, d);
    int f = max_2(6, e);
    std::cout << f << std::endl;

    // nested function calls
    int f_nested =
        fplus::max_2(6, fplus::clamp(1, 4, fplus::abs_diff(7, fplus::min_2(2, fplus::square((a))))));
    std::cout << f_nested << std::endl;

    // forward-application style
    int f_fwd =
        fplus::fwd::apply(a,
                          fplus::fwd::square(),
                          fplus::fwd::min_2(2),
                          fplus::fwd::abs_diff(7),
                          fplus::fwd::clamp(1, 4),
                          fplus::fwd::max_2(6));
    std::cout << f_fwd << std::endl;
    return 0;
}
}     // namespace polygonEdges
#endif     // POLYGON_EDGES_H