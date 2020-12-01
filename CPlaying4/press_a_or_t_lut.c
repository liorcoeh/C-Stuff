/*
 * Printing on the screen when 'A' or 'T' are pressed, using LUT method.
 */

#include <stdio.h>
#include <stdlib.h>

#define ASCII (256)

void A_T();

/* Function that prints out "A pressed" if 'A' is pressed			*/
int PressA();

/* Function that prints out "T pressed" if 'T' is pressed			*/
int PressT();

/* Function that returns nothing if not 'A', 'T' or ESC are pressed */
int Empty();

  
int main() 
{
	A_T();
	
	return (0);
} 

void A_T()
{
	int (*LUT[ASCII])();			/* Array of pointers to functions */
	char c = 0;
	int i = 0;
	
	for (i = 0 ; i < ASCII ; ++i)	/* Pointing all the pointers in	  */
	{								/* to the function Empty		  */
		LUT[i] = Empty;
	}
	
	LUT[65] = PressA;				/* Pointing pointer number 65 (A) */
	LUT[84] = PressT;				/* Pointing pointer number 85 (T) */
	
	system("stty -icanon -echo");	/* This one locks down "echo" */
	
	while (c != 27)					/* Exit when ESC is pressed		  */
	{
		c = getchar();
		LUT[c]();
	}

	system("stty icanon echo");			/* This one releases "echo"	  */
}

int PressA()
{ 
	printf("A pressed\n");

	return (0);
}

int PressT()
{ 
	printf("T pressed\n");
	
	return (0);
}

int Empty()
{
	return (0);
}




