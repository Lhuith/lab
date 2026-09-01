#ifndef FILE_STREAMS_H
#define FILE_STREAMS_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace fileStreams {

void write() {
    ofstream ofile{"../data/text_out.txt"};     // define ofile as an ofstream variable bound to text_out.txt

    if (ofile) {
        vector<string> words = {"The",
                                "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
        for (auto word : words)
            ofile << word << ", ";

        ofile.close();     // release the binding between ofile and text_out.txt
    }
}
void read2() {
    ifstream ifile{"../data/text.txt"};     // define ifile as an ifstream variable bound to text.txt

    if (ifile) {
        string text{""};
        while (getline(ifile, text))     // read a word from the file
            cout << text << endl;

        ifile.close();
    }
}

int main() {
    // ifstream ifile{"../data/text.txt"}; // define ifile as an ifstream variable bound to text.txt

    // if (ifile)
    // {
    // 	string text{""};
    // 	while (ifile >> text) // read a word from the file
    // 		cout << text << ", ";
    // 	cout << "\n";
    // 	ifile.close(); // release the binding between ifile and text.txt
    // }
    // else
    // 	cout << "no dice\n";

    read2();
    write();

    return 0;
}
}     // namespace fileStreams
#endif     // FILE_STREAMS_H