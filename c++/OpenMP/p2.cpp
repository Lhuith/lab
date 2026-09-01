#include <iostream>
#include <omp.h>

using namespace std;

static long num_steps = 100000;
double step;

void pooh(int id, double A[])
{
    printf("doing stuff with %d \n", id);
}
#define NUM_THREADS 4

int main()
{
    int i, nthreads;
    double pi;
    step = 1.0 / (double)num_steps;
    omp_set_num_threads(NUM_THREADS);
    double start = omp_get_wtime();
#pragma omp parallel
    {
        int i, id, nthrds;
        double sum, x;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        if (id == 0)
            nthreads = nthrds;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        for (sum = 0.0, i = id; i < num_steps; i = i + nthrds)
        {
            x = (i + 0.5) * step;
            sum += 4.0 / (1.0 + x * x);
        }
#pragma omp critical
        pi += sum * step;
    }

    printf("pi value is : %lf, in %lf ms", pi, omp_get_wtime() - start);
    return 0;
}