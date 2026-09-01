#ifndef STRING_LIT_H
#define STRING_LIT_H

#include <iostream>
using namespace std;

namespace stringLit
{

    void rawStrings()
    {
        // string literal with escaped characters
        string url = "<a href=\"file\">C:\\\"Program Files\"\\</a>\\n";
        cout << "URL is " << url << endl
             << endl;

        // Raw string literal with unescaped characters
        string raw_url = R"(<a href="file">C:\"Program Files"\</a>\n)";
        cout << "Raw URL is " << raw_url << endl
             << endl;

        // Raw string literal with delimeter x
        string delimited_url = R"x(<a href="file">C:\"Program Files (x86)"\</a>\n)x";
        cout << "Delimited URL is " << delimited_url << endl
             << endl;
    }

    int main()
    {
        // const char *cca = "Hello, world!";
        // cout << "cca: " << cca << endl;

        // string str = "Hello, world!"s;
        // cout << "str: " << str << endl;

        // cout << "std::string literal: " << "Hello"s + ", world!"s << endl;
        rawStrings();

        return 0;
    }
}

#endif // STRING_LIT_H