#include <iostream>
#include <omp.h>

int main()
{

    int num_threads;
    omp_set_dynamic(0);
    omp_set_num_threads(omp_get_num_procs()); // set to # of processors
#pragma omp parallel
    {
        int id = omp_get_thread_num();
    }
#pragma omp parallel single
    {
        num_threads = omp_get_num_threads();
        // do lots of stuff(id);
    }

    return 0;
}