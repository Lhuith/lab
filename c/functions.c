/*
    Function Demo
*/

#include <stdio.h>

//functions must be declared before they are called:

/*
*   FUNCTION DECLARATION or PROTOTYPES
*/

void callout(char* str);
void starline();
float int2float(int num);
void countToTen();
void wedge(char what, int lines);
void wedgeReverse(char what, int lines);
void wedgeFlip(char what, int lines);
void wedgeReverseFlip(char what, int lines);
void intSwap(int *a, int *b);

int main(int argc, char* argv[]){
    int a = 5, b = 2;
    starline();
    callout("Hello, world");
    callout(argv[0]);
    starline();
    printf("int = %d, float = %f\n", 42, int2float(42));
    starline();
    countToTen();
    starline();
    wedge('@', 5);
    wedgeReverse('@', 5);
    wedgeFlip('@', 5);
    wedgeReverseFlip('@', 5);
    starline();
    intSwap(&a, &b);
}

/*
*   FUNCTION DEFINITIONS
*/
//prints a string with \n before and after:
void callout(char* str){
    printf("\n%s\n", str);
}

//just prints a line of stars:
void starline(){
    printf("**************************************\n");
}

//convers an int to a float:
float int2float(int num){
    
    //this is a "cast." it doesnt change the type of a num, but
    //(float) num means "num as a float."
    //casts can generally be performed when there is no loss of
    //precision between the "from type" and the "to type."
    return (float) num;
}

//just counts to ten and returns:
void countToTen(){
    short count = 1;
    while (count <= 10){
        printf("%d, ", count++);
    }
    printf("\n");
}

//prints a wedge of "what" characters.
void wedge(char what, int lines){
    for(int i = 1; i <= lines; i++){
        for(int j = 1; j <= i; j++){
            printf("%c", what);
        }
        printf("\n");
    }
}

void wedgeFlip(char what, int lines){
    for(int i = 1; i <= lines; i++){
        
        for(int s = lines - i; s > 0; s--)
        printf(" ");
            
        for(int j = 1; j <= i; j++){
            printf("%c", what);
        }
        printf("\n");
    }
}

void wedgeReverse(char what, int lines){
        for(int i = 1; i <= lines; i++){
        for(int j = lines; j >= i; j--){
                printf("%c", what);
        }
        printf("\n");
    }
}

void wedgeReverseFlip(char what, int lines){
        for(int i = 1; i <= lines; i++){
                        for(int s = 0; s < i - 1; s++)
                        printf(" ");
        for(int j = lines; j >= i; j--){
                printf("%c", what);
        }
        printf("\n");
    }
}

//integer swap, passing the var address then assigng the contents to the vars

void intSwap(int *a, int *b){ //2 points, not contents, so we pass the address, and in the function we grab the content
    printf("a was %d, and b was %d\n", *a, *b);
    int temp = *a; //contents of a
    *a = *b;
    *b = temp;
    printf("a is now %d, and b is now %d\n", *a, *b);
}
