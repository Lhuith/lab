#ifndef MONADS_H
#define MONADS_H

#include <fplus/fplus.hpp>
#include <iostream>

using namespace std;
using namespace fplus;

namespace monads {

typedef vector<int> Ints;
typedef vector<string> Strings;

result<string, string> get_input_filepath(const Strings& args) {
    assert(args.size() > 0);
    if (args.size() != 2)
        return error<string, string>("usage: " + args[0] + " FILEPATH");
    else
        return ok<string, string>(args[1]);
}

result<string, string> read_file(const string& filepath) {
    const auto maybe_content = read_text_file_maybe(filepath)();

    // ifstream input(filepath);
    // if (!input.good())
    //     return nothing<string>();
    // return just(trim_whitespace(string(
    //     istreambuf_iterator<string::value_type>(input),
    //     istreambuf_iterator<string::value_type>())));

    const auto trimmed = lift_maybe(trim_whitespace<string>, maybe_content);
    return from_maybe(string("unable to open ") + filepath, trimmed);
}

result<Ints, string> parse_content(const string& content) {
    const auto maybe_values = fwd::apply(
        content,
        fwd::split(',', false),
        fwd::transform(read_value<int>));
    if (all_by(is_just<int>, maybe_values))
        return ok<Ints, string>(justs(maybe_values));
    else
        return error<Ints, string>("can not parse file.");
}

result<int, string> calc_median(const Ints& xs) {
    if (is_not_empty(xs))
        return ok<int, string>(median(xs));
    return error<int, string>("need at least one value.");
}

string show_median(int value) {
    return "The median is " + show(value);
}

string show_error(const string& error) {
    return "ERROR: " + error;
}

template <typename Res, typename Error, typename F, typename A>
result<Res, Error> maybe_and_then_result(F f, const result<A, Error>& r) {
    if (is_ok(r))
        return f(unsafe_get_ok(r));
    else
        return error<Res, Error>(r.unsafe_get_error());
}

// // and_then : ((a -> Maybe b), (Maybe a)) -> Maybe b
// template <typename Res, typename F, typename A>
// maybe<Res> and_then(F f, const maybe<A>& m) {
//     if (is_just(m))
//         return f(unsafe_get_just(m));
//     else
//         return nothing<Res>();
// }

int main(int argc, char* argv[]) {
    const Strings arguments(argv, argv + argc);

    const string error_msg = "An error occurred.";

    // auto input_fp = get_input_filepath(arguments);
    // auto content = and_then<string>(read_file, input_fp);
    // auto values = and_then<Ints>(parse_content, content);
    // auto res = and_then<int>(calc_median, values);

    // const auto res = fwd::apply(
    //     arguments,
    //     compose_maybe(
    //         get_input_filepath,
    //         read_file,
    //         parse_content,
    //         calc_median));

    // const auto output = lift_maybe(show_median, res);
    // cout << just_with_default(error_msg, output) << endl;

    const auto input_filepath = get_input_filepath(arguments);
    const auto file_content = maybe_and_then_result<string>(read_file, input_filepath);
    const auto values = maybe_and_then_result<Ints>(parse_content, file_content);
    const auto res = maybe_and_then_result<int>(calc_median, values);

    const auto output = unify_result(show_median, show_error, res);
    cout << output << endl;

    return 0;
}
}     // namespace monads
#endif     // MONADS_H