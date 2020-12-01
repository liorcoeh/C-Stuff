/*
 * Flip the order of the digits in a number
 */

#include <stdio.h>

int FlipNum(int num);

int main()
{
	int num = 54321;

	printf("%d\n%d\n", num, FlipNum(num));

	return (0);
}

int FlipNum(int num)
{
	int fliped_num = 0;

	while (num)
	{
		fliped_num = (fliped_num * 10 + (num % 10));
		num /= 10;
	}

	return (fliped_num);
}