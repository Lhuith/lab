#ifndef STRING_STREAMS_H
#define STRING_STREAMS_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

namespace stringStreams {
void inputStringStream() {
    ifstream infile{"../data/data.txt"};

    if (!infile) {
        cout << "couldn't read file \n";
        return;
    }

    string line;
    vector<int> numbers;

    while (getline(infile, line)) {
        // validate etc
        istringstream is(line);
        int num;
        while (is >> num) {
            numbers.push_back(num);
        }
    }

    double sum{0.0};
    for (auto n : numbers) {
        cout << n << endl;
        sum += n;
    }
    cout << "average is " << sum / numbers.size() << endl;
}

void ostring() {
    ostringstream ostr;
    string text;

    cout << "please enter a world\n";
    cin >> text;                  // read some data
    ostr << setw(16) << text;     // start build up the output
    cout << "please enter another word\n";
    cin >> text;     // read more data and add it to output
    ostr << setw(12) << text;

    // call str() to access the output string
    cout << ostr.str() << endl;     // display output string
}

template <typename T>
string To_String(const T &t) {
    ostringstream os;
    os << t;
    return os.str();
}

int main() {
    // string hello{"hello, "};
    // string pi{To_String(3.14159)};
    // hello += pi;
    // cout << hello << endl;

    // ostring();
    inputStringStream();
    return 0;
}
}     // namespace stringStreams
#endif     // STRING_STREAMS_H