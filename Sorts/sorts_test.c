/*
 * Sorts - Test File
 */

#include <stdio.h>	/* printf() */
#include <time.h>	/* time()	*/
#include <stdlib.h> /* srand(), rand() */

#include "sorts.h"

#define SIZE (5000)
#define UPPER (100)
#define LOWER (1)
#define SEVUP (10000)
#define SEVLOW (1)

#define PRINT

/*****************************************************************************/

/*
 * Random Num: Static function to get random numbers
 * Receive:
 * - int arr[] - The array to put the random numbers in
 * - size_t size - The size of the array
 * - size_t lower - The lowest number that can come out as random
 * - size_t upper - The highest number that can come out as random
 * Time Complexity: O(n)
 */
static void RandomNum(int arr[], size_t size, size_t lower, size_t upper);

/*
 * Print Nums: Static function to print the numbers in an array
 * Receive:
 * - int arr[] - The array to print the numbers of
 * - size_t size - The size of the array
 * Time Complexity: O(n)
 */
static void PrintNums(int arr[], size_t size);

/*
 * Cmp Func: Help function for the qsort function
 * Return: int - The deference between two numbers
 * Receive:
 * - const void *a - Pointer to the first element
 * - const void *b - Pointer to the second element
 * Time Complexity: O(1)
 */
static int CmpFunc(const void *a, const void *b);

static void SortedArr(int arr[], size_t size, size_t lower);

/*****************************************************************************/
/*****************************************************************************/

int main()
{
	int test[SIZE] = {0};
	int to_find = 2;
	int found_index = 0;
	int param = 10;
	clock_t start_t = 0;
	clock_t end_t = 0;
	
	/***************************** qsort() ***********************************/
	
	RandomNum(test, SIZE, LOWER, SIZE);
	
	start_t = clock();	
	qsort(test, SIZE, sizeof(int), CmpFunc);
	end_t = clock();
	printf("The total time of qsort() is %ld\n\n", end_t - start_t);

	/***************************** BUBBLE SORT *******************************/
	
	RandomNum(test, SIZE, LOWER, SIZE);
	
	#ifdef PRINT
	printf("After the first randomize the list is: \n");
	PrintNums(test, SIZE);
	#endif /* PRINT */
	
	start_t = clock();
	BubbleSort(test, SIZE);
	end_t = clock();
	printf("The total time of BUBBLE SORT is %ld\n\n", end_t - start_t);
	
	#ifdef PRINT
	printf("After BUBBLE SORT the list is: \n");
	PrintNums(test, SIZE);
	#endif /* PRINT */
	
	/************************** SELECTION SORT *******************************/
	
	RandomNum(test, SIZE, LOWER, SIZE);
	
	#ifdef PRINT
	printf("After the second randomize the list is: \n");
	PrintNums(test, SIZE);
	#endif /* PRINT */
	
	start_t = clock();
	SelectionSort(test, SIZE);
	end_t = clock();
	printf("The total time of SELECTION SORT is %ld\n\n", end_t - start_t);
	
	#ifdef PRINT
	printf("After SELECTION SORT the list is: \n");
	PrintNums(test, SIZE);
	#endif /* PRINT */
	
	/************************** INSERTION SORT *******************************/
	
	RandomNum(test, SIZE, LOWER, SIZE);
	
	#ifdef PRINT
	printf("After the third randomize the list is: \n");
	PrintNums(test, SIZE);
	#endif /* PRINT */
	
	start_t = clock();
	InsertionSort(test, SIZE);
	end_t = clock();
	printf("The total time of INSERTION SORT is %ld\n\n", end_t - start_t);
	
	#ifdef PRINT
	printf("After INSERTION SORT the list is: \n");
	PrintNums(test, SIZE);
	#endif /* PRINT */
	
	/************************** COUNTING SORT *******************************/
	
	RandomNum(test, SIZE, LOWER, UPPER);
	
	#ifdef PRINT
	printf("The list after randomize before COUNTING SORT is: \n");
	PrintNums(test, SIZE);
	#endif /* PRINT */
	
	start_t = clock();
	CountingSort(test, SIZE, UPPER);
	end_t = clock();
	printf("The total time of COUNTING SORT is %ld\n\n", end_t - start_t);
	
	#ifdef PRINT
	printf("After COUNTING SORT the list is: \n");
	PrintNums(test, SIZE);
	#endif /* PRINT */
	
	/************************** RADIX SORT *******************************/
	
	RandomNum(test, SIZE, SEVLOW, SEVUP);
	
	#ifdef PRINT
	printf("The list after randomize before RADIX SORT is: \n");
	PrintNums(test, SIZE);
	#endif /* PRINT */
	
	start_t = clock();
	RadixSort(test, SIZE);
	end_t = clock();
	printf("The total time of RADIX SORT is %ld\n\n", end_t - start_t);
	
	#ifdef PRINT
	printf("After RADIX SORT the list is: \n");
	PrintNums(test, SIZE);
	#endif /* PRINT */
	
	
	/************************** MERGE SORT *******************************/
	
	
	RandomNum(test, SIZE, SEVLOW, SEVUP);
	
	#ifdef PRINT
	printf("The list after randomize before MERGE SORT is: \n");
	PrintNums(test, SIZE);
	#endif /* PRINT */
	
	start_t = clock();
	MergeSort(test, SIZE);
	end_t = clock();
	
	
	#ifdef PRINT
	printf("After MERGE SORT the list is: \n");
	PrintNums(test, SIZE);
	#endif /* PRINT */
	
	printf("The total time of MERGE SORT is %ld\n\n", end_t - start_t);
	
	/************************** QUICK SORT *******************************/
	
	RandomNum(test, SIZE, SEVLOW, SEVUP);
	
	#ifdef PRINT
	printf("The list after randomize before QUICK SORT is: \n");
	PrintNums(test, SIZE);
	#endif /* PRINT */
	
	start_t = clock();
	Qsort(test, SIZE, sizeof(int), CmpFunc);
	end_t = clock();
	
	
	#ifdef PRINT
	printf("After QUICK SORT the list is: \n");
	PrintNums(test, SIZE);
	#endif /* PRINT */
	
	printf("The total time of QUICK SORT is %ld\n\n", end_t - start_t);
	
	
	/********************** BINARY SEARCH ITERATION **************************/
	
	SortedArr(test, SIZE, 1);
	/*#ifdef PRINT
	PrintNums(test, SIZE);
	#endif*/ /* PRINT */
	
	found_index = BinarySearchI(test, SIZE, to_find);
	printf("The found index is (%d): %d\n", to_find - 1, found_index);
	
	to_find = 896;
	found_index = BinarySearchI(test, SIZE, to_find);
	printf("The found index is (%d): %d\n", to_find - 1, found_index);
	
	to_find = 3058;
	found_index = BinarySearchI(test, SIZE, to_find);
	printf("The found index is (%d): %d\n", to_find - 1, found_index);
	
	to_find = 5230;
	found_index = BinarySearchI(test, SIZE, to_find);
	printf("The found index is (%d): %d\n", to_find - 1, found_index);
	
	/********************** BINARY SEARCH RECURSIVE **************************/
	
	to_find = 2;
	found_index = BinarySearchR(test, SIZE, to_find);
	printf("The found index is (%d): %d\n", to_find - 1, found_index);
	
	to_find = 896;
	found_index = BinarySearchR(test, SIZE, to_find);
	printf("The found index is (%d): %d\n", to_find - 1, found_index);
	
	to_find = 3058;
	found_index = BinarySearchR(test, SIZE, to_find);
	printf("The found index is (%d): %d\n", to_find - 1, found_index);
	
	to_find = 5230;
	found_index = BinarySearchR(test, SIZE, to_find);
	printf("The found index is (%d): %d\n", to_find - 1, found_index);
	
/*****************************************************************************/	
	
	return (0);
}

/*****************************************************************************/
/*****************************************************************************/

static void RandomNum(int arr[], size_t size, size_t lower, size_t upper)
{
	size_t i = 0;
	srand(time(0));
	
	for (i = 0; i < size; ++i)
	{
		arr[i] = (rand() % (upper - lower + 1)) + lower;
	}
}

/*****************************************************************************/

static void PrintNums(int arr[], size_t size)
{
	size_t i = 0;
	
	for (i = 0; i < size; ++i)
	{
		printf("%d, ", arr[i]);
	}
	printf("\n\n");
}

/*****************************************************************************/

static int CmpFunc(const void *a, const void *b)
{
	return ( *(int *)a - *(int *)b);
}

static void SortedArr(int arr[], size_t size, size_t lower)
{
	size_t i = 0;
	
	for (i = 0; i < size; ++i)
	{
		arr[i] = lower;
		++lower;
	}
}






