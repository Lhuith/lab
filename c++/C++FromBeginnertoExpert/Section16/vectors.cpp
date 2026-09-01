#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> wholeNumbers;

    wholeNumbers.push_back(1);
    wholeNumbers.push_back(25);
    wholeNumbers.push_back(-45);
    wholeNumbers.push_back(350);

    cout << wholeNumbers.at(0) << endl;
    cout << wholeNumbers[1] << endl;
    cout << wholeNumbers[2] << endl;
    cout << wholeNumbers[3] << endl;

    wholeNumbers.push_back(124123);
    wholeNumbers.push_back(124123);
    wholeNumbers.push_back(124123);
    wholeNumbers.push_back(124123);
    wholeNumbers.push_back(124123);
    cout << "size: " << wholeNumbers.size() << endl;
    cout << "capacity: " << wholeNumbers.capacity() << endl;

    wholeNumbers[2] = 500;
    cout << wholeNumbers[2] << endl;

    // wholeNumbers.insert(3, 500) iterator
    // wholeNumbers.erase() iterator

    return 0;
}