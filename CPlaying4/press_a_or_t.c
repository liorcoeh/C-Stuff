/*
 * Function that types out when 'a' or 'T' are pressed
 */

#include <stdio.h>
#include <stdlib.h> /* system() */

void A_T();

int main()
{
	A_T();

	return (0);
}

void A_T()
{
	char c = 0;

	system("stty -icanon -echo");	/* This one locks down "echo" */

	while (c != 27)						/* Exit when ESC is pressed		  */
	{
		c = getchar();

		if (c == 'A')
		{
			printf("A pressed\n");
		}
		else if (c == 'T')
		{
			printf("T pressed\n");
		}
	}

	system("stty icanon echo");			/* This one releases "echo"	  */
}