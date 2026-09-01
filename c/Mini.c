/*
    Creating a Mini C Game
*/ 

#include <stdio.h>
#include<conio.h>

typedef char* string;
typedef int bool;

#define true 1
#define false 0
#define ESC 27


bool running = true;
bool started = false;

void update();
void checkInput();
void render();
void start();

int getch(void);


int main(int argc, string argv[])
{
        while(running == 1)
        {
            checkInput();
            if(started == 0) start();
            update();
            render();
        }
}

void start(){
      printf("Game has started.\n");
      started = true;
}

//Game update junk in here
void update(){
    
    //printf("Game is Running\n");
}

void render(){
    
}


void checkInput(){
    if (_kbhit())
    {
      int key =_getch();

      if (key == ESC)
          printf("Game has ended.");
          running = false;
    }   
     
}