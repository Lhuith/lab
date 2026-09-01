#include <iostream>
#include <omp.h>

void NEAT_STUFF(int i)
{
    printf("NEAT!: %d \n", i);
}

int main()
{
    omp_set_num_threads(12);
#pragma omp parallel for
    {
        for (int i = 0; i < 1000; i++)
        {
            printf("I am %d \n", omp_get_thread_num());
            NEAT_STUFF(i);
        }
    }
    return 0;
}