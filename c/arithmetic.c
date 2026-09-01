/*
    Arithmetic operators demo
    Shows use of C arithmetic operators
*/

#include <stdio.h>

int main(int argc, char* argv[]){
    char letter ='A';
    int a = 3;
    int b = 5;
    int result;
    
    //add a and b, and print the result
    result = a + b;
    printf("\n%d + %d = %d\n", a, b, result);
    
    //multiply a and b, and print the result
    result = a * b;
    printf("%d * %d = %d\n", a, b, result);
    
    //subtract b from a, and print the result
    result = a - b;
    printf("%d - %d = %d\n", a, b, result);
    
    //divide a from b, and print the result
    result = a / b;
    printf("%d / %d = %d\n\n", a, b, result);
    
    //well, that didnt work very well, try this:
    float quotient = a / b;
    printf("%d / %d = %f\n\n", a, b, quotient);
    
    //hmmm... maybe a and b need to be floats?
    float c = 3, d = 5;
    quotient = c / d;
    printf("%f / %f = %f\n\n", c, d, quotient);
    
    //ok, that worked :) more on that later
    
    //unary minus:
    a = -a;
    printf("negative %d is %d\n\n", -a, a);
    //reset a:
    a = -a;
    
    //shortcut assignment operators
    a += 3; //a = a + 3, a is now 6;
    b -= 2; //b = b - 2, b is now 3;
    printf("a = %d, b = %d\n", a, b);
    c *= 2; //c = c * 2, c is now 6.000000
    d /= 2; //d = d / 2, d is now 2.500000
    printf("c = %f, d = %f\n\n", c, d);
    
    //assign the value 1 to a and 0 to b:
    a = 1;
    b = 0;
    
    //incriment and decrement operators
    a++;                                //a is now 2
    printf("a = %d, b = %d\n\n", a, b); // print a
    b = a++;                            //b should be 3, right? 
    printf("a = %d, b = %d\n", a, b);   //wrong! try this:
    b = ++a;                            //always incriment before assigment;
    printf("a = %d, b = %d\n", a, b);   //that works
    
    b = a--;
    printf("a = %d, b = %d\n", a, b); //no suprises, post dec.
    b = --a;
    printf("a = %d, b = %d\n", a, b); //pre-decrement
    
    //remember char letter = 'A'?
    letter++;
    printf("%c is ASCII %d\n", letter, letter);
    printf("lowercase %c is %c\n", letter, letter + 32);
}























