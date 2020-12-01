/*
 * The test file for the bit wise functions
 */

#include "bit_wise.h"

int main()
{
	unsigned long x = 9;
	unsigned long y = 16;
	unsigned int arr[] = {10, 11, 12, 13, 14, 15, 16, 17, 18 ,19 ,20};
	unsigned int n = 5;
	unsigned int m = 20;
	unsigned int i = 30;
	unsigned int j = 1000;
	unsigned char c1 = 205;
	unsigned char c2 = 201;
	float a = -118.625;
	
/*****************************************************************************/	
	
	if (589824 == Pow2(x, y))
	{
		printf("The Pow2() function seems fine\n\n");
	}
	else
	{
		printf("There is something wrong with Pow2() function\n\n");
	}
	
/*****************************************************************************/	
	
	if ((0 == IsPowerOfTwoA(x)) && (1 == IsPowerOfTwoA(y)))
	{
		printf("The IsPowerA() function seems fine\n\n");
	}
	else
	{
		printf("There is something wrong with the IsPowerA() function\n");
	}
	
	if ((0 == IsPowerOfTwoB(x)) && (1 == IsPowerOfTwoB(y)))
	{
		printf("The IsPowerB() function seems fine\n\n");
	}
	else
	{
		printf("There is something wrong with the IsPowerB() function\n");
	}

/*****************************************************************************/

	if (((unsigned int)(x + 1) == AddOne(x)) && 
				((unsigned int)(y + 1) == AddOne(y)))
	{
		printf("The AddOne() function seems fine\n\n");
	}
	else
	{
		printf("There is something wrong with the AddOne() function\n");
	}

/*****************************************************************************/

	if (4 == ExactlyThree(arr, 11))
	{
		printf("The ExactlyThree() function seems fine\n\n");
	}
	else
	{
		printf("There is something wrong with the ExactlyThree() function\n");
	}

/*****************************************************************************/

	if ((160 == ByteMirrorA(n)) && ((40 == ByteMirrorA(m))))
	{
		printf("The ByteMirrorA() function seems fine\n\n");
	}
	else
	{
		printf("There is something wrong with the ByteMirrorA() function\n");
	}
	
	if ((2013265920 == ByteMirrorB(i)) && ((398458880 == ByteMirrorB(j))))
	{
		printf("The ByteMirrorB() function seems fine\n\n");
	}
	else
	{
		printf("There is something wrong with the ByteMirrorB() function\n");
	}
	
/*****************************************************************************/

	if ((1 == TwoAndSix(c1)) && ((0 == TwoAndSix(c2))))
	{
		printf("The TwoAndSix() function seems fine\n\n");
	}
	else
	{
		printf("There is something wrong with the TwoAndSix() function\n");
	}
	
	c1 = c2;
	c2 = 153;
	
	if ((1 == TwoOrSix(c1)) && ((0 == TwoOrSix(c2))))
	{
		printf("The TwoOrSix() function seems fine\n\n");
	}
	else
	{
		printf("There is something wrong with the TwoOrSix() function\n");
	}

	n = 137;
	if (161 == Swap3And5Bits(n))
	{
		printf("The Swap3And5Bits() function seems fine\n\n");
	}
	else
	{
		printf("There is something wrong with the Swap3And5Bits() function\n");
	}

/*****************************************************************************/

	n = 33;
	if (32 == Devisable16(n))
	{
		printf("The Devisable16() function seems fine\n\n");
	}
	else
	{
		printf("There is something wrong with the Devisable16() function\n");
	}

/*****************************************************************************/

	n = 30;
	SwapTwoVars(&n, &m);
	if ((n == 20) && (m == 30))
	{
		printf("The SwapTwoVars() function seems fine\n\n");
	}
	else
	{
		printf("There is something wrong with the SwapTwoVars() function\n");
	}

/*****************************************************************************/

	n = 15;
	m = 111;
	
	if ((4 == SetBitsNumA(n)) && (6 == SetBitsNumA(m)))
	{
		printf("The SetBitsNumA() function seems fine\n\n");
	}
	else
	{
		printf("There is something wrong with the SetBitsNumA() function\n");
	}

/*****************************************************************************/

	if ((4 == SetBitsNumB(n)) && (6 == SetBitsNumB(m)))
	{
		printf("The SetBitsNumB() function seems fine\n\n");
	}
	else
	{
		printf("There is something wrong with the SetBitsNumB() function\n");
	}

/*****************************************************************************/
	
	BitPrint(a);
	
	return (0);
	
}





