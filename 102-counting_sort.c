#include "sort.h"

/**
 * find_max_integer - Return the maximum integer in an array of integers.
 * @array: The array in question.
 * @size: The number of integers in the array.
 *
 * Return: The maximum integer in the array
 */
int find_max_integer(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order.
 *			Using the Counting sort algorithm.
 * @array: Pointer to the array of integers to be sorted.
 * @size: Size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output, max;
	size_t i;

	if (array == NULL || size < 2)
		return;

	max = find_max_integer(array, size);

	count = malloc(sizeof(int) * max + 1);
	if (count == NULL)
		return;
	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count);
		return;
	}

	for (i = 0; (int)i < max + 1; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (i = 0; (int)i < max + 1; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
	free(count);
}
