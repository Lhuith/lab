/*
    structures.c
    shows use of structs
*/

#include <stdio.h>
#include <stdlib.h> //for malloc and free

//using the typedef alias to define an alais for string
typedef char* string;

int main(int argc, string argv[]){
    
    //define a new type called Book: a structure
    //containing a title, author, and number of pages:
    typedef struct{
        string title;
        string author;
        short pages;
    } Book;
    
    //create one book on the stack:
    Book book1;
    book1.title = "Big book of C";
    book1.author = "Jhon Doe";
    book1.pages = 100;
    
    //create a pointer to book2 on the heap:
    Book *book2 = malloc(sizeof(Book));
    book2 -> title = "Magic and why its Awsome";
    book2 -> author = "Jane DOH";
    book2 -> pages = 128;
    
    //print book1's information:
    printf("Book 1\n");
    printf("Title: %s\n", book1.title);
    printf("Author: %s\n", book1.author);
    printf("# of Pages: %d\n", book1.pages);
    
    //print book2's information:
    printf("Book 2\n");
    printf("Title: %s\n", book2 -> title);
    printf("Author: %s\n", book2 -> author);
    printf("# of Pages: %d\n", book2 -> pages);

    
    //free the heap memory assigned to book2:
    //failing to do this will result in memory leak.
    free(book2);
}