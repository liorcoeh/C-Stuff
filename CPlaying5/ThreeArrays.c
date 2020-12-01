/*
 * A function that prints the letters that appear in the first two arrays
 * without appearing in the third array
 */

#include <stdio.h>		/* printf() */

int OnlyInTwo(char *arr1, char *arr2, char *arr3);

int main()
{
	char *arr1 = "something somethingx";
	char *arr2 = "anything anythingx";
	char *arr3 = "nothing nothing";
	
	OnlyInTwo(arr1, arr2, arr3);

	return (0);
}

int OnlyInTwo(char *arr1, char *arr2, char *arr3)
{
	int i = 0;
	int result[123] = {0};
	int temp = 0;
	
	while (*arr1)
	{
		temp = *arr1;
		if (0 == result[temp])
		{
			result[temp] = 1;
		}
		++arr1;
	}
	
	while ('\0' != *arr2)
	{
		temp = *arr2;
		if (1 == result[temp])
		{
			result[temp] = 2;
		}		
		++arr2;
	}
	
	while ('\0' != *arr3)
	{
		temp = *arr3;
		if (2 == result[temp])
		{
			result[temp] = 0;
		}
		++arr3;
	}
	
	for (i = 0; i < 123; ++i)
	{
		if ((0 != result[i]) && (1 != result[i]))
		{
			printf("%c, ", (char)i);
		}
	}
	printf("\n");
	
	return (0);
}


