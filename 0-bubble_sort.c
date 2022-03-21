#include <stddef.h>
#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *       using Bublle sort.
 *@array: The array to sort
 *@size: The size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i = 0, j = 0;

	for (i = 0; i < size; i++)
	{
		for (j = 1; j < size; j++)
		{
			if (array[j - 1] > array[j])
			{
				tmp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
}
