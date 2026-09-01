#include "array.h"

#include <stdio.h>

int array_print(int arr[], int n) {
    printf("\nim using c!\n");

    int i = 0;
    for (i = 0; i < n; ++i)
        printf("%d,", arr[i]);

    printf("\n");
    return 0;
}