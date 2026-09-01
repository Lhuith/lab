#include <iostream>
#include <vector>

using namespace std;

class Book
{
public:
    Book()
    {
        cout << "constructor invoked" << endl;
    }

    Book(const Book &secondBook) { cout << "some copy constructor instructions" << endl; }
    string getInfo()
    {
        return "Hey I'm book!";
    }
};

int main()
{
    // vector<int> wholeNumbers{1, 25, -45, 350};

    vector<Book> wholeNumbers{Book(), Book(), Book(), Book(), Book()};

    /*
        ranged based for loop - loops as long as there are elements within range of container
    */

    // for (auto vi = wholeNumbers.begin(); vi != wholeNumbers.end(); vi++)
    // {
    //     auto nr = *vi;
    //     nr *= 10;
    //     cout << nr << endl;
    // }

    // for (const auto &nr : wholeNumbers) // always use address or you will be making copies for each element
    // {
    //     // nr *= 10;
    //     cout << nr.getInfo() << endl;
    // }

    for (auto nr : wholeNumbers)
    {
        cout << nr.getInfo() << endl;
    }

    return 0;
}