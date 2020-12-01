/*
 * Implement the following functions using bit wise operations
 */

#include <stdio.h>

/* Power - base equals 2 */
long PowerOfTwoByNum(unsigned int x);

/* Multiply two numbers */
long Multiply(unsigned int x, unsigned int y);

/* Swaping two bits */
int SwapTwoBits(unsigned int x, int first, int second);

/*****************************************************************************/

/* Clalculating " x*(2^y) " using bitwise operators */
long Pow2(unsigned int x, unsigned int y);

/* Checking if n is power of 2 using a loop */
long IsPowerOfTwoA(unsigned int n);

/* Checking if n is power of 2 without using a loop */
long IsPowerOfTwoB(unsigned int n);

/* Adding one to a number without the use of arithmetic operators */
long AddOne(unsigned int n);

/* Prints out the numbers that have exactly 3 set bits in them */
int ExactlyThree(unsigned int x[], int size);

/* Mirrors the byte using a loop */
int ByteMirrorA(unsigned int x);

/* Mirrors the byte without using a loop */
unsigned int ByteMirrorB(unsigned int x);

/* Checks if bit number two And bit number six are set */
int TwoAndSix(unsigned char c);

/* Checks if bit number two OR bit number six are set */
int TwoOrSix(unsigned char c);

/* Swaps the 3rd and 5th bits */
int Swap3And5Bits(unsigned int x);

/* Gives the closest number (smaller) that is devisable by 16 */
int Devisable16(unsigned int n);

/* Swaps two variables without using a third one */
int SwapTwoVars(unsigned int *x, unsigned int *y);

/* Counts the number of set bits using a loop */
int SetBitsNumA(unsigned int x);

/* Counts the number of set bits without using a loop */
int SetBitsNumB(unsigned int x);

/* Prints out the bits of a float number */
int BitPrint(float a);




