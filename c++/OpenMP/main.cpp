#include <iostream>
#include <omp.h>

using namespace std;

static long num_steps = 100000;
double step;

void pooh(int id, double A[])
{
    printf("doing stuff with %d \n", id);
}
#define NUM_THREADS 32
#define PAD 8 // assume 64 byte L1 cache line size, its a cache hack lawl

int main()
{
    //     double A[1000]; // heap, all threads
    // #pragma omp parallel num_threads(4)
    //     {
    //         // stack
    //         int ID = omp_get_thread_num();
    //         pooh(ID, A);
    //     }
    //     printf("all done \n");

    int i, nthreads;
    double pi, sum[NUM_THREADS][PAD];
    step = 1.0 / (double)num_steps;
    omp_set_num_threads(NUM_THREADS);
    double start = omp_get_wtime();
#pragma omp parallel
    {
        int i, id, nthrds;
        double x;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        if (id == 0)
            nthreads = nthrds;

        for (sum[id][0] = 0.0, i = id; i < num_steps; i = i + nthrds)
        {
            x = (i + 0.5) * step;
            sum[id][0] += 4.0 / (1.0 + x * x);
        }
    }
    for (i = 0, pi = 0.0; i < nthreads; i++)
        pi += sum[i][0] * step;
    printf("pi value is : %lf, in %lf ms", pi, omp_get_wtime() - start);
    return 0;
}