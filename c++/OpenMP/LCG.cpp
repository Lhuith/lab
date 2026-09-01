#include <iostream>

static long M = 1366;
static long A = 150889;
static long PMOD = 714025;
long random_last = 0;

double LCG_Random()
{
    long random_next;
    random_next = (M * random_last + A) % PMOD;

    random_last = random_next;

    return ((double)random_next / (double)PMOD);
}

int main()
{

    // #pragma omp single
    //     {
    //         int nthreads = omp_get_num_threads();
    //         float iseed = PMOD / MULTIPLIER; // just pick anything
    //         pseed[0] = iseed;
    //         mult_n = MULTIPLIER;

    //         for (int i = 1; i < nthreads; ++i)
    //         {
    //             iseed = (unsigned long long)((MULTIPLIER * iseed) % PMOD);
    //             pseed[i] = iseed;
    //             mult_n = (mult_n * MULTIPLIER) % PMOD;
    //         }
    //     }
    //     random_last = (unsigned long long)pseed[id];

    return 0;

    printf("neat little random %f \n", LCG_Random());
    return 0;
}
