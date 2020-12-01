/*
 * Print out "Hello World", while using the hexadecimal for the letters
 */

# include <stdio.h>

void HelloWorldPrint();

int main()
{
	HelloWorldPrint();

	return (0);
}

void HelloWorldPrint()
{
	printf("\x22\x48\x65\x6C\x6C\x6F\x20\x57\x6F\x72\x6C\x64\x22\n");
}