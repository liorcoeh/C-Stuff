/****************************************************************************
* File Name: MyFunctions.h													*
* Writer: Lior Cohen														*
* Date: 20/02/2020														    *
* Purpose: A header file for usefull functions for future things			*
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/******************************************************************************/

/* Function that gives back the ASCII value of (0 - 35) */
char ToASCII(int num);

/* Function that reverses a string */
void Strev(char *str);

/* Counts the number of digits in a number */
int NumDigits(int num);

/* Gives the power of x by y (x^y) */
int Power(int x, unsigned int y);
