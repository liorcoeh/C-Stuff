/*
 * Prints out the size in bytes of C data types
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void DataTypeSizes();

int main()
{
	Data_Type();
	
	return (0);
}

void DataTypeSizes()
{
	printf("Type: short int, size: %lu\n\n", sizeof(short int));
	
	printf("Type: unsigned short int, size: %lu	\n\n", 
	sizeof(unsigned short int));
	
	printf("Type: unsigned int, size: %lu\n\n", sizeof(unsigned int));
	
	printf("Type: int, size: %lu\n\n", sizeof(int));
	
	printf("Type: long int, size: %lu\n\n", sizeof(long int));
	
	printf("Type: signed char, size: %lu\n\n", sizeof(signed char));
	
	printf("Type: unsigned char, size: %lu\n\n", sizeof(unsigned char));
	
	printf("Type: float, size: %lu\n\n", sizeof(float));
	
	printf("Type: double, size: %lu\n\n", sizeof(double));
	
	printf("Type: long double, size: %lu\n\n", sizeof(long double));
}