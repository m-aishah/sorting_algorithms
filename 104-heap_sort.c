#include "sort.h"

void build_heap(int *array, size_t size);
void heapify(int *array2, size_t size, size_t leaf_index, size_t root_index);

/**
 * swap - Swap two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}


/**
 * heap_sort - Sort an array of integers using the heap sort algorithm.
 *		The integers are sorted in ascending order
 * @array: An array of integers to be sorted.
 * @size: The number of integers in an array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	build_heap(array, size);


	for (i = size - 1; i > 0; i--)
	{
		swap(array, array + i);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}


/**
 * build_heap - Build the heap in array so that the largest value is at the root.
 * @array: The array in question.
 * @size: The number of integers in the array.
 */
void build_heap(int *array, size_t size)
{
	int i;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, size, i);
}


/**
 * heapify - Turn a tree (array of integers) into a heap.
 * @array: Array of integers, the tree.
 * @size: The number of integers in the array/tree.
 * @leaf_index: The index of the integer at the end of the tree.
 * @root_index: The index of the integer at the root of the tree.
 */
void heapify(int *array, size_t size, size_t leaf_index, size_t root_index)
{
	size_t left, right, max;

	left = (2 * root_index) + 1;
	right = (2 * root_index) + 2;
	max = root_index;

	if (left < leaf_index && array[left] > array[max])
		max = left;
	
	if ((right < leaf_index) && (array[right] > array[max]))
		max = right;

	if (max != root_index)
	{
		swap(array + root_index, array + max);
		print_array(array, size);
		heapify(array, size, leaf_index, max);
	}
}
