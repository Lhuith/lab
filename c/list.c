/*
    list.c
    doubly linked list demo
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char* name;
    char* phone;
    struct node *pNext;
    struct node *pPrev;
    
} node;

node *pHead = NULL;
node *pTail = NULL;
node *pCurrent = NULL;

void printCurrent();
void prev();
void next();
void head();
void tail();

void add(char* name, char* phone);
void delete();

int main(int argc, char* argv[]){
    add("Anus Jim", "111-212-3125");
    add("Susie WhatsaBalls","222-555-3431");
    add("MummewWhamboo", "512-211-5532");
    add("Jacksir Twamboo", "214-634-988");
    head();
    printCurrent();
    next();
    printCurrent();
    next();
    printCurrent();
    prev();
    printCurrent();
    prev();
    printCurrent();
    delete();
    delete();
    delete();
    delete();
}

void add(char* name, char* phone){
    //set up the new node:
    node *pNew = malloc(sizeof(node));
    pNew -> name = name;
    pNew -> phone = phone;
    pNew -> pPrev = NULL;
    pNew -> pNext = NULL;
    
    //is this the first node?
    if(pCurrent == NULL){
        pHead = pNew;
        pTail = pNew;
    } else {
        //add to end:
        pTail -> pNext = pNew;
        pNew -> pPrev = pTail;
        pTail = pNew;
    }
    pCurrent = pNew;
}
void delete(){
    //make a pointer to the delete candidate:
    node *pDelete = pCurrent;
    //delete the current node
    if(pDelete == pHead && pDelete == pTail){ //only node
        printf("deleting only node: %s\n", pDelete -> name);
        pCurrent = pHead = pTail = NULL;
    } else if (pDelete == pHead){   //first node
        printf("deleting first node: %s\n", pDelete -> name);
        //next nodes prev is NULL
        pDelete -> pNext -> pPrev = NULL;
        //head points to next node
        pHead = pDelete -> pNext;
        //current is the first node
        pCurrent = pHead;
    } else if (pDelete == pTail){ //last node
        printf("deleting last node: %s\n", pDelete -> name);
        //previos nodes next is null
        pDelete -> pPrev -> pNext = NULL;
        //tail points to prevois node
        pTail = pDelete -> pPrev;
        //current is the last node
        pCurrent = pTail;
    } else { //middle
        printf("deleting a node in the middle: %s\n", pDelete -> name);
        pDelete -> pNext -> pPrev = pDelete -> pPrev;
        pDelete -> pPrev -> pNext = pDelete -> pNext;
        pCurrent = pDelete -> pNext;
    }
    free(pDelete);
}

void printCurrent(){
    printf("%s, %s\n", pCurrent -> name, pCurrent -> phone);
}
void prev(){
    if(pCurrent -> pPrev != NULL){
        pCurrent = pCurrent -> pPrev;
    }
}
void next(){
    if(pCurrent -> pNext != NULL){
        pCurrent = pCurrent -> pNext;
    }
}
void head(){
    pCurrent = pHead;
}
void tail(){
    pCurrent = pTail;
}