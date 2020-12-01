/*
 * A function that copies the "envp" to a buffer and prints it out as
 * lower case only.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>


/* Counts the amount of strings in env */
int CountStrings(char **env);

/* Finds the total length of all the strings in env */
int StringsLength(char **env);

/* Turns the letters to lower case */
char *ToLow(char *str);

/* Copies the information in envp into strings */
void CopyToStrings(char **envp_p, char **dest, char *strings, int num);

int main(int argc, char **argv, char **envp)
{
	int i = 0;
	int num = CountStrings(envp);
	int length = StringsLength(envp);
	
	char **new_envp = (char**)malloc(num * sizeof(char*));
	assert(new_envp != NULL);
	
	char *strings = (char*)malloc(length * sizeof(char));
	assert(strings != NULL);
	
	CopyToStrings(envp, new_envp, strings, num);
	
	/* Prints out the result */
	for (i = 0; i <+ num; ++i)
	{
		printf("%s\n", new_envp[i]);
	}	
	
	return (0);
}

int CountStrings(char **env)
{
	int count = 0;
	
	for ( ; *env != 0 ; env++, count++);
	
	return count;
	
}

int StringsLength(char **env)
{
	int count = 0;

	for (; *env != 0 ; env++)
	{
		count += strlen(*env) + 1;
	}
	
	return count;
	
}

char *ToLow(char *str)
{
    char *start = str;
    while (*str)
    {
        *str = tolower(*str);
        str++;
    }
    
    return start;
    
}

void CopyToStrings(char **envp_p, char **dest, char *strings, int num)
{
	int i = 0;
	
	for (i = 0 ; i < num ; i++)
	{
		int string_len = strlen(envp_p[i]);
		strcpy(strings, *(envp_p + i));
		
		ToLow(strings);
		*dest = strings;
		strings += string_len + 1;
		dest++;
	}
}







