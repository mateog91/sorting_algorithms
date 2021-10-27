#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @array: Array to be sorted
 * @size: Size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, jMin;
	int temp;

	/* Go through list */
	for (i = 0; i < size; i++)
	{
		jMin = i;

		/* Search for the minimum */
		for (j = i + 1; j < size; j++)
		{
			/* store minimun index*/
			if (array[j] < array[jMin])
				jMin = j;
		}
		/* Swap the current index with the minimum */
		if (jMin != i)
		{
			temp = array[jMin];
			array[jMin] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
