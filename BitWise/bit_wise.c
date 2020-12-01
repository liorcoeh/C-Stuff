/*
 * Functions definitions
 */

#include "bit_wise.h"

long PowerOfTwoByNum(unsigned int x)
{
	//unsigned long result = 1 << x;
	return (1 << x);
	//return (result);
}

long Multiply(unsigned int x, unsigned int y)
{
	long result = 0;
	int counter = 0; 
	while  (0 != y) 
	{
		if (y % 2 == 1)
		{
			result = result + (x << counter);
		}
			++counter; 
			y /= 2;
	}
	
    return result;
}

int SwapTwoBits(unsigned int x, int first, int second)
{
	int bit1 = (x >> first) & 1;	/* Moves the 3rd bit to the right side	*/
	int bit2 = (x >> second) & 1;	/* Moves the 5th bit to the right side	*/
	int swap = 0;
	unsigned result = 0;
	
	swap = bit1 ^ bit2;				/* Doing XOR on both bits				*/

	swap = (swap << first) | (swap << second);	/* Putting the swaped bits 	*/
												/* back in their places		*/
	result = x ^ swap;

	return (result);    
}

/*****************************************************************************/

long Pow2(unsigned int x, unsigned int y)
{
	unsigned long result = 1;
	
	result = Multiply(x, PowerOfTwoByNum(y));	/* Using functions in lines 13 and 20 */
	
	return (result);
}

/*****************************************************************************/

long IsPowerOfTwoA(unsigned int n)
{   
    while (n > 1)
	{
		if (0 == n % 2)
		{
			n = n >> 1;
		}
		else
		{
			return (0);
		}
	}
	
	return (1);
}


long IsPowerOfTwoB(unsigned int n)
{
	if (0 == (n & (n - 1)))		/* The & operand tells us if a number is odd */
	{							/* or even: (n & 1).						 */
		return (1);				/* so if we put & between a number and the	 */
	}							/* (number - 1), the only way it will be 0	 */
	else						/* is if it looks like this 100000 which is  */
	{							/* a power of 2								 */
		return (0);
	}
}

/*****************************************************************************/

long AddOne(unsigned int x)
{
	int m = 1;

	while (x & m)				/* Fliping all the bits after the last	*/
	{ 							/* right zero							*/
		x = x ^ m; 				/* Say 001010011 ==> 001010000			*/
		m <<= 1;
	}
	x = x ^ m;					/* Fliping the zero we fliped after		*/
	
	return (x);
} 

/*****************************************************************************/

int ExactlyThree(unsigned int x[], int size)
{
	int i = 0;
	int bits_num = 0;
	int num_amount = 0;

	printf("The numbers that have exactly 3 set bits in them, are: ");
	for(i = 0; i < size; ++i)
	{
		bits_num = SetBitsNumA(x[i]);	/* Calling a function from line 281 */
		if (3 == bits_num)
		{
			printf("%d, ", x[i]);
			++num_amount;
		}
	}
	printf("\n\n");

	return (num_amount);
}

/*****************************************************************************/

int ByteMirrorA(unsigned int x)
{
	int bit1 = 0;
	int bit2 = 0;
	unsigned int mirror_num = x;

	for (bit1 = 0, bit2 = 7; bit2 > 3; ++bit1, --bit2)
	{
		mirror_num = SwapTwoBits(mirror_num, bit1, bit2);
	}

	return mirror_num;
}

unsigned int ByteMirrorB(unsigned int x)
{
	unsigned int reverse = 0;
	unsigned int rev_lut[] = {0, 128, 64, 192, 32, 160, 96, 224, 16, 144, 80,
	208, 48, 176, 112, 240, 8, 136, 72, 200, 40, 168, 104, 232, 24, 152, 88,
	216, 56, 184, 120, 248, 4, 132, 68, 196, 36, 164, 100, 228, 20, 148, 84,
	212, 52, 180, 116, 244, 12, 140, 76, 204, 44, 172, 108, 236, 28, 156, 92,
	220, 60, 188, 124, 252, 2, 130, 66, 194, 34, 162, 98, 226, 18, 146, 82, 210,
	50, 178, 114, 242, 10, 138, 74, 202, 42, 170, 106, 234, 26, 154, 90, 218,
	58, 186, 122, 250, 6, 134, 70, 198, 38, 166, 102, 230, 22, 150, 86, 214,
	54, 182, 118, 246, 14, 142, 78, 206, 46, 174, 110, 238, 30, 158, 94, 222,
	62, 190, 126, 254, 1, 129, 65, 193, 33, 161, 97, 225, 17, 145, 81, 209,
	49, 177, 113, 241, 9, 137, 73, 201, 41, 169, 105, 233, 25, 153, 89, 217,
	57, 185, 121, 249, 5, 133, 69, 197, 37, 165, 101, 229, 21, 149, 85, 213,
	53, 181, 117, 245, 13, 141, 77, 205, 45, 173, 109, 237, 29, 157, 93, 221,
	61, 189, 125, 253, 3, 131, 67, 195, 35, 163, 99, 227, 19, 147, 83, 211,
	51, 179, 115, 243, 11, 139, 75, 203, 43, 171, 107, 235, 27, 155, 91, 219,
	59, 187, 123, 251, 7, 135, 71, 199, 39, 167, 103, 231, 23, 151, 87, 215,
	55, 183, 119, 247, 15, 143, 79, 207, 47, 175, 111, 239, 31, 159, 95, 223,
	63, 191, 127, 255};
	
	/* Reversing integers from 32 bits */
	reverse = rev_lut[x & 0xff] << 24 | rev_lut[(x >> 8) & 0xff] << 16 |
			  rev_lut[(x >> 16) & 0xff] << 8 | rev_lut[(x >> 24) & 0xff];

	return (reverse);
}

/*****************************************************************************/

int TwoAndSix(unsigned char c)
{
	int check2 = 0;
	int check6 = 0;
	int final_answer = 1;
	
	check2 = 1 << 2;			/* Checks if bit number 2 is set (1) */
	check2 = c & check2;		/* if so it is equal "not zero"		 */
	
	check6 = 1 << 6;			/* Checks if bit number 6 is set (1) */
	check6 = c & check6;		/* if so it is equal "not zero"		 */
	
	switch (check2)
	{
		case (0):
			final_answer = 0;
			return (final_answer);
		break;
	}
	
	switch (check6)
	{
		case (0):
			final_answer = 0;
			return (final_answer);
		break;
	}
	
	return (1);
}

int TwoOrSix(unsigned char c)
{
	int check2 = 0;
	int check6 = 0;
	int final_answer = 0;
	
	check2 = 1 << 2;
	check2 = c & check2;
	
	check6 = 1 << 6;
	check6 = c & check6;
	
	switch (check2)
	{
		case(4):
			final_answer = 1;
			return (final_answer);
		break;
	}
	
	switch (check6)
	{
		case (64):
			final_answer = 1;
			return (final_answer);
		break;
	}

	return (final_answer);
}

int Swap3And5Bits(unsigned int x)
{
	int bit3 = (x >> 3) & 1;		/* Moves the 3rd bit to the right side	*/
	int bit5 = (x >> 5) & 1;		/* Moves the 5th bit to the right side	*/
	int swap = 0;
	unsigned result = 0;
	
	swap = bit3 ^ bit5;				/* Doing XOR on both bits				*/

	swap = (swap << 3) | (swap << 5);	/* Putting the swaped bits back in	*/
										/* in their places					*/
	result = x ^ swap;
	
	return (result);    
}

/*****************************************************************************/

int Devisable16(unsigned int n)
{ 
	unsigned int result = n >> 4;	/* Devisable by 16 means deivisable by	*/
	result = result << 4;			/* 2^4, so we just need to go 4 right	*/
									/* and then 4 left						*/

	return (result);
} 

/*****************************************************************************/

int SwapTwoVars(unsigned int *x, unsigned int *y)
{
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
	
	return (0);
}

/*****************************************************************************/

int SetBitsNumA(unsigned int x)
{
	int counter = 0;
	int check = 1;
	int i = 0;
	
	for(i = 0; i < 8; ++i)
	{
		check = check & x;
		if (0 == check)
		{
			check = 1;
		}
		
		else
		{
			++counter;
		}
		x = x >> 1;
	}
	
	return (counter);
}

/*****************************************************************************/

int SetBitsNumB(unsigned int x)
{
	int result = 0;
	int set_bits_num[] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2,
	2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3,
	4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, 3,
	2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4,
	5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5,
	5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4,
	5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5,
	3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2,
	3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5,
	5, 6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5,
	6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8};
	
	result = set_bits_num[x];
	
	return (result);
}

/*****************************************************************************/

int BitPrint(float a)
{
    int i = 0;
    int bit_num = 0;
    int *b = 0;
    
    b = (int*)&a;
    
    for (i = 32; i > 0; --i)
    {
    	bit_num = *b & (1 << i);
		if (0 == bit_num)
		{
			printf("0");
		}
		else
		{
			printf("1");
		}
	}   
	printf("\n\n");
	
	return (0);
}








/*
1) It takes an integer with a value of 5 and prints it out, so you get 5.
   Then it shifts it to the left 2 times. Since 5 in binary is 101, it will
   now turn into 10100 which is 20 in decimal so it will print that out.
   Lastly, x wasn't changed, so now x is shifted right 2 times which will give
   out 1, and that is what it will print.

2) a. We can use if/else.
   b. We can use switch-case.
   c. We can use function that gives the answer of (12 - x)  .
   d. We can use a function that swaps the first bit. 5 is 101, 7 is 111.
   
3) In the past there were diffrenet meanings to bytes. Some use 6 or 7...
   Actually, anywhere from 1 to 48 was used sometime in the past.
   Later on, since 8 bits in a byte is very usefull for the 256 binary code,
   and because Intel started using it as well, it was officially diclared
   as the standart of byte.
   
4) !(!(a && b) || (c && a) = ~(~(a & b) | (c & a)
	
 */ 






