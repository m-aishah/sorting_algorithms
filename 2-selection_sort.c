#include "sort.h"

void swap(int *array, size_t i, size_t j)
{
	size_t temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void selection_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	size_t min_index;

	if(size < 2)
		return;

	for(; i < size - 1; i++)
	{
		min_index = i;
		for(j = i + 1; j < size; j++)
		{
			if(array[j] < array[min_index])
				min_index = j;
		}

		swap(array, i, min_index);
		print_array(array, size);
	}
}
