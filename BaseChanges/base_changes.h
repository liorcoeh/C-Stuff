/*
 * Implement functions that can change bases:
 * From base to decimal.
 * From decimal to base.
 * From any base to any base.
 */

#include <stdio.h>

/* This function gets a string and turns is into base 10 number */
int ToBaseDec(char *str, int from_base);


/* This function gets a decimal number and converts it to another base */
char *DecBaseToOthers(int value, char *str, int to_base);


/* This function converts numbers from diffrent bases */
char *BaseToBase(char *source, char *result, int from_base, int to_base);

/* This function returns the power of x by y (x^y) */
int Power(int x, unsigned int y);

/* This function reverses a string */
char *Strrev (char *str);