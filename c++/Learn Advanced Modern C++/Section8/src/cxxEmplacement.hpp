#ifndef CXX_EMPLACEMENT_H
#define CXX_EMPLACEMENT_H

#include <iostream>
#include <map>
#include <vector>

using namespace std;

namespace cxxEmplacement {
class refrigerator {
    // data member
    int temperature;
    bool door_open;
    bool power_on;

   public:
    refrigerator(int temp, bool open, bool power) : temperature(temp), door_open(open), power_on() {}
    void print() {
        cout << "temperature = " << temperature;
        cout << boolalpha;
        cout << ", door_open = " << door_open;
        cout << ", power_on = " << power_on;
        cout << noboolalpha;
    }
};

void emplace_map() {
    map<string, refrigerator> fridges;

    refrigerator meat_fridge(2, false, true);                  // create refrigerator object
    fridges.insert_or_assign("Meat fridge"s, meat_fridge);     // add an element copy fridge into it

    fridges.insert_or_assign("Dairy fridge"s, refrigerator(3, false, true));

    auto [iter, success] = fridges.try_emplace("Not in use"s, 5, false, false);

    if (success)
        cout << "inserted the new element\n";
    else {
        auto [name, fridge] = *iter;     // get the members of the element pair
        cout << "insert failed: ";
        cout << "existing element with name " << name << " and ???";
        fridge.print();
        cout << "\n";
    }

    for (auto el : fridges) {
        cout << el.first << ", ";
        el.second.print();
        cout << "\n";
    }
}

int main() {
    // vector<refrigerator> vec;

    // refrigerator fridge(2, false, false);     // create a refrigerator object
    //                                           // vec.insert(begin(vec), fridge);           // add an element and copy fridge into it
    // vec.push_back(fridge);

    // // vec.insert(end(vec), refrigerator(3, false, true));
    // vec.push_back(refrigerator(3, false, true));

    // // vec.emplace(end(vec), 5, false, false);     // add an element and create an object in it
    // vec.emplace_back(5, false, false);

    // cout << "vector elements:\n";
    // for (auto el : vec) {
    //     el.print();
    //     cout << "\n";
    // }
    emplace_map();

    return 0;
}
}     // namespace cxxEmplacement
#endif     // CXX_EMPLACEMENT_H