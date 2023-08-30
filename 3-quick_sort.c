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
 * partition - a function to partition an array using the lomuto
 * partition scheme
 *
 * @array: array to be partitioned
 * @size: size of the array
 * @l: left boundary
 * @r: right boundary
 * Return: index where partition occured
 */
int partition(int *array, size_t size, int l, int r)
{
	int i, h;
	int *pivot = array + r;

	for (h = i = l; i < r; i++)
	{
		if (array[i] < *pivot)
		{
			if (h < i)
			{
				swap(array + i, array + h);
				print_array(array, size);
			}
			h++;
		}
	}

	if (array[h] > *pivot)
	{
		swap(array + h, pivot);
		print_array(array, size);
	}

	return (h);
}

/**
 * lomuto_sort - a function that implements the lomuto
 * partition to sort an array
 *
 * @array: array to be sorted
 * @size: size of the array
 * @l: left boundary
 * @r: right boundary
 */
void lomuto_sort(int *array, size_t size, int l, int r)
{
	int section;

	if (r - l > 0)
	{
		section = partition(array, size, l, r);
		lomuto_sort(array, size, l, section - 1);
		lomuto_sort(array, size, section + 1, r);
	}
}

/**
 * quick_sort - a function to sort an array using the quick sort algorithm'
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
