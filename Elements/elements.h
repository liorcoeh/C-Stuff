/*
 * Create a struct that holds a string, an integer and a float.
 * You should be able to add to the struct an int and it should be added to
 * each member of the struct:
 * To the string it should concat - "string + 10" ==> "string10"
 * To the integer it should just add - "10 + 10" ==> "20"
 * To the float it should just add - "2.5000 + 10" ==> "25.0000"
 */

#include <stdio.h>	/* printf() */
#include <stdlib.h> /* malloc(), realloc(), free() */
#include <string.h> /* strcpy(), strlen(), strcat() */
#include <assert.h>

#define ARR_SIZE (5)	/* Needs to change when putting more elements */
#define BASIC_STRING_SIZE (30) /* Can be changed if needs to */

typedef struct TYPES
{
	char *string;
	int integer;
	float fl;
} types;

types *elements;

/******************************************************************************/

/* The manager for the program */
void MainMenu(int arr_size, int add_num);

/* Initialise the array and adding new elements */
void InitialiseArray(int arr_size);

/* Does the cycle of print - add - print */
void PrintAddPrint(int add_num, size_t arr_size);

/* Responsable for the printing of the information */
int Output(char *str, int num1, float num2);

/* Adds the integer to integer or float */
int AddToNum(int *num1, float *num2, int *add_num);

/* Responsable for adding integer to a string - uses two sub functions */
char *AddToStr(char *str, int add_num);

/* Concats the integer to the string  - uses a sub function */
char *ConcatIntStr(char *str, int add_num);

/* Counts the number of digits in an int - being used in ConcatIntStr() */
int NumOfDigits(int add_num);

/* Frees the allocated memory */
int CleanUp(int arr_size);
















