#include "assignment13.h"

void display_int_array(int arr[], int size) {
    printf("c - displaying integers: ");
    for (int i = 0; i < size; ++i)
        printf("%d, ", arr[i]);
    printf("\n");
}

void display_char_array(char **arr, int size) {
    printf("c - displaying string: ");
    for (int i = 0; i < size; ++i)
        printf("\"%s\", ", arr[i]);
    printf("\n");
}

int c_main() {
    printf("\nim in c land now\n");
    return 0;
}