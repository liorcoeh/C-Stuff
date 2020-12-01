/*
 * The functions definitions
 */

#include "elements.h"

void MainMenu(int arr_size, int add_num)
{
	PrintAddPrint(add_num, arr_size);
	CleanUp(arr_size);	
}

/******************************************************************************/

/* Initializing the array elements */
void InitialiseArray(int arr_size)
{
	int i = 0;

	elements = (types *)malloc(sizeof(types) * ARR_SIZE);
	assert(elements);

	/* Initializing the array elements to hold nothing */
	for (i = 0; i < arr_size; ++i)
	{		
		elements[i].string = (char*) malloc(sizeof(char) * BASIC_STRING_SIZE);
		assert(elements[i].string);
			
		elements[i].integer = 0;
		elements[i].fl = 0;
	}
}

/******************************************************************************/

void PrintAddPrint(int add_num, size_t arr_size)
{
	size_t i = 0;
	
	/* Prints first time, before add up */
	for (i = 0; i < arr_size; ++i)
	{
		Output(elements[i].string, elements[i].integer, elements[i].fl);
	}
	printf("\n");

	/* Adds the int to the elements */
	for (i = 0; i < arr_size; ++i)
	{
		AddToNum(&elements[i].integer, &elements[i].fl, &add_num);
		AddToStr(elements[i].string, add_num);
	}

	/* Prints second time, after add up */
	for (i = 0; i < arr_size; ++i)
	{
		Output(elements[i].string, elements[i].integer, elements[i].fl);
	}
	printf("\n");
}

/******************************************************************************/
		
int Output(char *str, int num1, float num2)
{	
	if (0 != num1)				/* If integer isn't empty print it out */
	{
		printf("%d, ", num1);
	}
	else if (0 != num2)			/* If float isn't empty print it out */
	{
		printf("%f, ", num2);
	}
	else
	{
		printf("%s, ", str);	/* string isn't empty print it out */
	}

	return (0);
}

/******************************************************************************/

int AddToNum(int *num1, float *num2, int *add_num)
{		
	if(0 != *num1)				/* Adds to int	 */
	{
		*num1 += *add_num;
	}
	else if(0 != *num2)			/* Adds to float */
	{
		*num2 += + *add_num;
	}
	
	return (0);
}

/******************************************************************************/

char *AddToStr(char *str, int add_num)
{							 	
	if(*str)
	{	
		str = (ConcatIntStr(str, add_num));
		return (str);
	}
	else
	{
		return (0);
	}
}

char *ConcatIntStr(char *str, int add_num)
{
	int length = strlen(str);
	int DigitsNum = NumOfDigits(add_num);
	char *buffer = (char *) malloc(sizeof(char) * DigitsNum);
	
	sprintf(buffer, "%d", add_num);
	length = (length + strlen(buffer) + 1);
	strcat(str, buffer);
	free(buffer);	
	
	return (str);
}

int NumOfDigits(int add_num)
{
	int num = add_num;
	int digits = 1;
	
	while (0 != num)
	{
		num /= 10;
		++digits;
	}
	
	return (digits);
}

int CleanUp(int arr_size)
{
	int i = 0;
	
	for (i = 0; i < arr_size; ++i)
	{
		free(elements[i].string);
	}
	
	free(elements);
	return (0);
}












	
	
	
	
	
	
	
	
	
