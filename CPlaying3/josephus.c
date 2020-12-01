/*
 * Solve the Josephus Problem
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int Josephus(int size);

int main()
{
	int size = 100;
	
	printf("The last one to survive is: %d\n", Josephus(size));
	
	return 0;
}
	
int Josephus(int size)
{
	int soldier = 0;				/* Will give the number of the last one */
	int i = 0;
	int j = 0;
	int startpoint = 2;
	int *soldiers  = (int*) (malloc(size * sizeof(int)));
	
	assert(soldiers != NULL);
	
	for(i = 0 ; i < size ; ++i)			/* filling every "cell" in the		*/
	{									/* array with N number				*/
		soldiers[i] = (i + 1);
	}
	
	i = 0;

	/* Moving the "surviving numbers" to the start of the array				 */
	while (i < (size / 2) + 1)			/* No need to run on all the array	 */
	{
		if (2 >= size)
		{
			soldier = soldiers[0];		/* The output - when the size of	 */
			free(soldiers);				/* the array is two or less the		 */
			return soldier;				/* answer is the first cell			 */
		}
		
		else if (0 == size % 2)					/* If the array size is		 */
		{										/* even start from the		 */
			for (i = 1 ; i < size ; ++i)		/* second cell, and each	 */
			{									/* one equals the one who 	 */
				soldiers[i] = soldiers[2 * i];	/* is i+i from it			 */
			}
		}
		
		else									/* If the array size is	odd	 */
		{										/* start from the first cell */
			for (i = 0 ; i < size + 1 ; ++i)	/* and each one equals the   */
			{									/* one who is 2+i+i from it  */
				soldiers[i] = soldiers[startpoint + (2 * i)];
			}
		}
		
		i = 0;
		size = size / 2;
	}	
}	
	
	
	
