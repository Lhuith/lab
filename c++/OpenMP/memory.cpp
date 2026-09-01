#include <iostream>
#include <omp.h>

int main()
{
    double A;
    A = compute();
#pragma omp flush(A); // flash A and any R/W to DRAM, syncing ops
    return 0;
}