/*
 * Sorts - Functions Definitions
 */

#include <stdlib.h> /* malloc(), free() */
#include <unistd.h> /* ssize_t */
#include <stdio.h>	/* printf() */

#include "sorts.h"

#define SIZE (5000)


/**************************** UTILITY FUNCTIONS *******************************/

/*
 * Recursive Bin Search: Helpfull function for the binary search
 */
static int RecursiveBinSearch(int arr[], size_t size,
							  size_t index, size_t diff, int search);

/*
 * Split Array and Merge Arrays: Two functions to help the Merge Sort function
 */
static void SplitArray(int *arr, int left, int right);

static void MergeArrays(int *arr, int left, int middle, int right);

/*
 * Pivoting and QuickSort: Two functions to help with the Qsort function
 */
static int Pivoting(int *base, int start, int end,
					int (*compar)(const void *data1, const void *data2));
					 
static void QuickSort(int *base, int start, int end,
					  int (*compar)(const void *data1, const void *data2));


/*
 * Count Sort: Help function for the RADIX sort, it's a count sort adapted for
 *			   the RADIX special demaned (going one digit at a time)
 * Receive:
 * - int arr[] - The array to sort
 * - size_t n - Amount of elements in the array
 * - size_t exp - The digit to go by
 * Time Complexity: O(n)
 */
static void CountSort(int arr[], size_t n, size_t exp);

/*
 * Get Max: Help function for the RADIX sort, that gets the max num in an array
 * Return: int - The max number in an array
 * Receive:
 * - int arr[] - The array to check
 * - size_t size - The the size of the array
 * Time Complexity: O(n)
 */
static int GetMax(int arr[], size_t size);

/*
 * Swap: Swaps two integers
 * Receive:
 * - int * - Pointer to the first integer
 * - int * - Pointer to the second integer
 * Time Complexity: O(1)
 */
static void Swap(int *x, int *y);


/******************************************************************************/
/******************************************************************************/

void BubbleSort(int arr[], size_t size)
{
	size_t i = 0;
	size_t counter = -1;
	
	while (0 != counter)
	{
		i = 0;
		counter = 0;
		for (i = 0; i < size - 1; ++i)
		{
			if (arr[i] > arr[i + 1])
			{
				Swap(&arr[i], &arr[i + 1]);
				++counter;
			}
		}
	}
}

/******************************************************************************/

void SelectionSort(int arr[], size_t size)
{
	size_t i = 0;
	size_t j = 0;
	size_t swap_index = 0;
	int min_value = 0;
	
	for (i = 0; i < size; ++i)
	{
		min_value = arr[i];
		
		for (j = i; j < size; ++j)
		{
			if (min_value > arr[j])
			{
				min_value = arr[j];
				swap_index = j;
			}
		}
		Swap(&arr[i], &arr[swap_index]);
	}	
}

/******************************************************************************/

void InsertionSort(int arr[], size_t size)
{
	size_t i = 0;
	size_t j = 0;
	int temp = 0;
	
	for (i = 1; i < size; ++i)
	{
		if (arr[i] < arr[i - 1])
		{
			j = i;
			while (arr[j] < arr[j - 1] && 0 != j)
			{
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
				--j;
			}
		}
	}
}

/******************************************************************************/

void CountingSort(int arr[], size_t size, size_t range)
{
	size_t i = 0;
	size_t j = 0;
	size_t total_sum = 0;
	int *small_sum = NULL;
	size_t min_count = 0;
	size_t counter = 0;
	
	small_sum = (int *)calloc(range + 1, sizeof(int));
	
	/* Getting the amount of each element and putting it in the right index */
	for (i = 0; i < size; ++i)
	{
		small_sum[arr[i]] += 1;
	}
	
	/* Putting in each element the total sum of all small sums before it */
	for (i = 0; i <= range; ++i)
	{
		total_sum += small_sum[i];
		small_sum[i] = total_sum;
	}
	
	for (i = 0; i <= range; ++i)
	{
		min_count = 0;
		if (0 != small_sum[i])
		{
			j = small_sum[i];
			
			for (j = small_sum[i]; j > counter; --j)
			{
				arr[j - 1] = i;				
				++min_count;
			}
			counter += min_count;
		}
	}
	
	free(small_sum);
	small_sum = NULL;
}

/******************************************************************************/

void RadixSort(int arr[], size_t size)
{
	int digit = 0;
	int max = 0;
	
	max = GetMax(arr, size);
	
	for (digit = 1; max / digit > 0; digit *= 10)
	{
		CountSort(arr, size, digit);
	}
}

/******************************************************************************/

int MergeSort(int *arr_to_sort, size_t num_elements)
{
	SplitArray(arr_to_sort, 0, num_elements - 1);
	
	return (0);
}

/******************************************************************************/

void Qsort(int *base, size_t nmemb, size_t size,
		   int (*compar)(const void *data1, const void *data2))
{
	(void)size;
	
	QuickSort(base, 0, nmemb - 1, compar);
}

/****************************** BINARY SEARCH *********************************/

int BinarySearchI(int arr[], size_t size, int search)
{
	size_t i = size / 2;
	size_t diff = size / 4;
	
	while (0 < i && size > i)
	{
		if (search == arr[i])
		{
			return (i);
		}
		else if (search < arr[i])
		{
			i -= diff;
		}
		else
		{
			i += diff;
		}
		
		diff /= 2;
		if (0 == diff)
		{
			diff = 1;
		}
	}
	
	return (-1);
}

/******************************************************************************/

int BinarySearchR(int arr[], size_t size, int search)
{
	size_t index = size / 2;
	size_t diff = size / 4;

	return (RecursiveBinSearch(arr, size, index, diff, search));
}

static int RecursiveBinSearch(int arr[], size_t size,
							  size_t index, size_t diff, int search)
{
	if (0 >= index || size <= index)
	{
		return (-1);
	}
	else if (search == arr[index])
	{
		return (index);
	}
	else if (search < arr[index])
	{
		if (0 == diff)
		{
			diff = 1;
		}
		return (RecursiveBinSearch(arr, size, index - diff, diff / 2, search));
	}
	else
	{
		if (0 == diff)
		{
			diff = 1;
		}
		return (RecursiveBinSearch(arr, size, index + diff, diff / 2, search));
	} 
}

/*************************** MERGE SORT FUNCTIONS *****************************/

static void SplitArray(int *arr, int left, int right)
{
	int middle = 0;
	
	if (left < right)
	{
		middle = (left + right) / 2;
		
		SplitArray(arr, left, middle);
		SplitArray(arr, middle + 1, right);
		
		MergeArrays(arr, left, middle, right);
	}
}

static void MergeArrays(int *arr, int left, int middle, int right)
{
	int *left_arr = NULL;
	int *right_arr = NULL;
	
	int left_arr_size = middle - left + 1;
	int right_arr_size = right - middle;
	
	int left_arr_index = 0;
	int right_arr_index = 0;
	int merged_arr_index = left;
	
	left_arr = (int *)malloc(sizeof(int) * left_arr_size);
	
	if (!left_arr)
	{
		return;
	}
	
	right_arr = (int *)malloc(sizeof(int) * right_arr_size);
	
	if (!right_arr)
	{
		free (left_arr);
		left_arr = NULL;
		
		return;
	}
	
	
	/* Putting the data from arr into the sub-arrays */
	for (left_arr_index = 0; left_arr_index < left_arr_size; ++left_arr_index)
	{
		left_arr[left_arr_index] = arr[left + left_arr_index];
	}
	
	for (right_arr_index = 0; right_arr_index < right_arr_size; ++right_arr_index)
	{
		right_arr[right_arr_index] = arr[middle + right_arr_index + 1];
	}

	left_arr_index = 0;
	right_arr_index = 0;

	/* Sorting the data from the two sub-arrays into the merged one */
	while (left_arr_index < left_arr_size && right_arr_index < right_arr_size)
	{
		if (left_arr[left_arr_index] <= right_arr[right_arr_index])
		{
			arr[merged_arr_index] = left_arr[left_arr_index];
			++left_arr_index;
		}
		else
		{
			arr[merged_arr_index] = right_arr[right_arr_index];
			++right_arr_index;
		}
		++merged_arr_index;
	}
	
	/* In case there are elements in the left array, putting into the merged */
	while (left_arr_index < left_arr_size)
	{
		arr[merged_arr_index] = left_arr[left_arr_index];
		++left_arr_index;
		++merged_arr_index;
	}
	
	/* In case there are elements in the right array, putting into the merged */
	while (right_arr_index < right_arr_size)
	{
		arr[merged_arr_index] = right_arr[right_arr_index];
		++right_arr_index;
		++merged_arr_index;
	}
	
	free(left_arr);
	left_arr = NULL;
	
	free(right_arr);
	right_arr = NULL;
}

/**************************** QUICK SORT FUNCTIONS ***************************/

static int Pivoting(int *base, int start, int end,
					int (*compar)(const void *data1, const void *data2))
{
	int pivot = base[end];
	int rear_index = start - 1;
	int front_index = 0;
	
	for (front_index = start; front_index <= end - 1; ++front_index)
	{
		if (0 > compar(&base[front_index], &pivot))
		{
			++rear_index;
			if (rear_index != front_index)
			{
				Swap(&base[rear_index], &base[front_index]);
			}
		}
	}
	if (rear_index + 1 != end)
	{
		Swap(&base[rear_index + 1], &base[end]);
	}

	return (rear_index + 1);
}

static void QuickSort(int *base, int start, int end,
					  int (*compar)(const void *data1, const void *data2))
{
	int pivot = 0;
	
	if (start < end)
	{
		pivot = Pivoting(base, start, end, compar);
		
		QuickSort(base, start, pivot - 1, compar);
		QuickSort(base, pivot + 1, end, compar);
	}
}

/******************************************************************************/
/******************************************************************************/

static void CountSort(int arr[], size_t n, size_t exp) 
{
	int output[SIZE];
	size_t i = 0;
	int count[10] = {0};
	
	/* Store amount of elements in count */
	for (i = 0; i < n; ++i)
	{
		++count[(arr[i] / exp) % 10];
	}
	
	/* Changing count[i] so that now it will contain the	*/
	/* actual index of this digit in output[]				*/
	for (i = 1; i < 10; ++i)
	{
		count[i] += count[i - 1];
	}
	
	/* Build the output array */
	for (i = n - 1; ; --i)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		--count[(arr[i] / exp) % 10];
	}
	
	/* Puting the output into arr[] */
	for (i = 0; i < n; ++i)
	{
		arr[i] = output[i];
	}
}

/******************************************************************************/

static int GetMax(int arr[], size_t size)
{
	size_t i = 0;
	int max = 0;
	
	for (i = 0; i < size; ++i)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	
	return (max);
}

/******************************************************************************/

static void Swap(int *x, int *y)
{
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
}

























