#ifndef STREAM_MEMBER_FUNCS_H
#define STREAM_MEMBER_FUNCS_H

#include <fstream>
#include <iostream>
#include <limits>

using namespace std;

namespace streamMemberFuncs {
void validInput() {
    int x{0};

    cout << "please enter a number: ";
    cin >> x;

    bool success{false};
    while (!success) {
        if (cin.good()) {
            cout << "you entered the number " << x << "\n";
            success = true;
        } else if (cin.fail()) {
            cout << "please try again and enter a number \n";
            cin.clear();
            // cin.ignore(cin., '\n'); // remove next 20 characters or anything after newline
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> x;
        }
    }
}

void readIn() {
    ifstream ifile;
    ifile.open("../data/input.txt");

    int x{0};
    while (ifile >> x) {
        cout << x << ", ";
    }
    cout << endl;
}

int main() {
    // int x{0};

    // cout << "please enter a number: ";
    // cin >> x;

    // if (cin.good()) // successfully read in int
    // {
    // 	cout << "you entered the number " << x << "\n";
    // }
    // else if (cin.fail()) // not an int. probably user error
    // {
    // 	cout << "please try again and enter a number\n";
    // }
    // else if (cin.bad()) // a series error occurred
    // {
    // 	cout << "something has gone seroisly wrong\n";
    // }
    // readIn();
    validInput();

    return 0;
}
}     // namespace streamMemberFuncs
#endif     // STREAM_MEMBER_FUNCS_H