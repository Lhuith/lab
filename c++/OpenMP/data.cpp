#include <iostream>
#include <omp.h>

void wrong()
{
    int temp = 0;
#pragma omp parallel for private(tmp) // tmp isn't initted
                                      // private variable for each thread
    for (, , )
    {
        tmp += j;
    }
    printf("stuff");

    int incr = 0;
#pragma omp parallel for firstprivate(incr) // incer is innited by above value
                                            // private variable for each thread
    for (, , )
    {
    }
    printf("stuff");
}

void sq2(int n, double *lastterm)
{
    double x, int i;

#pragma omp parallel for lastprivate(x) { // stored the last value
                                          // which ever thread did n-1, its value gets stored, in this case to x
    for (, i < n, )
    {
        x = a[i] * a[i] + b[i] * b[i] b[i] = sqrt(x);
    }
    *lastterm = x;
}
}

int main()
{

    return 0;
}