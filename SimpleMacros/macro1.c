#include <stdio.h>

#define MAX2(a, b) ((a >= b) ? a : b)

#define MAX3(a, b, c) ((MAX2(a, b) >= c) ? MAX2(a, b) : c)


/* Checking if the macros work */
int main()
{
	int a = 5;
	int b = 4;
	int c = 1;
	
	int result = MAX2(a, b);
	result = MAX3(a, b, c);
	
	printf("%d\n", result);

	return (0);
}

