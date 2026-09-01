#include <iostream>
#include <omp.h>

int counter = 0;
#pragma omp threadprivate(counter)

int increment_counter()
{
    counter++;
    return (counter);
}

int main()
{

    return 0;
}