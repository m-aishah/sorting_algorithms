#include "sort.h"

/**
 * swap - Swaps the position of two integers.
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
 * shell_sort - Sort an array of integers using the shell sort algorithm.
 *		The integers are sorted in ascending order.
 * @array: The array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i;
	int j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3); gap = gap * 3 + 1)
		;

	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i - gap; j >= 0; j = j - gap)
			{
				if (array[j + gap] >= array[j])
					break;
				swap((array + j), (array + j + gap));
			}
		}
		print_array(array, size);
	}
}
