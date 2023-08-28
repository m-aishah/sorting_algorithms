#include "sort.h"

void top_down_split_merge(int *B, size_t start, size_t end, int *A);
void top_down_merge(int *B, size_t start, size_t middle, size_t end, int *A);

/**
 * merge_sort - Sort an array of integers ina scending order,
 *		using the Merge sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: The number of integers in the array.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;
	size_t i;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	/* Copy array into buffer */
	for (i = 0; i < size; i++)
		buffer[i] = array[i];

	top_down_split_merge(array, 0, size, buffer);
}

/**
 * top_down_split_merge - Sort an array using recursion,
 *				split an array into 2, sort, and merge.
 * @B: Array of integers to sort.
 * @A: Buffer to store the sorted result.
 * @start: Index of the first element of the array.
 * @end: Index of the last element of the array.
 */
void top_down_split_merge(int *B, size_t start, size_t end, int *A)
{
	size_t middle;

	if (end - start < 2)
		return;

	middle = (end + start) / 2;
	top_down_split_merge(A, start, middle, B);
	top_down_split_merge(A, middle, end, B);
	top_down_merge(B, start, middle, end, A);
}

/**
 * top_down_merge - Sort the array and merge it
 *		using the top-down merge sort algorithm.
 * @B: Array of integers to sort.
 * @A: Buffer to store the sorted result.
 * @start: Index of the first element of the array.
 * @middle: Index of the element in the middle of the array.
 * @end: Index of the last element of the array.
 */
void top_down_merge(int *B, size_t start, size_t middle, size_t end, int *A)
{
	size_t i, j, k;

	printf("Merging...\n[left]: ");
	print_array(B + start, middle - start);

	printf("[right]: ");
	print_array(B + middle, end - middle);

	i = start, j = middle;

	for (k = start; k < end; k++)
	{
		if (i >= middle || (j < end && A[i] > A[j]))
		{
			B[k] = A[j];
			j++;
		}
		else
		{
			B[k] = A[i];
			i++;
		}
	}

	printf("[Done]: ");
	print_array(B + start, end - start);
}
