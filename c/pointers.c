/*
    First Pointer Demo
*/

#include <stdio.h>

int main(int argc, char* argv[]){
    //declare an int a
    int a;
    //delcare a pointer to a. "assign pA the address of a"
    int *pA; // <--- pointer
    pA = &a; // <--- assigning the address of a, not the contents!, but now we can get the contents using *
    
    //print the sizeof a and pA:
    printf("sizeof a = %lu, sizeof pA = %lu\n", sizeof a, sizeof pA);
    
    a = 9;
    
    //print a, pA, and the contents of the memory at address pA:
    printf("a = %d, pA = %p, *pA = %d\n", a, pA, *pA);
    
    *pA = 4;
    //print again
    printf("a = %d, pA = %p, *pA = %d\n", a, pA, *pA);
    
    int *pA2 = &a;
    //print the contents of pA and pA2:
    printf("*pA = %d, *pA2 = %d\n", *pA, *pA2);
    
    //bump *pA:
    *pA += 1;
    printf("*pA = %d, *pA2 = %d, a = %d\n", *pA, *pA2, a);
    
    //char* argv[] is an array of char pointers, or string
    //char* = string in c and c++
    //c# syntax candied that shit yo
    
    int argcount = 0;
    
    while(argcount < argc){
        printf("argv[%d] = %s\n", argcount, argv[argcount]);
        argcount++;
    }
}