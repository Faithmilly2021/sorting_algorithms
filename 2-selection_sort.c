#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *     using the ``Selection sort`` algorithm.
 *@array: An array of integers
 *@size: Array size
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *tmp;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		tmp = array + i;

		for (j = i + 1; j < size; j++)
		{
			if (*tmp > *(array + j))
				tmp = array + j;
		}
		if (tmp != array + i)
		{
			swap(array + i, tmp);
			print_array(array, size);
		}
	}
}

/**
 * swap - Swaps the position of two ints in an array
 * @int1: First int
 * @int2: Second int
 */
void swap(int *int1, int *int2)
{
	int tmp;

	tmp = *int1;
	*int1 = *int2;
	*int2 = tmp;
}
