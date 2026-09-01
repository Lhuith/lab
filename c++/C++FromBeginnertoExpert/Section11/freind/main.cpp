#include <iostream>
#include "test.hpp"

using namespace std;

int main()
{
    B b;
    A a;

    a.setSecret(b, 1000);

    cout << b.getSecret() << endl;

    return 0;
}