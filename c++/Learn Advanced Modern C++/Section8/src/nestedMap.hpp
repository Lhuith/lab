#ifndef NESTED_MAP_H
#define NESTED_MAP_H

#include <iostream>
#include <map>

using namespace std;

namespace nestedMap {

using level_map = map<int, string>;
// typedef map<int, string> level_map;	// before c++11

void print(const map<int, level_map>& game_map) {
    cout << "game map" << endl;
    for (auto level : game_map) {
        cout << "level number " << level.first << " map: " << endl;
        for (auto elem : level.second) {
            cout << elem.first << ", " << elem.second << endl;
        }
    }
    cout << endl;
}

int main() {
    level_map level_one_map = {
        {1, "player"},     // element with key 1
        {10, "door"}};     // element with key 10
    level_map level_two_map = {
        // create another level map
        {5, "player"},
        {10, "monster"}};

    // game map
    map<int, level_map> game_map = {
        {1, level_one_map},     // element with key 1
        {2, level_two_map}      // element with key 2
    };

    print(game_map);

    cout << "inserting a new entity into level 2\n";
    auto level2 = game_map.find(2);     // iterator to the level 2 element

    if (level2 != end(game_map))
        level2->second.insert({3, "magic wand"});     // add another object to the level 2 map

    print(game_map);

    cout << "inserting a new level\n";
    level_map level_three_map = {
        // create another level map
        {7, "player"},
        {8, "bomb"}};

    game_map.insert({3, level_three_map});     // add the level map to the game map

    print(game_map);

    cout << "removing element with key 10 from level 2\n";

    auto& lmap = level2->second;
    auto ten = lmap.find(10);
    if (ten != end(lmap))
        lmap.erase(ten);

    print(game_map);

    /*
        for(auto [l_no, l_map] : game_map)
            cout << "level " << l_no << " map: " << endl;
                        for(auto [position, object]:l_map)
                                cout << "position = " << position << ", object = " << object << endl;
    */

    return 0;
}
}     // namespace nestedMap
#endif     // NESTED_MAP_H