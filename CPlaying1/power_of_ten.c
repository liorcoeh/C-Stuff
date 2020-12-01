/*
 * Return the power of 10 of a given num (n^10)
 */

# include <stdio.h>

double PowerOfTen(double num);

int main()
{
	double num = 5;

	printf("%0.2f\n%0.2f\n", num, PowerOfTen(num));

	return (0);
}

double PowerOfTen(double num)
{
	double res = 1;
	int ten = 10;

	while (ten)
	{
		res *= num;
		--ten;
	}

	return (res);	
}


