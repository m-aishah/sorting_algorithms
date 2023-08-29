#include "sort.h"

void partition(int *array, size_t size, int *boundary_index)
{
	int i;
	int pivot = array[size - 1];

	*boundary_index = 0;

	for (i = 0; i < size - 1; i++)
	{
		if (array[i] < pivot)
		{
			swap(&array[i], &array[boundary_index]);
			(*boundary_index)++;
		}
	}
	swap(&pivot, &array[*boundary_index]);
}

void quick_sort(int *array, size_t size)
{
	int boundary_index;

	if (size < 2)
		return;

	partition(array, max_value - min_value + 1, &boundary_index);

	quick_sort(array, boundary_index)
}
