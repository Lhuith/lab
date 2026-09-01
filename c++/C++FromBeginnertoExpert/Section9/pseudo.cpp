#include <iostream>

using namespace std;
// pseudo random

void lottery(int, int);

int main()
{
    // srand(time(NULL));        // seed
    // int nr = rand() % 49 + 1; // [1, 49]
    // cout << nr << endl;

    lottery(49, 2);
    return 0;
}

void lottery(int total, int balls_to_draw)
{
    if (total < balls_to_draw)
        return;

    srand(time(NULL)); // seed

    int *balls = new int[balls_to_draw];

    for (int i = 0; i < balls_to_draw; i++)
    {
        balls[i] = rand() % total;

        for (int j = 0; j < i + 1; j++)
        {
            if (balls[i] == balls[j] && i != j)
            {
                i--;
                break;
            }
            else if (j == i)
                cout << balls[i] << endl;
        }

        // cout << balls[i] << endl;
    }

    delete[] balls;
}