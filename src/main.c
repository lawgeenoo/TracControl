#include "roll.h"
#include<stdio.h>
#include<termios.h>
#include<unistd.h>
#include<stdlib.h>

void main(){
static struct termios oldt, newt;
tcgetattr( STDIN_FILENO, &oldt);
newt = oldt;
newt.c_lflag &= ~(ICANON | ECHO);         
tcsetattr( STDIN_FILENO, TCSANOW, &newt);
roll();
tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
}
