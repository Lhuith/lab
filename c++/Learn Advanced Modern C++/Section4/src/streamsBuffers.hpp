#ifndef STREAMS_BUFFERS_H
#define STREAMS_BUFFERS_H

#include <fstream>
#include <iostream>

using namespace std;

namespace streamsBuffers {
int main() {
    ofstream ofile{"../data/log.txt"};

    if (!ofile) {
        cout << "couldn't not open file\n";
        return -1;
    }

    for (int i = 0; i < 1'000'000; ++i) {
        cout << i << endl;
        ofile << i << endl;

        if (i == 66666) {
            terminate();
        }
    }

    ofile.close();

    return 0;
}
}     // namespace streamsBuffers
#endif     // STREAMS_BUFFERS_H