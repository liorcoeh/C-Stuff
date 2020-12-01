/***************************************************************************
* File Name: quiz.c														   *
*																		   *
* Purpose: The answers to the code questions on the quiz that			   *
*		   took place on Tusday, 04/02/2020								   *
****************************************************************************/

/*
 * Print the numbers from num1 to num2
 * If the number devides by 3, print "T"
 * If the number devides by 5, print "F"
 * If the number devides by 3 AND 5, print "TF"
 * If not, print the number itself
 */

# include <stdio.h>

void TF(int begin, int end);

int main()
{
	int begin = -100;
	int end = 100;
	
	TF(begin, end);

	return (0);
}

void TF(int begin, int end)
{
	int i = 0;
	
	for(i = begin ; i <= end ; i++)
	{
		if ((0 == i % 3) && (0 == i % 5))
		{
			printf("%d == TF\n", i);
		}

		else if (0 == i % 3)
		{
			printf("%d == T\n", i);
		}
		
		else if (0 == i % 5)
		{
			printf("%d == F\n", i);
		}

		else
		{
			printf("%d == %d\n", i, i);
		}
	}
}
