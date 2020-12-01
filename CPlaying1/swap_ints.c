/*
 * Swap between two int
 */

# include <stdio.h>

void Swap(int *a, int *b);

int main()
{
	int a = 2, b = 5;

	printf("a = %d, b = %d\n", a, b);

	Swap(&a, &b);

	printf("a = %d, b = %d\n", a, b);

	return 0;
}

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}