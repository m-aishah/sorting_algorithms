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

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	top_down_split_merge(array, 0, size, buffer);
	free(buffer);
}

/**
 * top_down_split_merge - Sort an array using recursion,
 *				split an array into 2, sort, and merge.
 * @B: Array of integers to sort.
 * @A: Buffer to store the sorted result.
 * @start: Index of the first element of the array.
 * @end: Index of the last element of the array.
 */
void top_down_split_merge(int *A, size_t start, size_t end, int *B)
{
	size_t middle;

	if (end - start < 2)
		return;

	middle = (end + start) / 2;
	top_down_split_merge(A, start, middle, B);
	top_down_split_merge(A, middle, end, B);
	top_down_merge(A, start, middle, end, B);
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
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(B + start, middle - start);

	printf("[right]: ");
	print_array(B + middle, end - middle);

	for (i = start, j = middle; i < middle && j < end; k++)
	{
		if (B[i] < B[j])
			A[k] = B[i++];
		else
			A[k] = B[j++];
	}
	for (; i < middle; i++)
		A[k++] = B[i];
	for (; j < end; j++)
		A[k++] = B[j];
	for (i = start, k = 0; i < end; i++)
		B[i] = A[k++];

	printf("[Done]: ");
	print_array(B + start, end - start);
}
