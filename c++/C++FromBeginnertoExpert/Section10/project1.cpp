#include <iostream>
#include <cstring>

using namespace std;

void showHelp();

int main(int argc, char *argv[])
{
    // arguments counter -arg c
    // argument values - arg v
    // cout << argc << endl;

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-h") == 0)
        {
            showHelp();
        }
        else
        {
            cout << "unrecognised option |> "
                 << "\"" << argv[i] << "\"" << endl;
        }
    }

    // char a[] = {'a', 'b', 'c', 'd', '\0'};
    // char const *b = "this is a test";
    // char const *c[] = {"asdasd", "test", "another test"};

    // // cout << c[2] << endl;

    // char x[] = "a"; // name of array is pointer!!! its an address!!
    // char y[] = "b";

    // cout << (x == y) << endl;
    // cout << (&x[0] == &y[0]) << endl;

    // string a1 = "lalala";
    // string a2 = "lalala";
    // cout << (a1 == a2) << endl;

    // cout << (strcmp(x, y)) << endl; // 0 - same, 1 first string greater, -1 second string greater

    return 0;
}

void showHelp()
{
    // instructions
    cout << "helpful list of things you can do with this app" << endl;
}