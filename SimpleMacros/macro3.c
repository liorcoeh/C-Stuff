#include <stdio.h>

#define SIZE_TYPE(var) ((char*)(&var+1)-(char*)(&var))

/* Checking if the macro work */
int main()
{
	
	int num = 12345678;
	int digits = 0;
	
	while (0 != num)
	{
		num /= 10;
		++digits;
	}
	
	printf("%d\n", digits);
	
	return (digits);
}
