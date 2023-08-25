#include "sort.h"

/**
 * swap - Swap two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Sort array of integers using the Bubble sort algorithm.
 *			The integers are sorted in ascending order.
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, is_sorted = 0, len = size;

	if (array == NULL || size < 2)
		return;

	while (!is_sorted)
	{
		is_sorted = 1;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap((array + i), (array + i + 1));
				/* Print the array after each swap. */
				print_array(array, size);
				is_sorted = 0;
			}
		}
		len--;
	}
}
