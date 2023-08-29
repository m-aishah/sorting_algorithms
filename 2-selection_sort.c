#include "sort.h"

void selection_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	size_t min_index, temp;

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

		temp = array[i];
		array[i] = array[min_index];
		array[min_index] = temp;
	}
}
