#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMax(int[], int);
int findMax(vector<int>);

int main()
{
    int a = 4, b = 2, c = 50;
    vector<int> tmp = {a, b, 1000, c};

    int sample[5] = {243, 1000, -4, 150, 40};

    cout << "max is: " << findMax(sample, sizeof(sample) / sizeof(sample[0])) << endl;
    cout << "max vector is: " << findMax({a, b, 1000, c}) << endl;
    //
    cout << "max is: " << *max_element(sample, sample + (sizeof(sample) / sizeof(sample[0]))) << endl;
    cout << "max vector is: " << *max_element(tmp.begin(), tmp.end()) << endl;

    return 0;
}

int findMax(int numbers[], int size)
{
    int max = numbers[0];
    for (int i = 1; i < size; i++)
    {
        if (max < numbers[i])
            max = numbers[i];
    }
    return max;
}

int findMax(vector<int> numbers)
{
    int max = numbers[0];
    for (auto &num : numbers)
        if (max < num)
            max = num;

    return max;
}