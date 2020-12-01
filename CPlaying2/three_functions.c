/*
 * Define the following functions:
 * IsPalindrome(const char *str) - checks if a string is a plindrome.
 * SevenBoom(int from, int to) - prints all the the numbers between
 * from / to, if the number devides by 7 it will print Boom insted.
 * void TwoPointersSwap(int **a, int **b) - swaps between two pointers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int IsPalindrome(const char *str);

void SevenBoom(int from, int to);

void TwoPointersSwap(int **a, int **b);

int main()
{
	char st1[] = "abcefggfedcba";
	char st2[] = "  My Name Is Lior Cohen  ";
	char st3[] = "abcdeedcba";

	int from = -20;
	int to = 10;

	int e = 10;
	int f = 0;
	int *pe = &e;
	int *pf = &f;
	int **ppe = &pe;
	int **ppf = &pf;

	printf("st1[] is a palindrome? %d\n", IsPalindrome(st1));
	printf("st2[] is a palindrome? %d\n", IsPalindrome(st2));
	printf("st3[] is a palindrome? %d\n", IsPalindrome(st3));
	printf("\n\n");

	SevenBoom(from, to);
	printf("\n\n");

	printf("%d\n", *ppe);
	printf("%d\n", *ppf);

	TwoPointersSwap(ppe, ppf);

	printf("%d\n", **ppe);
	printf("%d\n", **ppf);
	
	return (0);
}

int IsPalindrome(const char *str)
{
	int i = 0;
	int length = strlen(str) - 1;
	
	for (i = 0; i < length / 2; ++i)
	{
		if (str[i] != str[length - i])
		{
			printf("Not a palindrome\n");
			return (0); /* Failure */
		}
	}

	printf("Is a palindrome\n");
	return (1); /* Success */
}

void SevenBoom(int from, int to)
{
	int i = 0;

	for (i = from; i <= to; ++i)
	{
		if (0 == i % 7)
		{
			printf("BOOM\n");
		}
		else
		{
			printf("%d\n", i);
		}
	}
}

void TwoPointersSwap(int **a, int **b)
{
	int *temp = *a;
	*a = *b;
	*b = temp;
}