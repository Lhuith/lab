#ifndef ASS_1_H
#define ASS_1_H

#include <string>
#include <iostream>

using namespace std;

class url
{
    string protocol;
    string resource;
    const string separator = "://";

public:
    url(const string &p, const string &r) : protocol(p), resource(r) {} // dont forget ref pass to avoid copying
    ~url() {}

    const string print() { return protocol + separator + resource; }
};

namespace assignment1
{
    int main()
    {
        cout << url{"http", "www.example.com/index.html"}.print() << endl;
        return 0;
    }
}

#endif // ASS_1_H