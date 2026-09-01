/*
    maxmin.c
    Find the max and min value in an array
    using pointer arithmetic
    
    Not something you would normally do with arrays,
    but the point is to increase the understanding,
    that pointers are just variables containing address's
*/

#include <stdio.h>
#include <limits.h> //for maximum and minimum int values

int max(int *array, int count);
int min(int *array, int count);

int maxGene(int *array, int count);
int minGene(int *array, int count);
void walkWithChars(int *array, int count); //very dangerous
typedef char* string;

int main(int argc, char* argv[]){
    int numbers[] = {3, -4, 79, 0, 5, 8, 42, 109, 85};
    
    //first show equivalency of [] and pointer notation:
    printf("numbers[0]: %d, *numbers: %d\n", numbers[0], *(numbers + 0));
    printf("numbers[4]: %d, *(numbers + 4): %d\n", numbers[4], *(numbers + 4));
    
    //print out the max and min of the array:
    printf("EDUMobile method\n");
    printf("The max is %d\n", max(numbers, 9)); //note that numbers is already an address ":()
    printf("The min is %d\n", min(numbers, 9));
    
    printf("Gene method\n");
    printf("The max is %d\n", maxGene(numbers, 9)); //note that numbers, the name, is already an pointer address, so no need for & ":()
    printf("The min is %d\n", minGene(numbers, 9));
    
    walkWithChars(numbers, 9);
}

int max(int *array, int count){
    //the name of the array is a pointer to the first element
    //of an array.pNumber will be used to walk the array.
    int *pNumber = array;
    //the minimum 4-byte int value:
    int max = INT_MIN;
    
    //loop through the array
    for(int i = 0; i < count; i++){
        int n = *pNumber; //which in this case is numbers[0] VALUE!!!! or 3!
        if(n >= max) max = n;
        //point pNumber to the next element in the array.
        //adding 1 to a pointer increases the pointers
        //value by the sizeof the type it points to i.e.,
        //this increases pNumber by 4, not 1.
        pNumber += 1; //or pNumber++
    }
    
    return max;
}

int min(int *array, int count){
    int *pNumber = array;
    int min = INT_MAX;
    
    //loop through the array
    for(int i = 0; i < count; i++){
        int n = *pNumber;
        if(n <= min) min = n;
        pNumber += 1; 
    }
    
    return min;
}

int maxGene(int *array, int count){
    int temp = *(array + 0);
    
    for(int i = 0; i < count; i++){
           if(*(array + i) > temp) temp = *(array + i);
    }
    
    return temp;
}

int minGene(int *array, int count){
    int temp = *(array + 0);
    
     for(int i = 0; i < count; i++){
        if(*(array + i) < temp) temp = *(array + i);
    }
    
    return temp;
}

//what happens if the types of pNumber and array are mismatched?
void walkWithChars(int *array, int count){
    int *pNumber;
        pNumber = array;
    
    for(int i = 0; i < count; i++){
        printf("'value' at pNumber %d :%d\n",i, *(pNumber + i));
        pNumber ++;
    }
}