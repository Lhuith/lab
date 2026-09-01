#include <iostream>

using namespace std;

int sum_pos(int *, int);

int main()
{
    int toSum[] = {1, -2, 3, 0, -4, 5};
    int summed = sum_pos(toSum, sizeof(toSum) / sizeof(toSum[0]));
    cout << summed << endl;
    return 0;
}

int sum_pos(int *s, int size)
{
    int summed = 0;
    for (int i = 0; i < size; i++)
    {
        if (s[i] > 0)
        {
            summed += s[i];
            // cout << s[i] << endl;
        }
    }
    return summed;
}