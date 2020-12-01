/****************************************************************************
* File Name: Compare.c														*
* Writer: Lior Cohen														*
* Date: 13/02/2020														    *
* Purpose: The functions inside the structures who checks the input			*
* Code Reviewr: Amir paz													*
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Logger.h"		/* My header */


enum opera Delete(char *str, char *filename)
{	
	int length = strlen(str);	/* Removing the '\n' from the end of the */
	char check[] = "-remove";	/* string to make a good comparison		 */
	str[length - 1] = '\0';
	
	if(strcmp(str, check) == 0)
	{
		return ((*Operation_Delete)(str, filename));
	}
	
	else
	{
		str[length -1] = '\n';	/* Returning the '\n' to the string		*/
								/* for future purposes					*/
		return ((*Count)(str, filename));	
	}
}


enum opera Count(char *str, char *filename)
{
	int length = strlen(str);
	char check[] = "-count";
	str[length - 1] = '\0';
	
	if(strcmp(str, check) == 0)
	{
		return ((*Operation_Count)(str, filename));
	}
	
	else
	{
		str[length -1] = '\n';
		
		return ((*Exit)(str, filename));
	}
}


enum opera Exit(char *str, char *filename)
{
	int length = strlen(str);
	char check[] = "-exit";
	str[length - 1] = '\0';
	
	if(strcmp(str, check) == 0)
	{
		return (Operation_Exit(str, filename));
	}
	
	else
	{	
		str[length -1] = '\n';
		
		return (Addup(str, filename));
	}
}

enum opera Addup(char *str, char *filename)
{	
	if(*str == '<')	/* Checing if the first note is '<' */
	{
		return (Operation_Addup(str, filename));
	}
	
	else
	{
		return (Addend(str, filename));
	}
}

enum opera Addend(char *str, char *filename) /* If nothing else happened */
{
	return (Operation_Addend(str, filename));
}
















