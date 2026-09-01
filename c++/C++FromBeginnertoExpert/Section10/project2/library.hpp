#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED
#include <iostream>

using namespace std;

extern int a; // external (outside) means we don't reserve memory

/*
    this will help ALOT ...
*/
void showHelp(); // auto external

#endif