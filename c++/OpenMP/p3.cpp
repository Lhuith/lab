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
    double pi, sum = 0.0;
    step = 1.0 / (double)num_steps;

    double start = omp_get_wtime();
#pragma omp parallel
    {
        double x;
#pragma omp for reduction(+ : sum)
        for (i = 0; i < num_steps; i++)
        {
            x = (i + 0.5) * step;
            sum += 4.0 / (1.0 + x * x);
        }
    }
    pi = sum * step;
    printf("pi value is : %lf, in %lf ms", pi, omp_get_wtime() - start);
    return 0;
}