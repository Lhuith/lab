#ifndef STREAM_MANIPULATE_FORMAT_H
#define STREAM_MANIPULATE_FORMAT_H

#include <iomanip>
#include <iostream>
using namespace std;

namespace streamManipulateFormat {
void manip() {
    cout << setfill('#');
    cout << left << setw(15) << "Penguins" << 5 << "\n";
    cout << setw(15) << "Polar Bears" << 2 << "\n";
    cout << right;
    cout << setfill(' ');
    cout << setw(15) << "Hippopotamuses" << 11 << "\n";
}
int main() {
    // int x = 2;
    // bool is_negative = x < 0;

    // cout << "the value of is_negative is " << is_negative << endl;
    // cout << "is_negative is " << boolalpha << is_negative << endl;
    // cout << "x == 2 is " << (x == 2) << endl; // sticky (as it alters stream state) manipulator, the stream will now return true/false until noboolalpha is called/used instream
    // cout << "the numerical value of \"false\" is " << noboolalpha << false << endl;

    manip();
    return 0;
}
}     // namespace streamManipulateFormat
#endif     // STREAM_MANIPULATE_FORMAT_H