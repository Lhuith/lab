#ifndef SEARCH_STRING_H
#define SEARCH_STRING_H

#include <iostream>
using namespace std;

namespace searchString
{
    void firstAndLast()
    {
        string str{"Hello world"};
        cout << "String to search: " << str << endl;

        string vowels{"aeiou"};
        cout << "first vowel is at index " << str.find_first_of(vowels) << endl;
        cout << "last vowel is at index " << str.find_last_of(vowels) << endl;
        cout << "first non-vowel is at index " << str.find_first_not_of(vowels) << endl;
        cout << "last non-vowel is at index " << str.find_last_not_of(vowels) << endl;
    }

    void rIndexReplace()
    {
        string str{"Hello world"};
        cout << "init contents of str: " << str << endl;

        size_t pos = str.rfind('o');

        if (pos != string::npos)
        {
            str[pos] = 'p';
        }
        else
        {
            cout << "couldn't find the search string \n";
        }

        cout << "final contents of str: " << str << endl;
    }

    void indexReplace()
    {
        string str{"Hello world"};
        cout << "init contents of str: " << str << endl;

        size_t pos = str.find('o');

        if (pos != string::npos)
        {
            str[pos] = 'p';
        }
        else
        {
            cout << "couldn't find the search string \n";
        }

        cout << "final contents of str: " << str << endl;
    }

    int main()
    {
        // string str{"Hello world"};
        // cout << "string to search: " << str << endl;

        // if (size_t pos = str.find('o'); pos != string::npos)
        // {
        //     cout << R"(first occurrence of 'o' is at index )" << pos << endl;
        // }
        // else
        // {
        //     cout << R"(couldn't find 'o' in the string)" << endl;
        // }

        // if (size_t pos = str.find("or"); pos != string::npos)
        // {
        //     cout << R"(first occurrence of "or" is at index )" << pos << endl;
        // }
        // else
        // {
        //     cout << R"(couldn't find "or" in the string)" << endl;
        // }

        // if (size_t pos = str.find('O'); pos != string::npos)
        // {
        //     cout << R"(first occurrence of 'O' is at index )" << pos << endl;
        // }
        // else
        // {
        //     cout << R"(couldn't find 'O' in the string)" << endl;
        // }

        // indexReplace();
        // rIndexReplace();
        firstAndLast();
        return 0;
    }
}

#endif // SEARCH_STRING_H