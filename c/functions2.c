/*
    Functions: pass by value vs pass by refrence
*/

#include <stdio.h>

void swapV(int a, int b);
void swapR(int *a, int *b);

int main(int argc, char* argv[]){
    
    //attempt to swap two integers by passing there values:
    int num1 = 1, num2 = 0;
    printf("num1 = %d, num2 = %d\n", num1, num2);
    printf("Calling swapV\n");
    swapV(num1, num2);
    printf("num1 = %d, num2 = %d\n", num1, num2);
    
    //try to swap the same two values by passing pointers to
    //there values instead:
    printf("num1 = %d, num2 = %d\n", num1, num2);
    printf("Calling swapR\n");
    swapR(&num1, &num2);
    printf("num1 = %d, num2 = %d\n", num1, num2);
}

//swapping by value, only changing locally
void swapV(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

//swapping by refrence, chaning the values perminatly
void swapR(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
