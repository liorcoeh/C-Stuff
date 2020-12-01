/*
 * Definistions of all the string functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "string_functions.h"

/****************************************************************************/

size_t Strlen(const char *str)
{
	size_t length = 0;
	
	assert(str != NULL);

	while (*str)
	{
		++length;
		++str;
	}

	return (length);	
}

/****************************************************************************/

int Strcmp(const char *str1, const char *str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	
	while (*str1 || *str2)
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		++str1;
		++str2;
	}

	return (0);
}

/****************************************************************************/

char *Strcpy(const char *source, char *destination)
{
	size_t length = Strlen(source);
	size_t i = 0;

	for (i = 0; i < length; ++i)
	{
		destination[i] = source[i];
	}

	destination[i] = '\0';

	return (destination);


	// char *result = destination;
	
	// assert(source != NULL);
	// assert(destination != NULL);
	
	// while (*source)
	// {
	// 	*destination = *source;
	// 	++source;
	// 	++destination;
	// }
	// *destination = '\0';
	
	// return (result);
}

/****************************************************************************/

char *Strncpy(const char *source, char *destination, size_t n)
{
	size_t i = 0;
	
	assert(source != NULL);
	assert(destination != NULL);
	
	for(i = 0; i < n; i++)
	{
		destination[i] = source[i];
	}

	destination[i] = '\0';
	
	return (destination);


	// char *result = destination;
	// size_t i = 0;
	
	// assert(source != NULL);
	// assert(destination != NULL);
	
	// for(i = 0; i < n; i++)
	// {
	// 	*destination = *source;
	// 	source++;
	// 	destination++;
	// }
	// *destination = '\0';
	
	// return result;
}

/****************************************************************************/

int Strcasecmp(const char *str1, const char *str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	
	while(*str1 || *str2)
	{
		/* checks if a charcter is equal to other one */
		/* or by a difference of +- 32				  */
		if ((*str1 != *str2) && (*str1 != *str2+32) && (*str1 != *str2-32))
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
	}

	return (0);
}

/****************************************************************************/

char *Strchr(const char *str, int ch)
{
	assert(str != NULL);
	
	while ((*str) && (*str != ch))
	{
		str++;
	}

	return ((char*)str);
}

/****************************************************************************/

char *Strdup(const char *str)
{
	size_t size = Strlen(str) + 1;
	char *temp = (char*) malloc(sizeof(char) * size);
	
	assert(str != NULL);
	
	return Strcpy(str, temp);
}

/****************************************************************************/

char *Strcat(const char *source, char *destination)
{
	size_t length = Strlen(destination);
	char *result = destination;
	
	assert(source != NULL);
	assert(destination != NULL);
	
	while(*source)
	{
		*(destination + length) = *source;
		++destination;
		++source;
	}
	*(destination + length) = '\0';

	return (result);	
}

/****************************************************************************/

char *Strncat(const char *source, char *destination, size_t n)
{
	size_t length = Strlen(destination);
	size_t i = 0;
	char *result = destination;
	
	assert(source != NULL);
	assert(destination != NULL);
	
	for(i = 0; i < n; i++) 
	{
		*(destination + length) = *source;
		destination++;
		source++;
	}
	*(destination + length) = '\0';

	return (result);
}

/****************************************************************************/

char *Strstr(const char *search, const char *find)
{
	int l = Strlen(find);
	const char *result = search;
	
	assert(search != NULL);
	assert(find != NULL);
		
	while(*search)
	{
		if(*search == *find)
		{
			find++;
		}
		else if(*find == '\0')
		{
			return (char*)search - l;
		}
		search++;
	}
	
	return (char*)result;
}

/****************************************************************************/	