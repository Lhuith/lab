/*
    while, do, and for loops
*/

#include <stdio.h>

int main(int argc, char* argv[]){
    
    int count = 0;
    
    //a while loop - the condition is checked
    //at the top of the loop, loops 0 or more times.
    printf("\nwhile loop\n");
    
    while (count < 10){
        printf("%d ", count++);
    }
    
    printf("\n\n");
    
    //a do loop - the condition checked at
    //the bottom of the loop. loops 1 more times.
    
    printf("do loop\n");
    
    do{
        printf("%d, note that count is already 10, but will execute atleast once and incriment", count++);
    }   while (count < 10);
    
    printf("\n\n");
    
    /*
        if you want the body of the loop to never execute unless the condition is true,
        use a while loop. The body of a do loop will always execute at least once.
    */
    
    //a for loop. For loops have 3 parts in parenthesis:
    // a initlization: set the counter and other values
    // a condiation: while must be true in order for the loop
    // to coninue executing.
    // an incriment: how to change the value of the counter
    // each time through the loop.
    
    printf("for loop\n");
    //note that for loop is not need a outside var, instead creates the condition within the perenthesis
    for(int i = 0; i < 10; i++){
        printf("%d ", i);
    }
    
    printf("\n\n");
}