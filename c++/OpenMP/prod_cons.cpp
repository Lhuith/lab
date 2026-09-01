#include <iostream>
#include <omp.h>

int main()
{

    double *A, sum, runtime;
    int numthreads, flag = 0, flag_temp;
    A = (double *)malloc(N * sizeof(double));
#pragma omp parallel sections
    {
#pragma omp section
        {
            fill_rand(N, A); // producer : fill array with data
#pragma omp flash
#pragma atomic write
            flag = 1;
#pragma omp flash(flag)
        }
#pragma omp section
        {
            while (1)
            {
#pragma omp flush(flag)
#pragma omp atomic read
                flag_temp = flag;
                if (flag_temp == 1)
                    break;
            }
#pragma omp flush
            sum = Sum_array(N, A); // consumer: sum the array;
        }
    }
    return 0;
}