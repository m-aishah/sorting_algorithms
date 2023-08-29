#include "sort.h"

void partition(int *array, size_t size, int *boundary_index)
{
	int i;
	int pivot = array[size - 1];

	boundary_index = 0;

	for (i = 0; i < array[size - 2]; i++)
	{
		if (array[i] < pivot)
		{
			swap(&array[i], array[boundary_index]);
			boundary_index++;
		}
	}
	swap(&pivot, &array[boundary_index]);
}

void quick_sort(int *array, size_t size)
{
	size_t min_value;


