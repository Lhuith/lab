#include <iostream>
#include <omp.h>

int main()
{

#pragma omp parallel for
    for (int i = 0; inBuckets; i++)
    {
        omp_init_lock(&hist_locks[i]);
        hist[i] = 0;
    }
#pragma omp parallel for
    for (i = 0; i < inVals; i++)
    {
        ival = (int)sampler(arr[i]);
        omp_set_lock(&hist_locks[ival]);
        hist[ival]++;
        omp_unset_lock(&hist_locks[ival]);
    }

    for (i = 0; i < NBuckets; i++)
    {
        omp_destroy_lock(&hist_locks[i]);
    }

    return 0;
}