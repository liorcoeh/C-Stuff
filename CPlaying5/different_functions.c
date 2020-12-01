/*
 * Different functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "different_functions.h"

#define ZERO (0)
#define NINE (9)
#define TEN (10)

/******************************************************************************/

char ToASCII(int num)
{
	if ((num >= ZERO) && (num <= NINE))
	{
		return (char)(num + '0');
	}
	else
	{
		return (char)(num - TEN + 'A');
	}
}

/******************************************************************************/

void Strrev (char *str)
{
	int i = 0;
	int length = strlen(str);
	char temp = '\0';
	
	for(i = 0; i < (length / 2); ++i)
	{
		temp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = temp;
	}
}

/******************************************************************************/

int power(int x, unsigned int y) 
{
	int result = 1;
	
	while(0 != y)
	{
		result *= x;
		--y;
	}
	
	return (result);
}

/******************************************************************************/

int NumDigits(int num)
{
	int result = 0;
	
	while(0 != num)
	{
		num /= 10;
		++result;
	}
	
	return (result);
}


int Power(int x, unsigned int y)
{
	int result = 1;
	
	while(0 != y)
	{
		result *= x;
		--y;
	}
	
	return (result);
}




