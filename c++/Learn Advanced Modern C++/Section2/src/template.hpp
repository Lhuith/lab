#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <iostream>
using namespace std;

namespace templates
{

    void CTAD()
    {
        // vector<int> vec{1, 2, 3};    //c++11 declared as vector<int>
        vector vec{1, 2, 3}; // c++17 deduced as vector<int>

        cout << "vec = ";
        for (const auto &it : vec)
            cout << it << ", ";
    }

    // function template for finding maximum of 2 values
    template <typename T>           // T is the parameter type
    T Max(const T &t1, const T &t2) // the arguments and return value ???
    {
        if (t1 > t2)
            return t1;
        return t2;
    }

    int main()
    {
        cout << Max(6.2, 2.1) << endl; // expands template to:

        /*
            double Max(const double& t1, const double& t2) {   // arguments and return value have this type
                if(t1 > t2)
                    return t1;
                return t2;
            }

        */

        CTAD();
        return 0;
    }
}

#endif // TEMPLATE_H