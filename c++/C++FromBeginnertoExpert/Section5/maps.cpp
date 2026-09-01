#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<float, int> mp;

    mp[1.1] = 1;

    cout << mp[1.1] << endl;
    return 0;
}