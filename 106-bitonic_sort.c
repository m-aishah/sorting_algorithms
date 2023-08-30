#include "sort.h"

void sort_sequence(int *array, size_t size, size_t start, size_t seq_size, int dir);
void create_bitonic_sequence(int *array, size_t size, size_t start, size_t seq_size, int dir);

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
 * bitonic_sort - Sort an array of integers using bitonic sort,
 *			in ascending order.
 * @array: The array of integers to be sorted.
 * @size: The number of integers in the array.
 */
void bitonic_sort(int *array, size_t size) 
{
	if (array == NULL || size < 2)
		return;

	create_bitonic_sequence(array, size, 0, size, 1);
}


/**
 * create_bitonic_sequence - Make a bitonic sequence from an array of integers.
 * @array: The array of integers.
 * @size: The number of integers in the array.
 * @start: The ndex of the integer that starts the bitonic sequence.
 * @seq_size: The size of the bitonic sequence to be built.
 * @dir: The direction that the bitonic sequence is sorted in.
 */
void create_bitonic_sequence(int *array, size_t size, size_t start, size_t seq_size, 
		int dir)
{
	size_t x = seq_size / 2;

	if (seq_size > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq_size, size, 
				(dir == 1)? "UP" : "DOWN");
		print_array(array + start, seq_size);

		create_bitonic_sequence(array, size, start, x, 1);
		create_bitonic_sequence(array, size, start + x, x, 0);
		sort_sequence(array, size, start, seq_size, dir);

		printf("Result [%lu/%lu] (%s):\n", seq_size, size, 
				(dir == 1)? "UP" : "DOWN");
		print_array(array + start, seq_size);
	}
}

/**
 * sort_sequence - Sort a bitonic sequence.
 * @array: The array from which the bitonic sequence was created.
 * @size: The number o fintegers in @array.
 * @start: The starting index of the sequence in the array.
 * @seq_size: The size of the sequence to sort.
 * @dir: Direction the sequence is sorted in.
 */
void sort_sequence(int *array, size_t size, size_t start, size_t seq_size, int dir)
{
	size_t i, y = seq_size / 2;

	if (seq_size > 1)
	{
		for (i = start; i < start + y; i++)
		{
			if ((dir == 1 && array[i] > array[i + y]) ||
					(dir == 0 && array[i] < array[i + y]))
				swap(array + i, array + i + y);
		}

		sort_sequence(array, size, start, y, dir);
		sort_sequence(array, size, start + y, y, dir);
	}
}
