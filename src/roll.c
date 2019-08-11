#include<stdio.h>
#include<termios.h>
#include<unistd.h>
#include<stdlib.h>
#include "roll.h"
void tc(_Bool *a , int speed){
	*a = !*a; 
	if(speed > 60 && *a == 0)
		*a = 1;
}

void roll(void)
{   		
   char c;
   _Bool tcstate = 1;
    unsigned int a = 0; 

while(1){
		 
		printf("\t\t\t\tTraction CTRL: %d\rKPH : %03d\r", tcstate, a);
		c=getchar();   
		
		switch(c){
		
			case 'w':
			if(a == 270)
				continue;
				a++;
				break;    
			
			case 's':
			if(a == 0)
				continue;
				a--;	
				break;
			
			case 't':
				tc(&tcstate , a);
				break;
			 
			case 'q':
			printf("\n");
			return;
			default:
			continue;
        		}
			
		}	
}




