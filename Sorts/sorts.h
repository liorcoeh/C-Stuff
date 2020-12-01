/*
 * Implement the following sorting algorithems:
 * Bubble sort
 * Selections sort
 * Insertion sort
 * Quick sort
 * Counting sort
 * Radix sort
 * 
 * Also Implement binary search (iterative and recursive)
 */

#include <stddef.h> /* size_t */

#ifndef SORTS_H
#define SORTS_H

/******************** For the Comparison Sorts Exercise **********************/

/*
 * Bubble Sort: Array sorting function - Comparison sorting
 * Receive:
 * - int arr[] - The array to sort
 * - size_t size - The size of the array
 * Time Complexity: O(n^2)
 */
void BubbleSort(int arr[], size_t size);

/*
 * Selection Sort: Array sorting function - Comparison sorting
 * Receive:
 * - int arr[] - The array to sort
 * - size_t size - The size of the array
 * Time Complexity: O(n^2)
 */
void SelectionSort(int arr[], size_t size);

/*
 * Insertion Sort: Array sorting function - Comparison sorting
 * Receive:
 * - int arr[] - The array to sort
 * - size_t size - The size of the array
 * Time Complexity: O(n^2)
 */
void InsertionSort(int arr[], size_t size);

/*
 * Merge Sort: Sorting an array using the merge sort method
 * Return: 0 for success, 1 for failure
 * Receive:
 * - int * - Pointer to the array to sort
 * - size_t - The number of elements in the array
 * Time Complexity: O(n logn)
 */
int MergeSort(int *arr_to_sort, size_t num_elements);

/*
 * Qsort: Sorting an array using the qsort method
 * Receive:
 * - void * - Pointer to the array to sort
 * - size_t - The amount of elements in the array
 * - size_t - The size of the elements in the array (sizeof)
 * - int * - Pointer to a comparing function which gets two pointers to elements
 *			 and one pointer to a parameter to be used
 * Time Complexity: O(2n)
 */
void Qsort(int *base, size_t nmemb, size_t size,
		   int (*compar)(const void *data1, const void *data2));


/*
 * Binary Search I: Iterative binary search of a sorted array
 * Return: The index the it was found in, -1 if it wasn't found at all
 * Receive:
 * - int arr[] - The array to search in
 * - size_t - The size of the array given
 * - int - The integer to look for in the array
 * Time Complexity: O(log n)
 */
int BinarySearchI(int arr[], size_t size, int search);

/*
 * Binary Search R: Recursive binary search of a sorted array
 * Return: The index the it was found in, -1 if it wasn't found at all
 * Receive:
 * - int arr[] - The array to search in
 * - size_t - The size of the array given
 * - int - The integer to look for in the array
 * Time Complexity: O(log n)
 */
int BinarySearchR(int arr[], size_t size, int search);

/********************** For the Linear Sorts Exercise ************************/

/*
 * Counting Sort: Array sorting function - Non Comparison sorting
 * Receive:
 * - int arr[] - The array to sort
 * - size_t size - The size of the array
 * - size_t range - The range of possible values in the array, the highest one
 * Time Complexity: O(n)
 */
void CountingSort(int arr[], size_t size, size_t range);

/*
 * Radix Sort: Array sorting function - Non Comparison sorting
 * Receive:
 * - int arr[] - The array to sort
 * - size_t size - The size of the array
 * Time Complexity: O(nk)
 */
void RadixSort(int arr[], size_t size);




#endif /* SORTS_H */
