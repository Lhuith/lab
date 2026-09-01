#include <iostream>
#include <omp.h>

float consume(float b) {}
float big_job(int i) {}
float DOIT() {}
float big_ugly(float b) {}
int main()
{
#pragma omp parallel
    {
        // BARRIER
        int id = omp_get_thread_num();
// A[id] = big_cal1(id);
#pragma omp barrier // every needs to finish here
        // B[id] = big_cal(id)
    }

    float res;
#pragma omp parallel
    {
        float B;
        int i, id, nthrds, niters = 100;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        for (i = id; i < niters; i += nthrds)
            B = big_job(i);
#pragma omp critical // toll gate, 1 thread at a time
        res += consume(B);
    }

    float X;
#pragma omp parallel
    {
        float tmp, B;
        B = DOIT();
        tmp = big_ugly(B);
#pragma omp atomic // toll gate, 1 thread at a time, with some more juice, and could be OS/hardware specific?
        X += tmp;
    }

    return 0;
}