#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using
 *    `Shell sort algorithm`, using the `knuth sequence`
 * @array: An array of integers to sort
 * @size: Size of @array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, forward;

	if (!array || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			forward = i;
			while (forward >= gap && (array[forward - gap] > array[forward]))
			{
				swap(array + forward, array + (forward - gap));
				forward -= gap;
			}
		}
		print_array(array, size);
	}
}

/**
 * swap - Swaps the position of two ints in an array
 * @int1: First int
 * @int2: Second int
 */
void swap(int *int1, int *int2)
{
	int tmp = *int1;
	*int1 = *int2;
	*int2 = tmp;
}
