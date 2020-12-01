#include <stdio.h>
#include <string.h>

#include "mem_functions.h"

#define GETPADDING(adress) ((size_t)(adress) % (8))

int main()
{
	char string2[40] = "another nice string to work with";
	char string3[40] = "another nice string to work with";
	char string[60] = "hello World this is a nice sentence wow";
	printf("string: %s\n", string);
	printf("string2: %s\n\n", string2);
	Memset(string + 1, '~', 30);
	
	printf("Expected: h~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ence wow\n");
	printf("Result:   %s\n\n\n", string);

	Memcpy(string2 + 5, string + 1, 18);
		
	printf("Expected: anoth~~~~~~~~~~~~~~~~~~work with\n");
	printf("Result:   %s\n\n\n", string2);

	/*memcpy(string2 + 4, string2, 12);
	printf("address: %p, offset: %lu, size: %lu\n", (void *)&string2, GETPADDING(&string2), sizeof(string2));
	printf("%s\n\n\n", string2);*/
	
	/* check when both aligned  and src < dest */
	Memmove(string3 + 8, string3, 18);
	printf("Original: another nice string to work with\n");
	printf("Expected: another another nice strink with\n");
	printf("Result:   %s\n\n\n", string3);
	
	/* check when src > dest */
	Memmove(string3, string3 + 5, 17);
	printf("Original: another nice string to work with\n");
	printf("Expected: er another nice sice strink with\n");
	printf("Result:   %s\n\n\n", string3);
	
	/* check when not aligned and src < dest */
	Memmove(string3 + 5, string3, 18);
	printf("Original: another nice string to work with\n");
	printf("Expected: er aner another nice sirink with\n");
	printf("Result:   %s\n\n\n", string3);

	/*
	printf("address: %p, offset: %u, size: %u\n", (void *)&i, GETPADDING(&i), sizeof(i));
	printf("address: %p, offset: %u, size: %u\n", (void *)&c, GETPADDING(&c), sizeof(c));
	printf("address: %p, offset: %u, size: %u\n", (void *)&s, GETPADDING(&s), sizeof(s));
	printf("address: %p, offset: %u, size: %u\n", (void *)&int_p, GETPADDING(&int_p), sizeof(int_p));
	printf("address: %p, offset: %u, size: %u\n", (void *)&pedding, GETPADDING(&pedding), sizeof(pedding));
	*/

	return (0);
}
