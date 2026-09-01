#include <iostream>

using namespace std;

int main()
{
    string text = "this is a test"; // t r a l a \0

    // for (int i = 0; i < text.length(); i++)
    // {
    //     cout << text[i] << endl;
    // }

    // char ch = text[0];
    // // cout << ch << endl;

    // char characters[] = "12341231231231231231";
    // cout << characters[0] << endl;
    // cout << *(characters) << endl;

    // cout << characters[1] << endl;
    // cout << *(characters + 1) << endl;

    // char *p = characters;
    // cout << p[0] << endl;
    // cout << *(p) << endl;

    // cout << p[1] << endl;
    // cout << *(p + 1) << endl;

    const char *text2 = text.c_str();
    cout << text2 << endl;

    char array[] = "here is text";
    string test = array;
    cout << test << endl;

    const char *a = "this is a test 1234"; // static string can't change values, should always add const
    cout << a << endl;

    char b[] = "this is another test"; // not constant/static and can be changed
    b[0] = 'l';
    cout << b << endl;

    char *const dynamic_array = new char[50]; // add constant to stop mistakes in assigning static strings
    dynamic_array[0] = 'x';                   // but this is fine?
    dynamic_array[1] = '\0';                  // dont forget this either
    // dynamic_array = "lalalala"; // static, cant change values... cant do this at all apparently

    cout
        << dynamic_array << endl;

    delete[] dynamic_array;

    string array_of_strings[5] = {"this is a test in all of the strings"};
    cout << array_of_strings[0] << endl;

    return 0;
}