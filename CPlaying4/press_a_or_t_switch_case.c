/*
 * Printing on the screen when 'A' or 'T' are pressed, using switch/case method.
 */

#include <stdio.h>
#include <stdlib.h>

void A_T();

int main()
{
	A_T();
	
	return (0);
	
}	

void A_T()
{
	char c;	

	system("stty -icanon -echo");		/* Locks the echo function		  */

	while (c != 27)						/* Exit when ESC is pressed		  */
	{
		c = getchar();

		switch (c)
		{
			case ('A'):					/* If 'a' is pressed then print	  */
				printf("A Prassed\n");
				break;
			
			case ('T'):
				printf("T Prassed\n");	/* If 'T' is pressed then print	  */
				break;
		}
	}
		
	system("stty icanon echo");		   /* Unlocks the echo function		  */
}