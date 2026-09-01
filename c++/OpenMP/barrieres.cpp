#include <iostream>
#include <omp.h>

int main()
{

#pragma omp parallel shared(A, B, C) private(id) // shared(A, B, C) >>
    {
        // id
        // big calc
#pragma omp barrier // explicit, everyone wait
#pragma omp for
        {
            for (int i = 0; i < 10; i++)
            {
            }
            // implied barrier
        }
#pragma omp for nowait // implicit barrier, theres an  barrier here, add "nowait" to skip it
    }

#pragma omp parallel
    {
// do things
#pragma omp parallel master // only first thread does this
        {
            // do master stuff
        }
    }
#pragma omp parallel barrier // explicit barrier
    // do non master stuff

#pragma omp parallel
    {
    // do thread stuff
#pragma omp parallel single // first thread do
        {
            // single thread stuff
        }
    // implied barrier
    // do all the things
#pragma omp parallel single nowait // first thread do
        {
            // single thread stuff
        }
        // do all the things
    }

#pragma omp parallel
    {
#pragma omp parallel sections // plural
        {
#pragma omp parallel section
            // A
#pragma omp parallel section
            // B
        }
    }
}
