/*
 * Test file for the logger
 */

#define _GNU_SOURCE			/* For the getline to work */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logger.h"			/* My header				*/

#define MAX_FILE_NAME 100


int main()
{
	FILE *fp;
	
	char filename[MAX_FILE_NAME];		/* Will get name from user		  	 */
    char *buffer = NULL;
    size_t bufsize = 0;
    int stop = -1;						/* Will be used to close the loop	 */
    
    /* Declaring the array of structers */
    struct logger log[5];
	log[0].Compare = Delete;
	log[1].Compare = Count;
	log[2].Compare = Exit;
	log[3].Compare = Addup;
	log[4].Compare = Addend;
	
	log[0].Operation = Operation_Delete;
	log[1].Operation = Operation_Count;
	log[2].Operation = Operation_Exit;
	log[3].Operation = Operation_Addup;
	log[4].Operation = Operation_Addend;
    
    
	printf("Enter file name: ");	/* Geting the file from the user and */
	scanf("%s", filename);			/* opening it. If it doesn't exist	 */
	fp = fopen(filename, "a");		/* creating it						 */
	
	
	/* The running of the main part */
	while(stop != GETOUT)	 /* getout from the enum in the header */
	{	
		getline(&buffer, &bufsize, stdin);
		stop = (*log[0].Compare)(buffer, filename);
	}
	
	fclose(fp);
	free(buffer);		/* Freeing the allocated careated by getline */

	return 0;

}

















