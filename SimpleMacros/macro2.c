#include <stdio.h>

#define SIZE_VAR(var) ((char*)(&var+1)-(char*)(&var))

/* Checking if the macro work */
int main()
{
	int a = 5;
	char c[1] = "a";
	long x = 23.1;
	
	printf("%ld\n", SIZE_VAR(a));
	printf("%ld\n", SIZE_VAR(c));
	printf("%ld\n", SIZE_VAR(x));

	return (0);
}
