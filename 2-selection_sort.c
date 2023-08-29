#include "sort.h"

/**
 * swap - a function to swap 2 elements
 * @array: array whose 2 elemets are to be swapped
 * @i: first element to be swapped
 * @j: second element to be swapped
 */

void swapa(int *array, size_t i, size_t j)
{
	size_t temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/**
 * selection_sort - a functionto sort an array using the selection algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	size_t min_index;

	if (size < 2)
		return;

	for (; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}

		if (i != min_index)
		{
			swapa(array, i, min_index);
			print_array(array, size);
		}
	}
}
