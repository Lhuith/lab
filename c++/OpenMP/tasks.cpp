#include <iostream>
#include <omp.h>

int main()
{

#pragma omp parallel
    {
#pragma omp task
        foo();
#pragma omp barrier
#pragma omp single
        {
#pragma omp task
            bar();
        }
    }

    list ml;
    Element *e
#pragma omp parallel
#pragma omp single
    {
        for (e = ml->first; e; e = e->next)
#pragma omp task firstprivate(e)
            process(e);
    }

    return 0;

// linked list
#pragma omp parallel
    {
#pragma omp single
        {
            node *p = head;
            while (p)
            {
#pragma omp task firstprivate(p)
                process(p);
                p = p->next;
            }
        }
    }
}

int fib(int n)
{
    int x, y;
    if (n < 2)
        return n;

#pragma omp task shared(x)
    x = fib(n - 1);
#pragma omp task shared(y)
    y = fib(n - 2);
#pragma omp taskwait
    return x + y;
}