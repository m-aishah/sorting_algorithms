#include "sort.h"

void counting_sort_alg(int *array, size_t size, int d, int *buffer);
/**
 * radix_sort - Sort an array of integers inusing the Radix sort algorithm
 *		The integers are arranged in ascending order.
 * @array: Array of integers to be sorted.
 * @size: Number of integers to in the array.
 */
void radix_sort(int *array, size_t size)
{
	int max, d, *buffer;
	size_t i;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}

	for (d = 1; max / d >= 1; d *= 10)
	{
		counting_sort_alg(array, size, d, buffer);
		print_array(array, size);
	}

	free(buffer);
}

/**
 * counting_sort_alg - Sort the place values of array of integers.
 *
 * @array: The array of integers in wquestion.
 * @size: The number of integers in the array.
 * @d: The place value to sort.
 * @buffer: A container to store the sorted array.
 *
 * Description: The sorting is done with the counting sort algorithm.
 */
void counting_sort_alg(int *array, size_t size, int d, int *buffer)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int i;

	for (i = 0; (size_t)i < size; i++)
		count[(array[i] / d) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		buffer[count[(array[i] / d) % 10] - 1] = array[i];
		count[(array[i] / d) % 10]--;
	}

	/* Copy the buffer into array */
	for (i = 0; (size_t)i < size; i++)
		array[i] = buffer[i];
}
