#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 *    using the Quick sort algorithm
 * @array: An array of integers
 * @size: The size of @array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	sort(array, size, 0, size - 1);
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

/**
 * partition - Partitions an array into halves
 *
 * @array: An array of integers
 * @size: Size of subarray
 * @left: Left index
 * @right: Right index
 *
 * Return: partitioned array
 */
int partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	below = left;
	above = below;

	for (; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * sort - Quicksort in recursion
 * @array: An array of integers
 * @size: Size of array
 * @left: Starting index
 * @right: Ending index
 */
void sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = partition(array, size, left, right);
		sort(array, size, left, part - 1);
		sort(array, size, part + 1, right);
	}
}
