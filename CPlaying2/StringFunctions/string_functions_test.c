/*
 * The test file for the string functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_functions.h"

int main()
{
	char st[10] = {0};
	char st1[] = "Hellow World";
	char st2[] = "Hellow World";
	char st3[] = "Hi World";
	char st4[] = "hI wOrLd";
	char vale[] = "Hellow Wo";
	char vale2[] = "World";
	char phrase1[] = "I a";
	char phrase2[] = "m tired";
	char test[] = "I am tired";
	char *target = 0;
			
	int length = 0;
	int check = 0;
	int ch = 'W';
	
	size_t n = 9;
	
	/**********************************************************************/

	/* Checking of the function: Strlen() */
	length = Strlen(st);
	
	if (0 != length)
	{
		printf("There is a problem with the Strlen function\n");
		check = 1;
	}
	
	length = Strlen(st1);
	
	if (12 != length)
	{
		printf("There is a problem with the Strlen function\n");
		check = 1;
	}
	
	if (0 == check)
	{
		printf("The function Strlen() seems fine\n\n");
	}
	
	/**********************************************************************/
	
	/* Checking of the function: Strcmp() */
	check = 0;
	
	if (0 != Strcmp(st1, st2))
	{
		printf("The function doesn't recognise that it's the same phrase\n");
		check = 1;
	}
	
	if (0 == Strcmp(st1, st3))
	{
		printf("The function is wrong\n");
		check = 1;
	}
	
	if (0 == check)
	{
		printf("The function Strcmp() seems fine\n\n");
	}
	
	/**********************************************************************/
	
	/* Checking of the function: Strcpy() */
	
	Strcpy(st3, st2);
	
	if (*st2 != *st3)
	{
		printf("The function didn't copy st3 into st2\n");
	}
	else
	{
		printf("The function Strcpy() seem fine\n\n");
	}
	
	/**********************************************************************/
	
	/* Checking of the function: Strncpy() */
	
	Strncpy(st1, st2, n);
	
	if (*st2 != *vale)
	{
		printf("The function doesn't work right\n");
		check = 1;
	}
	else
	{
		printf("The function Strncpy() seems fine\n\n");
	}
	
	/**********************************************************************/
	
	/* Checking of the function: Strcasecmp() */
	check = 0;
	
	if (0 == Strcasecmp(st1, st3))
	{
		printf("There is some problem with the function\n");
		check = 1;
	}
	
	if (0 != Strcasecmp(st3, st4))
	{
		printf("There is some problem with the function\n");
		check = 1;
	}
	
	if (0 == check)
	{
		printf("The function Strcasecmp() seems fine\n\n");
	}
	
	/**********************************************************************/
	
	/* Checking of the function: Strchr() */
	
	if (*vale2 != *Strchr(st1, ch))
	{
		printf("There is something wrong with the function\n");
	}
	else
	{
		printf("The function Strchr() seems fine\n\n");
	}
	
	/**********************************************************************/	
	
	/* Checking of the function: Strdup() */	
	target = Strdup(st1);
	
	if (0 != Strcmp(target, st1))
	{
		printf("There is a problem with the function\n");	
	}
	
	else
	{
		printf("The function Strdup() seems fine\n\n");
		free(target);
	}
	
	/**********************************************************************/
	
	/* Checking of the function: Strcat() */
	check = 0;

	target = Strcat(phrase2, phrase1);

	if (0 != Strcmp(target, test))
	{
		printf("There is something wrong with the function\n");
	}
	else
	{
		printf("The function Strcat() seems fine\n\n");
	}
	
	/**********************************************************************/
		
	/* Checking of the function: Strncat() */
	Strcpy("To be ", phrase1);
	Strcpy("or not to be", phrase2);
	Strcpy("To be or not", test);
	
	target = Strncat(phrase2, phrase1, 6);
	
	if (0 != Strcmp(target, test))
	{
		printf("There is a problem with the function\n");
		check = 1;
	}
	else
	{
		printf("The function Strncat() seems fine\n\n");
	}
	
	/**********************************************************************/
	
	/* Checking of the function: Strstr() */
	Strcpy("e", phrase1);
	Strcpy("To be or not to be", phrase2);
	Strcpy("e or not to be", test);
	check = 0;
	
	target = Strstr(phrase2, phrase1);
	
	if (0 != Strcmp(target, test))
	{
		printf("There is a problem with the function\n");
		check = 1;
	}
	
	Strcpy("a", phrase1);
	target = Strstr(phrase2, phrase1);
	
	if (0 != Strcmp(target, phrase2))
	{
		printf("There is a problem with the function\n");
		check = 1;
	}
	
	if (0 == check)
	{
		printf("The function Strstr() seems fine\n\n");
	}
	
	/**********************************************************************/
	
	
	return(0);	
}
