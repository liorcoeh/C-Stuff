/*
 * Functions definitions
 */

#include <string.h> /* strlen()   */
#include <ctype.h>  /* isaplpha() */

#include "base_changes.h"

#define DIGITDEF (48)	/* '0' */
#define LETTERDEF (55)	/* 'A' - 10 */
#define MAX_BASE (36)
#define MIN_BASE (2)


/******************************************************************************/

int ToBaseDec(char *str, int from_base)
{
	int length = strlen(str);
	int i = 0;
	int result = 0;
	int num = 0;
	
	if ((MAX_BASE < from_base) || (MIN_BASE > from_base))
	{
		printf("Wrong base - base must be between 2 and 36\n");
		return (0);
	}
	
	Strrev(str);
	
	for (i = 0; i < length; ++i)
	{
		if (isalpha(str[i]))
		{
			num = str[i] - LETTERDEF;
		}
		else
		{
			num = str[i] - DIGITDEF;
		}
		
		if (from_base <= num)
		{
			printf("Invalid Number\n");/* In case the number is not matching */
			return (0);				   /* the base given, like 13 in base 2  */
		}

		result += (num * (Power(from_base, i)));
	}

	return (result);
}

/******************************************************************************/

char *DecBaseToOthers(int value, char *str, int to_base)
{
	int reminder = 0;
	int i = 0;
	
	if ((MAX_BASE < to_base) || (MIN_BASE > to_base))
	{
		printf("Wrong base - base must be between 2 and 36\n");
		return (0);
	}
	
	for (i = 0; value != 0; ++i)
	{
		reminder = value % to_base;
		value /= to_base;
		
		if ((reminder >= 0) && (reminder <=9))
		{
			str[i] = reminder + DIGITDEF;

		}
		else
		{
			str[i] = reminder + LETTERDEF;
		}
		
	}
	str[i] = '\0';
	Strrev(str);
	
	return (str);	
}
	
/******************************************************************************/

char *BaseToBase(char *source, char *result, int from_base, int to_base)
{
	int num = 0;
	
	num = ToBaseDec(source, from_base);
	
	printf("%d\n", num);
	
	return (DecBaseToOthers(num, result, to_base));
}

/******************************************************************************/

int Power(int x, unsigned int y)
{
	int result = 1;
	
	while (y)
	{
		result *= x;
		--y;
	}
	
	return (result);
}
	
char *Strrev (char *str)
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
	
	return (str);
}



	
	
	
	
	
	
	
	
	




