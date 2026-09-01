#ifndef SQL_ANALOGY_H
#define SQL_ANALOGY_H

#include <fplus/fplus.hpp>
#include <iostream>
#include <vector>

namespace sqlAnalogy {

struct user {
    std::string name;
    std::string country;
    std::size_t visits;
};

std::string get_country(const user& u) {
    return u.country;
}

std::size_t get_visits(const user& u) {
    return u.visits;
}

int main() {
    const std::vector<user> users = {
        {"Nicole", "GER", 2},
        {"Justin", "USA", 1},
        {"Rachel", "USA", 5},
        {"Robert", "USA", 6},
        {"Stefan", "GER", 4},
    };
    // SELECT country, SUM(visits)
    // from users
    // GROUP BY country

    const auto visit_sum = [](const std::vector<user>& xs) -> std::size_t {
        return fplus::fwd::apply(xs,
                                 fplus::fwd::transform(get_visits),
                                 fplus::fwd::sum());
    };

    std::cout << fplus::show(visit_sum(users)) << std::endl;

    // n^2
    const auto result = fplus::fwd::apply(
        users,
        fplus::fwd::group_globally_on_labeled(get_country),
        fplus::fwd::transform(fplus::fwd::transform_snd(visit_sum)));
    std::cout << fplus::show_cont(result) << std::endl;

    // n * log(n)
    const auto result_n_log_n = fplus::fwd::apply(
        users,
        fplus::fwd::sort_on(get_country),
        fplus::fwd::group_globally_on_labeled(get_country),
        fplus::fwd::transform(fplus::fwd::transform_snd(visit_sum)));
    std::cout << fplus::show_cont(result_n_log_n) << std::endl;

    return 0;
}
}     // namespace sqlAnalogy
#endif     // SQL_ANALOGY_H